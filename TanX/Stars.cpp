#include <iostream>
#include "Stars.h"
#include "TextureManager.h"

Stars::Stars() : levels(3) {}

void Stars::loadTexture(TextureManager& textureManager) {
	Texture tex_star;
	tex_star = textureManager.getTexture("Single_player\\Star_gray.png"); //GRAY on position 0
	tex_vector.push_back(tex_star);
	tex_star = textureManager.getTexture("Single_player\\Star_yellow.png"); //YELLOW on position 1
	tex_vector.push_back(tex_star);

	star_vector.push_back(Object(tex_vector.at(1))); //yellow
	for (int i = 0; i < levels - 1; i++)
		star_vector.push_back(Object(tex_vector.at(0))); //gray

}

void Stars::setLocation() {
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

void Stars::setStarsInVector(std::vector<Object>& vector, int i) { //change needed if more levels
	switch (i) {
	case 0:
		setColor(vector, 1, "gray");
		setColor(vector, 2, "gray");
		break;
	case 1:
		setColor(vector, 1, "yellow");
		setColor(vector, 2, "gray");
		break;
	case 2:
		setColor(vector, 1, "yellow");
		setColor(vector, 2, "yellow");
		break;
	default:
		break;
	}
}


void Stars::handleInput(sf::Event & event, sf::Vector2i mouse_position) {
	switch (event.type) {
	case sf::Event::MouseMoved:
		for (int i = 0; i < levels; i++) {
			star_vector.at(i).id = "OFF";
			if (star_vector.at(i).getSprite().getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
				star_vector.at(i).id = "ON";
				setStarsInVector(temp_star_vector, i);
			}
		}
		break;

	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < levels; i++)
			if (star_vector.at(i).id == "ON")
				setStarsInVector(star_vector, i);
		break;

	default:
		break;
	}
}

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
