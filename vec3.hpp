/*
	Curtis Fortenberry
	hw6
	cs484
	raytracer.cpp
*/
// Using the guide: Ray Tracing in One Weekend
// https://raytracing.github.io/books/RayTracingInOneWeekend.html
// Somethings may be renamed for consistency/understandability

#ifndef VEC3_HPP_INCLUDED
#define VEC3_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include <cstdlib>

// 4D vector would be more correct but for this purpose 3D vector is adequate
class Vec3 {
	public:
		// Ctor
		Vec3() {}
		Vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
		
		// Position
		inline float x() const { return e[0]; }
		inline float y() const { return e[1]; }
		inline float z() const { return e[2]; }
		
		// Color, same principle as position
		inline float r() const { return e[0]; }
		inline float g() const { return e[1]; }
		inline float b() const { return e[2]; }

		// Unary ops
		inline const Vec3& operator+() const { return *this; }
		inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
		inline float operator[](int i) const { return e[i]; }
		inline float& operator[](int i) { return e[i]; }
		
		// Arithmetic ops
		inline Vec3& operator+=(const Vec3 &v2);
		inline Vec3& operator-=(const Vec3 &v2);
		inline Vec3& operator*=(const Vec3 &v2);
		inline Vec3& operator/=(const Vec3 &v2);
		inline Vec3& operator*=(const float t);
		inline Vec3& operator/=(const float t);

		// Utility funcs
		inline float length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
		inline float squared_length() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
		inline void make_unit_vector();

		// The "vector"
		float e[3];
};

inline std::istream& operator>>(std::istream &is, Vec3 &v) {
    is >> v.e[0] >> v.e[1] >> v.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const Vec3 &v) {
    os << v.e[0] << " " << v.e[1] << " " << v.e[2];
    return os;
}

inline void Vec3::make_unit_vector() {
    float u = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= u; e[1] *= u; e[2] *= u;
}

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator*(float t, const Vec3 &v) {
    return Vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vec3 operator*(const Vec3 &v, float t) {
    return Vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vec3 operator/(Vec3 v, float t) {
    return Vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline float dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.e[0]*v2.e[0]
         + v1.e[1]*v2.e[1]
         + v1.e[2]*v2.e[2];
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
           v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
           v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline Vec3& Vec3::operator+=(const Vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator*=(const Vec3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

inline Vec3& Vec3::operator/=(const Vec3 &v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator/=(const float t) {
    float k = 1.0/t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

#endif //VEC3_HPP_INCLUDED