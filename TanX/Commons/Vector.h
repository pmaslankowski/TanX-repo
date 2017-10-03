#pragma once
#include <SFML/Graphics.hpp>

#define PI 3.14159265358979


class Vector : public sf::Vector2f { 
public:
	using sf::Vector2f::Vector2f; //inheritance of constructors from vector
	Vector() = default;
	Vector(const sf::Vector2f& other_vector) : sf::Vector2f(other_vector) {};

	Vector rotateRight(const float angle);

	//Vector getOrientation() const;
};
