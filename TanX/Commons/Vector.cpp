#include "Vector.h"
#include <iostream>


Vector Vector::rotateRight(const float angle) {
	float alpha = angle*PI / 180;
	std::cout << "Alpha: " << alpha << " \n";
	float x_prim = x*cos(alpha) - y*sin(alpha);
	float y_prim = x*sin(alpha) + y*cos(alpha);
	x = x_prim;
	y = y_prim;
	return *this;
}

//Vector Vector::getOrientation() const {
//	float alpha = getRotation()*PI / 180;
//	return Vector(sin(alpha), -cos(alpha));
//}
