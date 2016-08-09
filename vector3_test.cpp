#include "cmath"

#include "gtest/gtest.h"

#include "vector3.h"


using btar::Vector3;


TEST(VectorTest, Round) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(4.4, 5.5).round(), Vector3(4, 6));
	EXPECT_EQ(Vector3(4.499, 5.500).round(), Vector3(4, 6));
}


TEST(VectorTest, Pow) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 2, 3).pow(2), Vector3(1, 2*2, 3*3));
	EXPECT_EQ(Vector3(4, 5, 6).pow(3), Vector3(4*4*4, 5*5*5, 6*6*6));
	EXPECT_EQ(Vector3(1, 2, 3).pow(Vector3(1, 2, 3)), Vector3(1, 2*2, 3*3*3));
}


TEST(VectorTest, Length) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 0, 0).length(), 1.0);
	EXPECT_EQ(Vector3(0, 1, 0).length(), 1.0);
	EXPECT_EQ(Vector3(0, 0, 1).length(), 1.0);
	EXPECT_EQ(Vector3(1, 1, 1).length(), std::sqrt(1.0*3));
}


TEST(VectorTest, Distance) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(0, 0, 0).distance(Vector3(2, 3, 4)), Vector3(2, 3, 4).length());
	EXPECT_EQ(Vector3(1,2,3).distance(Vector3(1, 2, 3) + Vector3(4, 5, 6)), Vector3(4,5,6).length());
}


TEST(VectorTest, Median) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 2, 3).median(Vector3(4, 5, 6)), Vector3((1+4)/2.0, (2+5)/2.0, (3+6)/2.0));
}


TEST(VectorTest, Abs) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(-1, 2, 3).abs(), Vector3(1, 2, 3));
	EXPECT_EQ(Vector3(1, 2, -3).abs(), Vector3(1, 2, 3));
}


TEST(VectorTest, Normalize) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(0, 1, 2).normalize(), Vector3(0, 0.5, 1.0));
	EXPECT_EQ(Vector3(4, 3, 1).normalize(), Vector3(1.0, 0.75, 0.25));
	EXPECT_EQ(Vector3(-0, -1, -2).normalize(), Vector3(-0, -0.5, -1.0));
	EXPECT_EQ(Vector3(-4, -3, -1).normalize(), Vector3(-1.0, -0.75, -0.25));
}


TEST(VectorTest, ToString) {
	EXPECT_EQ((std::string)Vector3(1, 2, 3), "[1 2 3]");
	EXPECT_EQ((std::string)Vector3(9, 7, 5), "[9 7 5]");
}


TEST(VectorTest, Add) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 2, 3) + Vector3(4, 5, 6), Vector3(1.0+4.0, 2.0+5.0, 3.0+6.0));
	EXPECT_EQ(Vector3(1, 2, 3) += Vector3(4, 5, 6), Vector3(1.0+4.0, 2.0+5.0, 3.0+6.0));

	EXPECT_EQ(Vector3(1, 2, 3) + 2, Vector3(1.0+2.0, 2.0+2.0, 3.0+2.0));
	EXPECT_EQ(Vector3(1, 2, 3) += 2, Vector3(1.0+2.0, 2.0+2.0, 3.0+2.0));
}


TEST(VectorTest, Sub) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 2, 3) - Vector3(4, 5, 6), Vector3(1.0-4.0, 2.0-5.0, 3.0-6.0));
	EXPECT_EQ(Vector3(1, 2, 3) -= Vector3(4, 5, 6), Vector3(1.0-4.0, 2.0-5.0, 3.0-6.0));

	EXPECT_EQ(Vector3(1, 2, 3) - 2, Vector3(1.0-2.0, 2.0-2.0, 3.0-2.0));
	EXPECT_EQ(Vector3(1, 2, 3) -= 2, Vector3(1.0-2.0, 2.0-2.0, 3.0-2.0));
}


TEST(VectorTest, Mul) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 2, 3) * Vector3(4, 5, 6), Vector3(1.0*4.0, 2.0*5.0, 3.0*6.0));
	EXPECT_EQ(Vector3(1, 2, 3) *= Vector3(4, 5, 6), Vector3(1.0*4.0, 2.0*5.0, 3.0*6.0));

	EXPECT_EQ(Vector3(1, 2, 3) * 2, Vector3(1.0*2.0, 2.0*2.0, 3.0*2.0));
	EXPECT_EQ(Vector3(1, 2, 3) *= 2, Vector3(1.0*2.0, 2.0*2.0, 3.0*2.0));
}


TEST(VectorTest, Div) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(1, 2, 3) / Vector3(4, 5, 6), Vector3(1.0/4.0, 2.0/5.0, 3.0/6.0));
	EXPECT_EQ(Vector3(1, 2, 3) /= Vector3(4, 5, 6), Vector3(1.0/4.0, 2.0/5.0, 3.0/6.0));

	EXPECT_EQ(Vector3(1, 2, 3) / 2, Vector3(1.0/2.0, 2.0/2.0, 3.0/2.0));
	EXPECT_EQ(Vector3(1, 2, 3) /= 2, Vector3(1.0/2.0, 2.0/2.0, 3.0/2.0));
}


TEST(VectorTest, Mod) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(Vector3(5, 6, 7) % Vector3(2, 3, 4), Vector3(5%2, 6%3, 7%4));
	EXPECT_EQ(Vector3(5, 6, 7) %= Vector3(2, 3, 4), Vector3(5%2, 6%3, 7%4));

	EXPECT_EQ(Vector3(5, 6, 7) % 4, Vector3(5%4, 6%4, 7%4));
	EXPECT_EQ(Vector3(5, 6, 7) %= 4, Vector3(5%4, 6%4, 7%4));
}


TEST(VectorTest, Assign) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	Vector3 a = {1, 2, 3};
	EXPECT_EQ(a, Vector3(1, 2, 3));

	a = Vector3(2, 3, 4);
	EXPECT_EQ(a, Vector3(2, 3, 4));
}


TEST(VectorTest, SingleOperation) {
	ASSERT_EQ(Vector3(1, 2, 3), Vector3(1, 2, 3));
	ASSERT_NE(Vector3(1, 2, 3), Vector3(4, 5, 6));

	EXPECT_EQ(+Vector3(1, 2, 3), Vector3(1, 2, 3));
	EXPECT_EQ(-Vector3(1, 2, 3), Vector3(-1, -2, -3));
}
