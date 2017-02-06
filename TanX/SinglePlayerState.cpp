#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SinglePlayerState.h"
#include "PlayingState.h"
#include "Star.h"


void SinglePlayerState::loadSprites() {
	colors = { "red", "yellow", "green", "pink", "blue", "orange" };
	
	/* Loading all textures to tex_vector */
	for (int i = 0; i < 3 + 2*colors.size(); i++) { //loading background, logo and logo_red, all colors and colored tanks
		Texture tex;
		if (i == 0)
			tex.loadFromFile("Graphics/Single_player/Background.png");
		else if (i == 1)
			tex.loadFromFile("Graphics/Single_player/Logo.png");
		else if (2 <= i && i < 8) 
			tex.loadFromFile("Graphics/Single_player/Color_" + colors[i-2] + ".png");
		else if (8 <= i && i < 14) 
			tex.loadFromFile("Graphics/Single_player/Color_tank_" + colors[i-8] + ".png");
		else
			tex.loadFromFile("Graphics/Single_player/Logo_red.png");
		tex_vector.push_back(tex);
	}
	
	/* Creating sprites and adding them to the sprite_vector and temp_vector */
	Sprite s_background, s_logo, s_logo_red;
	s_background.setTexture(tex_vector.at(0));
	sprite_vector.push_back(s_background); //adding background on position 0
	s_logo.setTexture(tex_vector.at(1));
	s_logo.setPosition(1100, 25);
	s_logo.scale(0.55f, 0.55f);
	sprite_vector.push_back(s_logo); //adding logo on position 1

	for (int j = 0; j < colors.size(); j++) { //adding and setting all colors
		Sprite s;
		s.setTexture(tex_vector.at(j+2));
		s.scale(0.65f, 0.65f);
		s.setOrigin(49,51);
		s.setPosition(110 + (j%3)*80, 300 + (j/3 * 85));
		sprite_vector.push_back(s);
	}

	for (int k = 0; k < colors.size(); k++) { //adding all colors of tanks to the temp_vector
		Sprite s;
		s.setTexture(tex_vector.at(k + 2+colors.size()));
		s.scale(0.23f, 0.23f);
		s.setPosition(350, 180);
		tank_vector.push_back(s);
	}
	sprite_vector.push_back(tank_vector.at(0)); //adding default tank to the sprite_vector = red tank
	sprite_vector.push_back(tank_vector.at(0));

	s_logo_red.setTexture(tex_vector.at(14));
	s_logo_red.setPosition(1090, 16);
	s_logo_red.scale(0.55f, 0.55f);
	sprite_vector.push_back(s_logo_red); //adding logo_red to position 10


	/* Creating and setting stars in star_vector */
	star_vector.push_back(Star("yellow", 0));
	star_vector.push_back(Star("gray", 1));
	star_vector.push_back(Star("gray", 2));
	star_vector.push_back(Star("yellow", 1));
	star_vector.push_back(Star("yellow", 2));
	for (int n = 0; n < 5; n++) {
		star_vector.at(n).loadTexture();
		star_vector.at(n).setLocation();
	}

	/* Setting the text on the screen */
	font.loadFromFile("Extra/nrkis.ttf");
	name.setFont(font);
	name.setOutlineThickness(0.4);
	name.setOutlineColor(sf::Color(235, 225, 225));
	name.setColor(sf::Color(235, 225, 225));
	name.setCharacterSize(40);
	name.setPosition(275, 70);
}

void SinglePlayerState::handleInput(Window & window) {
	sf::Event event;
	sf::Uint32 unicode;

	while (window.pollEvent(event)) {

		mouse_position = sf::Mouse::getPosition(window);

		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				if (isFullScreen)
					window.create(sf::VideoMode(1280, 720), "TanX - single player (1280x720)");
				isFullScreen = false;
				break;

			case sf::Keyboard::F5:
				if (!isFullScreen)
					window.create(sf::VideoMode(1280, 720), "TanX - single player (1280x720)", sf::Style::Fullscreen);
				isFullScreen = true;
				break;

			case sf::Keyboard::Return:
				nextState_ = std::make_unique<PlayingState>();
				break;

			}
			break;

		case sf::Event::TextEntered:
			unicode = event.text.unicode;
			if (unicode == 8 && string.size() > 0) {
				string.erase(string.size() - 1, 1);
				name.setString(string);
			}
			else if ((unicode == 32 || (unicode >= 48 && unicode <= 57) || (unicode >= 65 && unicode <= 90) || (unicode >= 95 && unicode <= 122)) && string.size() < maxTextLength) {
				string += static_cast<char>(unicode);
				name.setString(string);
			}
			std::cout << unicode << std::endl;
			break;

		case sf::Event::MouseMoved:
			std::cout << "x = " << mouse_position.x << ", y = " << mouse_position.y << std::endl;
			
			mouse_on_logo = false;
			if (sprite_vector.at(10).getGlobalBounds().contains(mouse_position.x, mouse_position.y))
				mouse_on_logo = true;

			mouse_on_color = -1;
			for (int i = 0; i < colors.size(); i++) 
				if (sprite_vector.at(i + 2).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
					mouse_on_color = i;
					sprite_vector.at(9) = tank_vector.at(i);
				}

			mouse_on_star = -1;
			for (int j = 0; j < 3; j++)
				if (star_vector.at(j).getSprite().getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
					mouse_on_star = j;
				}

			break;

		case sf::Event::MouseButtonPressed:
			if (mouse_on_color > -1) //changing tank color
				sprite_vector.at(8) = sprite_vector.at(9);

			if (mouse_on_logo) //changing state
				nextState_ = std::make_unique<PlayingState>();
			
			switch (mouse_on_star) { //changing level
			case 0:
				star_vector.at(1).setColor("gray");
				star_vector.at(2).setColor("gray");
				break;
			case 1:
				star_vector.at(1).setColor("yellow");
				star_vector.at(2).setColor("gray");
				break;
			case 2:
				star_vector.at(1).setColor("yellow");
				star_vector.at(2).setColor("yellow");
				break;
			default:
				break;
			}
				
			break;

		default:
			break;
		}
	}
}

void SinglePlayerState::update(double dt) {

}

void SinglePlayerState::draw(Window & window) const {
	for (int i = 0; i < colors.size()+3; i++) //background, logo and all colors + default tank
		window.draw(sprite_vector.at(i));

	if (mouse_on_logo)
		window.draw(sprite_vector.at(10));

	if (mouse_on_color > -1)
		window.draw(sprite_vector.at(9)); //tank on which mouse is on

	for (int j = 0; j < 3 + (mouse_on_star > -1 ? mouse_on_star : 0); j++) {
		star_vector.at(j).draw(window);
	}

	window.draw(name);
}
