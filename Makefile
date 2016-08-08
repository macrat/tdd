CFLAGS = -std=c++11
LDFLAGS = 

SRC = $(shell bash -c 'for x in *.cpp; do if [[ $$x != *_test.cpp ]]; then echo $$x; fi; done')

.cpp.o:
	${CXX} ${CFLAGS} -c $^

.PHONY: check
check: $(SRC:%.cpp=%.o) *_test.cpp
	cd googletest/googletest && cmake . && make
	${CXX} ${CFLAGS} ${LDFLAGS} $^ -o test -I./googletest/googletest/include -L./googletest/googletest -lgtest -lgtest_main -lpthread
	./test
	rm test

.PHONY: clean
clean:
	-rm *.o
