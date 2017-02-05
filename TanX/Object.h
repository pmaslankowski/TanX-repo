#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Sprite.h"


using Vector = sf::Vector2f;
using Window = sf::RenderWindow;
using Rectangle = sf::FloatRect;
using Texture = sf::Texture;

class Object {
public:
	Object();
	Object(Texture& texture);
	virtual ~Object() {}

	Vector getPosition() const { return sprite_.getPosition(); }
	Vector getOrientation() const { return sprite_.getOrientation(); }
	Vector getVelocity() const { return velocity_; }
	Rectangle getBoundingRect() const { return sprite_.getGlobalBounds(); }
	Sprite& getSprite() { return sprite_; }
	void setPosition(const Vector& position) { sprite_.setPosition(position); }
	void setOrientation(const Vector& orientation) { sprite_.setOrientation(orientation); }
	void setVelocity(const Vector& velocity) { velocity_ = velocity; }
	void setTexture(const Texture texture) { sprite_.setTexture(texture); }

	virtual void update(float dt);
	virtual void draw(Window &window) const { window.draw(sprite_); }
	
	std::string id;
protected:
	Sprite sprite_;
	Vector velocity_;
};

using iVector = sf::Vector2i;

using fVector = sf::Vector2f;