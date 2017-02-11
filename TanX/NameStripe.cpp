#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "NameStripe.h"



void NameStripe::loadTexture() {
	font.loadFromFile("Extra/nrkis.ttf");
	tex_name_stripe.loadFromFile("Graphics/Single_player/Name_stripe.png");
	s_name_stripe.setTexture(tex_name_stripe);
}

void NameStripe::setLocation() {
	/* Setting location of the name stripe */
	s_name_stripe.setPosition(240, 55);
	s_name_stripe.scale(0.55f, 0.52f);

	/* Setting location of the text on the screen */
	name.setFont(font);
	name.setStyle(sf::Text::Bold);
	name.setColor(sf::Color(235, 225, 225));
	name.setCharacterSize(40);
	name.setPosition(270, 70);

	/* Creating and setting cursor */
	s_cursor = sf::RectangleShape(sf::Vector2f(2, 35));
	s_cursor.setPosition(269, 80);
	s_cursor.setFillColor(sf::Color(200, 200, 200));
}

void NameStripe::handleInput(sf::Event & event, sf::Vector2i mouse_position) {
	sf::Uint32 unicode;
	
	switch (event.type) {
	
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Return:
			cursor = OFF;
			break;
		}
		break;

	case sf::Event::TextEntered:
		if (cursor != OFF) {
			unicode = event.text.unicode;
			if (unicode == 8 && string.size() > 0) {
				string.erase(string.size() - 1, 1);
				name.setString(string);
			}
			else if (name.getGlobalBounds().width < (s_name_stripe.getGlobalBounds().width * 0.8)) { //(unicode == 32 || (unicode >= 48 && unicode <= 57) || (unicode >= 65 && unicode <= 90) || (unicode >= 95 && unicode <= 122)) && 
				string += static_cast<char>(unicode);
				name.setString(string);
			}
			std::cout << string.size() << " | " << s_name_stripe.getGlobalBounds().width - 50 << std::endl;
		}
		break;

	case sf::Event::MouseButtonPressed:
		if (s_name_stripe.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
			cursor = ON_shown;
		else
			cursor = OFF;
		break;

	default:
		break;
	}
}

void NameStripe::update(double dt) {
	time += dt;
	s_cursor.setPosition(272 + name.getGlobalBounds().width, s_cursor.getPosition().y);
	if (time > 500) { //miliseconds
		time = 0;
		if (cursor != OFF)
			cursor = cursor == ON_shown ? ON_hidden : ON_shown;
	}
}

void NameStripe::draw(sf::RenderWindow & window) const {
	window.draw(s_name_stripe);

	if (cursor == ON_shown)
		window.draw(s_cursor);
	
	window.draw(name);
}