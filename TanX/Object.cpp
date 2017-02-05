#include "Object.h"


Object::Object() :
	velocity_(0.0, 0.0) {
	auto rect = getBoundingRect();
	sprite_.setOrigin(rect.width / 2, rect.height / 2);
}

Object::Object(Texture &texture) :
	sprite_(texture), 
	velocity_(0.0, 0.0) {

	auto rect = getBoundingRect();
	sprite_.setOrigin(rect.width / 2, rect.height / 2);
}


void Object::update(float dt) {
	Vector dx = dt * velocity_;
	Vector x = getPosition();
	setPosition(x + dx);
}




