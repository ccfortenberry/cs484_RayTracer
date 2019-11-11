/*
	Curtis Fortenberry
	hw6
	cs484
	raytracer.cpp
*/
// Following the guide: Ray Tracing in One Weekend
// https://raytracing.github.io/books/RayTracingInOneWeekend.html

#include "vec3.hpp"
#include "ray.hpp"
#include <fstream>
#include <iostream>

Vec3 color(const Ray &r) {
	Vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Vec3(1.0, 1.0, 1.0) + t*Vec3(0.5, 0.7, 1.0);
}

void testPPM(std::ofstream &ofs) {
	int nx = 200;
    int ny = 100;
    ofs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny-1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            Vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            ofs << ir << " " << ig << " " << ib << "\n";
        }
    }
}

void testRay(std::ofstream &ofs) {
	int nx = 200;
	int ny = 100;
	ofs << "P3\n" << nx << " " << ny << "\n255\n";
	Vec3 lower_left_corner(-2.0, -1.0, -1.0);
	Vec3 horizontal(4.0, 0.0, 0.0);
	Vec3 vertical(0.0, 2.0, 0.0);
	Vec3 origin(0.0, 0.0, 0.0);
	for (int j = ny-1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			Vec3 col = color(r);
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			ofs << ir << " " << ig << " " << ib << "\n";
		}
	}
}

int main() {
    std::ofstream outPPM;
	outPPM.open("testppm.ppm", std::ios::out | std::ios::trunc);
	if (outPPM.is_open()) {
		testPPM(outPPM);
		outPPM.close();
	}
	else {
		std::cout << "Failure opening PPM file for writing image!" << std::endl;
	}
	
	std::ofstream outRay;
	outRay.open("testray.ppm", std::ios::out | std::ios::trunc);
	if (outRay.is_open()) {
		testRay(outRay);
		outRay.close();
	}
	else {
		std::cout << "Failure opening PPM file for writing image!" << std::endl;
	}
}