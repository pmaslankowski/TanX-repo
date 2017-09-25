#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "TextureManager.h"


using Vector = sf::Vector2f;
using Window = sf::RenderWindow;
using Rectangle = sf::FloatRect;
using Texture = sf::Texture;

class Object {
public:
	Object();
	Object(float x, float y, float width, float height, float priority) 
		: width_(width), height_(height), priority_(priority) { sprite_.setPosition(x, y); }
	explicit Object(Texture& texture);

	virtual ~Object() {}

	Vector getPosition() const { return sprite_.getPosition(); }
	Vector getOrientation() const { return sprite_.getOrientation(); }
	Vector getVelocity() const { return velocity_; }
	Rectangle getBoundingRect() const { return sprite_.getGlobalBounds(); }
	Sprite& getSprite() { return sprite_; }
	float getVelocityX() const { return velocity_.x; }
	float getVelocityY() const { return velocity_.y; }
	float getHeight() const { return height_; }
	float getWidth() const { return width_; }
	float getPriority() const { return priority_; }
	void setPosition(const Vector& position) { sprite_.setPosition(position); }
	void setOrientation(const Vector& orientation) { sprite_.setOrientation(orientation); }
	void setWidth(float width_) { width_ = width_; }
	void setHeight(float height_) { height_ = height_; }
	void setVelocity(const Vector& velocity) { velocity_ = velocity; }
	void setVelocityX(float x) { velocity_.x = x; }
	void setVelocityY(float y) { velocity_.y = y; }
	void setPriority(float priority_) { priority_ = priority_; }
	void scaleTexture();

	virtual void loadSprite(TextureManager& textureManager) {} // remember to invoke scaleTexture in this function
	virtual void update(float dt);
	virtual void draw(Window &window) const { window.draw(sprite_); }
	
	std::string id;
protected:
	Sprite sprite_;
	float width_, height_;
	float priority_;
	Vector velocity_;
};

using iVector = sf::Vector2i;
using fVector = sf::Vector2f;