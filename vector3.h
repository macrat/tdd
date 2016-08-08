#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include <cmath>
#include <iostream>
#include <string>

#include <boost/cast.hpp>
#include <boost/format.hpp>


namespace btar {


class Vector3 {
private:
	double x, y, z;

public:
	Vector3(double x, double y, double z=0) : x(x), y(y), z(z) {}

	Vector3 pow(const Vector3& v) const;
	Vector3 pow(const double& v) const;

	double length() const;
	double distance(const Vector3& v) const;

	Vector3 median(const Vector3& v) const;

	Vector3 round() const;
	Vector3 abs() const;
	Vector3 normalize() const;

	operator std::string() const;

	Vector3& operator =(const Vector3& v);

	bool operator ==(const Vector3& v) const;
	bool operator !=(const Vector3& v) const;

	Vector3 operator +() const;
	Vector3 operator -() const;

	Vector3 operator +(const Vector3& v) const;
	Vector3& operator +=(const Vector3& v);
	Vector3 operator +(const double& v) const;
	Vector3& operator +=(const double& v);

	Vector3 operator -(const Vector3& v) const;
	Vector3& operator -=(const Vector3& v);
	Vector3 operator -(const double& v) const;
	Vector3& operator -=(const double& v);


	Vector3 operator *(const Vector3& v) const;
	Vector3& operator *=(const Vector3& v);
	Vector3 operator *(const double& v) const;
	Vector3& operator *=(const double& v);

	Vector3 operator /(const Vector3& v) const;
	Vector3& operator /=(const Vector3& v);
	Vector3 operator /(const double& v) const;
	Vector3& operator /=(const double& v);

	Vector3 operator %(const Vector3& v) const;
	Vector3& operator %=(const Vector3& v);
	Vector3 operator %(const int& v) const;
	Vector3& operator %=(const int& v);
};


}


#endif
