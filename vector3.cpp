#include "vector3.h"

#include <boost/format.hpp>
#include <cmath>
#include <iostream>


namespace btar {


Vector3 Vector3::pow(const Vector3& v) const {
	return {std::pow(x, v.x), std::pow(y, v.y), std::pow(z, v.z)};
}


Vector3 Vector3::pow(const double& v) const {
	return {std::pow(x, v), std::pow(y, v), std::pow(z, v)};
}


double Vector3::length() const {
	Vector3 p{pow(2)};
	return std::sqrt(p.x + p.y + p.z);
}


double Vector3::distance(const Vector3& v) const {
	Vector3 p{(*this - v).pow(2)};
	return std::sqrt(p.x + p.y + p.z);
}


Vector3 Vector3::median(const Vector3& v) const {
	return (*this + v) / 2.0;
}


Vector3 Vector3::round() const {
	return {std::round(x), std::round(y), std::round(z)};
}


Vector3 Vector3::abs() const {
	return {std::abs(x), std::abs(y), std::abs(z)};
}


Vector3 Vector3::normalize() const {
	const double max = std::max(std::max(abs().x, abs().y), abs().z);
	return {x / max, y / max, z / max};
}


Vector3::operator std::string() const {
	return (boost::format("[%1% %2% %3%]") % x % y % z).str();
}


Vector3& Vector3::operator =(const Vector3& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}


bool Vector3::operator ==(const Vector3& v) const {
	return x == v.x && y == v.y && z == v.z;
}


bool Vector3::operator !=(const Vector3& v) const {
	return !(*this == v);
}


Vector3 Vector3::operator +() const {
	return {x, y, z};
}


Vector3 Vector3::operator -() const {
	return {-x, -y, -z};
}


Vector3 Vector3::operator +(const Vector3& v) const {
	return {x + v.x, y + v.y, z + v.z};
}


Vector3& Vector3::operator +=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}


Vector3 Vector3::operator +(const double& v) const {
	return {x + v, y + v, z + v};
}


Vector3& Vector3::operator +=(const double& v) {
	x += v;
	y += v;
	z += v;
	return *this;
}


Vector3 Vector3::operator -(const Vector3& v) const {
	return {x - v.x, y - v.y, z - v.z};
}


Vector3& Vector3::operator -=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}


Vector3 Vector3::operator -(const double& v) const {
	return {x - v, y - v, z - v};
}


Vector3& Vector3::operator -=(const double& v) {
	x -= v;
	y -= v;
	z -= v;
	return *this;
}


Vector3 Vector3::operator *(const Vector3& v) const {
	return {x * v.x, y * v.y, z * v.z};
}


Vector3& Vector3::operator *=(const Vector3& v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}


Vector3 Vector3::operator *(const double& v) const {
	return {x * v, y * v, z * v};
}


Vector3& Vector3::operator *=(const double& v) {
	x *= v;
	y *= v;
	z *= v;
	return *this;
}


Vector3 Vector3::operator /(const Vector3& v) const {
	return {x / v.x, y / v.y, z / v.z};
}


Vector3& Vector3::operator /=(const Vector3& v) {
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}


Vector3 Vector3::operator /(const double& v) const {
	return {x / v, y / v, z / v};
}


Vector3& Vector3::operator /=(const double& v) {
	x /= v;
	y /= v;
	z /= v;
	return *this;
}


Vector3 Vector3::operator %(const Vector3& v) const {
	Vector3 a{round()}, b{v.round()};
	return {
		static_cast<double>(static_cast<int64_t>(a.x) % static_cast<int64_t>(b.x)),
		static_cast<double>(static_cast<int64_t>(a.y) % static_cast<int64_t>(b.y)),
		static_cast<double>(static_cast<int64_t>(a.z) % static_cast<int64_t>(b.z))
	};
}


Vector3& Vector3::operator %=(const Vector3& v) {
	Vector3 a{round()}, b{v.round()};
	x = static_cast<int64_t>(a.x) % static_cast<int64_t>(b.x);
	y = static_cast<int64_t>(a.y) % static_cast<int64_t>(b.y);
	z = static_cast<int64_t>(a.z) % static_cast<int64_t>(b.z);
	return *this;
}


Vector3 Vector3::operator %(const int& v) const {
	Vector3 a{round()};
	return {
		static_cast<double>(static_cast<int64_t>(a.x) % v),
		static_cast<double>(static_cast<int64_t>(a.y) % v),
		static_cast<double>(static_cast<int64_t>(a.z) % v)
	};
}


Vector3& Vector3::operator %=(const int& v) {
	Vector3 a{round()};
	x = static_cast<int64_t>(a.x) % v;
	y = static_cast<int64_t>(a.y) % v;
	z = static_cast<int64_t>(a.z) % v;
	return *this;
}


std::ostream& operator <<(std::ostream& os, const Vector3& v) {
	return os << (std::string)v;
}


}
