/*
	Curtis Fortenberry
	hw6
	cs484
	raytracer.cpp
*/
// Using the guide: Ray Tracing in One Weekend
// https://raytracing.github.io/books/RayTracingInOneWeekend.html
// Somethings may be renamed for consistency/understandability

#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED

#include "vec3.hpp"

class Ray {
	public:
		// Ctors
		Ray() {}
        Ray(const Vec3& o, const Vec3& d) { org = o; dir = d; }
        
		// Utility funcs
		Vec3 origin() const { return org; }
        Vec3 direction() const { return dir; }
        Vec3 point(float t) const { return org + t*dir; }

		// Data members
        Vec3 org;
        Vec3 dir;
};

#endif //RAY_HPP_INCLUDED