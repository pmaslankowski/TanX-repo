#include "Sprite.h"


void Sprite::setOrientation(const Vector& v) {
	float alpha = getRotation();

	// scalar to transform from radians to degrees
	const float transformScalar = 180.0f / 3.14159265358979f;

	// cos angle between two vector is equal to their dot product divided by their magnitudes
	float cosDeltaAlpha = (v.x * sin(alpha) + v.y * cos(alpha)) / sqrt(v.x * v.x + v.y * v.y);
	float deltaAlpha = transformScalar * acos(cosDeltaAlpha);

	// we have to check what quater of coordinates system is given vector in
	if (v.x > 0)
		setRotation(alpha + deltaAlpha);
	else
		setRotation(alpha + 360.0f - deltaAlpha);
}

Vector Sprite::getOrientation() const {
	float alpha = getRotation();
	return Vector(cos(alpha), sin(alpha));
}
