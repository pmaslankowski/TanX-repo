#include <string>

#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <PlayingState/ObjectFactory.h>

#include "Tank.h"


const float Tank::VELOCITY_SCALE = 10;



void Tank::loadSprite(TextureManager& texture_manager) {
	switch (type) {
	case Type::TankRed:
		sprite_.setTexture(texture_manager.getTexture("Tank_red.png"));
		break;
	case Type::TankGreen:
		sprite_.setTexture(texture_manager.getTexture("Tank_green.png"));
		break;
	case Type::TankBlue:
		sprite_.setTexture(texture_manager.getTexture("Tank_blue.png"));
		break;
	case Type::TankYellow:
		sprite_.setTexture(texture_manager.getTexture("Tank_yellow.png"));
		break;
	case Type::TankPink:
		sprite_.setTexture(texture_manager.getTexture("Tank_pink.png"));
		break;
	case Type::TankOrange:
		sprite_.setTexture(texture_manager.getTexture("Tank_orange.png"));
		break;
	}
	scaleTexture();
	setDefaultOrigin();
}

void Tank::setDefaultOrigin() {
	const auto& rect = sprite_.getTextureRect();
	Vector center_point(rect.width * 0.5, rect.height * 0.53);
	sprite_.setOrigin(center_point);
}




REGISTER_OBJECT(Tank, "TankRed");
REGISTER_OBJECT_WITH_LAMBDA(Tank, "TankGreen", [](float x, float y, float width, float height, float priority) -> Object* {
	return new Tank(x, y, width, height, priority, Tank::Type::TankGreen);
});


