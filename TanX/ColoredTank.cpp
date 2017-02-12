#include "ColoredTank.h"


ColoredTank::ColoredTank() {
	colors = { "red", "yellow", "green", "pink", "blue", "orange" };
}

void ColoredTank::loadTexture() {
	Texture tex_color;
	Texture tex_tank;
	for (int i = 0; i < colors.size(); i++) {
		tex_color.loadFromFile("Graphics/Single_player/Color_" + colors.at(i) + ".png"); //loading color textures
		tex_vector.push_back(tex_color);
		tex_tank.loadFromFile("Graphics/Single_player/Color_tank_" + colors.at(i) + ".png"); //loading tank textures
		tex_vector.push_back(tex_tank);
	}	
}

void ColoredTank::setLocation() {
	/* Setting position of all colors and temporary tanks */
	for (int i = 0; i < colors.size(); i++) { 
		Sprite s_color;
		s_color.setTexture(tex_vector.at(2*i));
		s_color.scale(0.65f, 0.65f);
		s_color.setOrigin(49, 51);
		s_color.setPosition(110 + (i % 3) * 80, 300 + (i / 3 * 85));
		color_vector.push_back(s_color);
		
		Sprite s_tank;
		s_tank.setTexture(tex_vector.at(2*i+1));
		s_tank.scale(0.23f, 0.23f);
		s_tank.setPosition(350, 180);
		temp_tank_vector.push_back(s_tank);
	}

	/* Setting color and position of the default tank  */
	default_tank.setTexture(tex_vector.at(1)); 
	default_tank.scale(0.23f, 0.23f);
	default_tank.setPosition(350, 180);
}

void ColoredTank::handleInput(sf::Event & event, sf::Vector2i mouse_position) {
	switch (event.type) {
	case sf::Event::MouseMoved:
		mouse_on_color = -1;
		for (int i = 0; i < colors.size(); i++)
			if (color_vector.at(i).getGlobalBounds().contains(mouse_position.x, mouse_position.y))
				mouse_on_color = i;
		break;

	case sf::Event::MouseButtonPressed:
		if (mouse_on_color >= 0) //changing tank color
			default_tank = temp_tank_vector.at(mouse_on_color);
		break;

	default:
		break;
	}
}

void ColoredTank::draw(sf::RenderWindow & window) const {
	for (int i = 0; i < colors.size(); i++)
		window.draw(color_vector.at(i));
	window.draw(default_tank);

	if (mouse_on_color >= 0)
		window.draw(temp_tank_vector.at(mouse_on_color));
}

