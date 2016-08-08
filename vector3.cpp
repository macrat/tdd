#include "vector3.h"


namespace btar {


Vector3 Vector3::pow(const Vector3& v) const {
	return {std::pow(x, v.x), std::pow(y, v.y), std::pow(z, v.z)};
}


Vector3 Vector3::pow(const double& v) const {
	return {std::pow(x, v), std::pow(y, v), std::pow(z, v)};
}


double Vector3::length() const {
	auto p = pow(2);
	return std::sqrt(p.x + p.y + p.z);
}


double Vector3::distance(const Vector3& v) const {
	auto p = (*this - v).pow(2);
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
	return Vector3(x * v, y * v, z * v);
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
	auto a = round();
	auto b = v.round();
	return {
		boost::numeric_cast<int64_t>(a.x) % boost::numeric_cast<int64_t>(b.x),
		boost::numeric_cast<int64_t>(a.y) % boost::numeric_cast<int64_t>(b.y),
		boost::numeric_cast<int64_t>(a.z) % boost::numeric_cast<int64_t>(b.z)
	};
}


Vector3& Vector3::operator %=(const Vector3& v) {
	auto a = round();
	auto b = v.round();
	x = boost::numeric_cast<int64_t>(a.x) % boost::numeric_cast<int64_t>(b.x);
	y = boost::numeric_cast<int64_t>(a.y) % boost::numeric_cast<int64_t>(b.y);
	z = boost::numeric_cast<int64_t>(a.z) % boost::numeric_cast<int64_t>(b.z);
	return *this;
}


Vector3 Vector3::operator %(const int& v) const {
	auto a = round();
	return {
		boost::numeric_cast<int64_t>(a.x) % v,
		boost::numeric_cast<int64_t>(a.y) % v,
		boost::numeric_cast<int64_t>(a.z) % v
	};
}


Vector3& Vector3::operator %=(const int& v) {
	auto a = round();
	x = boost::numeric_cast<int64_t>(a.x) % v;
	y = boost::numeric_cast<int64_t>(a.y) % v;
	z = boost::numeric_cast<int64_t>(a.z) % v;
	return *this;
}


std::ostream& operator <<(std::ostream& os, const Vector3& v) {
	return os << (std::string)v;
}


}
