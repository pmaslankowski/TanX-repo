#include "Stripe.h"

Stripe::Stripe(std::string color, std::string length) : color(color), length(length) {}

void Stripe::loadTexture() {
	std::string path = "Graphics/Main_menu/Stripe_" + length + "_" + color + ".png";
	if (!texture.loadFromFile(path))
		std::invalid_argument("Can't load the texture");
	sprite_.setTexture(texture);
}

void Stripe::setLocation() {
	int window_height = 720; //setting window height to work stripes placement on the screen out
	int height_unit = window_height / 72; //setting unit used to calculate proportions
	getSprite().scale(0.65f, 0.65f); //calibrating the size of the stripe, to the hight of around 105

	//setting the stripes on the screen depending on their color/type; assuming their origin is in the upper left corner of the sprite
	if (color == "sp")
		getSprite().setPosition(0, height_unit*7); 
	else if (color == "m")
		getSprite().setPosition(0, height_unit * 19); //gap between each stripe is 12 units = 120 
	else if (color == "e")
		getSprite().setPosition(0, height_unit * 31);
	else if (color == "s")
		getSprite().setPosition(0, height_unit * 43);
	else
		getSprite().setPosition(0, height_unit * 55);

}

