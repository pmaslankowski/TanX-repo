#include <iostream>
#include "Stars.h"


Stars::Stars() : levels(3) {}

void Stars::loadTexture() {
	Texture tex_star;
	tex_star.loadFromFile("Graphics/Single_player/Star_gray.png"); //GRAY on position 0
	tex_vector.push_back(tex_star);
	tex_star.loadFromFile("Graphics/Single_player/Star_yellow.png"); //YELLOW on position 1
	tex_vector.push_back(tex_star);
}

void Stars::setLocation() {
	star_vector.push_back(Object(tex_vector.at(1))); //yellow
	star_vector.push_back(Object(tex_vector.at(0))); //gray
	star_vector.push_back(Object(tex_vector.at(0))); //gray

	for (int i=0; i<levels; i++) {
		star_vector.at(i).id = "OFF"; //is mouse ON or OFF that star at the moment	
		star_vector.at(i).setPosition(sf::Vector2f(250 + i*85, 550));		
		temp_star_vector.push_back(star_vector.at(i));
	}
}

void Stars::setColor(std::vector<Object> &vector, int i, std::string color) {
	if (color == "gray")
		vector.at(i).getSprite().setTexture(tex_vector.at(0));
	else if (color == "yellow")
		vector.at(i).getSprite().setTexture(tex_vector.at(1));
}

void Stars::handleInput(sf::Event & event, sf::Vector2i mouse_position) {
	switch (event.type) {
	case sf::Event::MouseMoved:
		for (int i = 0; i < levels; i++) {
			star_vector.at(i).id = "OFF";
			if (star_vector.at(i).getSprite().getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
				star_vector.at(i).id = "ON";
				switch (i) {
				case 0:
					setColor(temp_star_vector, 1, "gray");
					setColor(temp_star_vector, 2, "gray");
					break;
				case 1:
					setColor(temp_star_vector, 1, "yellow");
					setColor(temp_star_vector, 2, "gray");
					break;
				case 2:
					setColor(temp_star_vector, 1, "yellow");
					setColor(temp_star_vector, 2, "yellow");
					break;
				default:
					break;
				}
			}
		}
		break;

	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < levels; i++)
			if (star_vector.at(i).id == "ON")
				switch (i) {
				case 0:
					setColor(star_vector, 1, "gray");
					setColor(star_vector, 2, "gray");
					break;
				case 1:
					setColor(star_vector, 1, "yellow");
					setColor(star_vector, 2, "gray");
					break;
				case 2:
					setColor(star_vector, 1, "yellow");
					setColor(star_vector, 2, "yellow");
					break;
				default:
					break;
				}
		break;

	default:
		break;
	}
}

void Stars::update(double dt) {}

void Stars::draw(sf::RenderWindow & window) const {
	bool is_mouse_on_star = false;

	for (int i = 0; i < levels; i++) {
		star_vector.at(i).draw(window);
		if (star_vector.at(i).id == "ON")
			is_mouse_on_star = true;
	}
	if (is_mouse_on_star)
		for (int i = 0; i < levels; i++)
			temp_star_vector.at(i).draw(window);	
}
