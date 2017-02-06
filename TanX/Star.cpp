#include "Star.h"


Star::Star(std::string color, int nr) : color(color), number(nr) {}

void Star::loadTexture() {
	std::string path = "Graphics/Single_player/Star_" + color + ".png";
	if (!texture.loadFromFile(path))
		std::invalid_argument("Can't load the texture");
	sprite_.setTexture(texture);
}

void Star::setLocation() {
	switch (number) {
	case 0:
		sprite_.setPosition(215, 515);
		break;
	case 1:
		sprite_.setPosition(300, 515);
		break;
	case 2:
		sprite_.setPosition(385, 515);
		break;
	}
}

void Star::setColor(std::string color) {
	std::string path = "Graphics/Single_player/Star_" + color + ".png";
	if (!texture.loadFromFile(path))
		std::invalid_argument("Can't load the texture");
	sprite_.setTexture(texture);
}
