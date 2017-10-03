#pragma once
#include <SFML/Graphics.hpp>
#include "Vector.h"

#define MY_PI 3.14159265358979

//using Vector = sf::Vector2f;

class Sprite : public sf::Sprite {
public:
	using sf::Sprite::Sprite; //inheritance of constructors from sprite
	
	// function sets sprite along given vector v
	void setOrientation(const Vector& v);
	void setOrientation(const float angle);
	// function returns unit vector. Sprite is set along this vector.
	Vector getOrientation() const;
};
