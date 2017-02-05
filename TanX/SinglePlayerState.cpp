#include <iostream>
#include <SFML/Graphics.hpp>
#include "SinglePlayerState.h"
#include "PlayingState.h"


void SinglePlayerState::loadSprites() {
	colors = { "red", "yellow", "green", "pink", "blue", "orange" };
	
	/* Loading all textures to tex_vector */
	for (int i = 0; i < 2 + 2*colors.size() + 2; i++) { //loading background, logo, all colors and colored tanks, and 2 types of stars
		Texture tex;
		if (i == 0)
			tex.loadFromFile("Graphics/Single_player/Background.png");
		else if (i == 1)
			tex.loadFromFile("Graphics/Single_player/Logo.png");
		else if (2 <= i && i < 8) 
			tex.loadFromFile("Graphics/Single_player/Color_" + colors[i-2] + ".png");
		else if (8 <= i && i < 14) 
			tex.loadFromFile("Graphics/Single_player/Color_tank_" + colors[i-8] + ".png");
		else if (i == 14) 
			tex.loadFromFile("Graphics/Single_player/Star_yellow.png");
		else
			tex.loadFromFile("Graphics/Single_player/Star_gray.png");
		tex_vector.push_back(tex);
	}
	
	/* Creating sprites and adding them to the sprite_vector: background, logo and colors */
	Sprite s_background, s_logo;
	s_background.setTexture(tex_vector.at(0));
	sprite_vector.push_back(s_background);
	s_logo.setTexture(tex_vector.at(1));
	sprite_vector.push_back(s_logo);

	for (int j = 0; j < colors.size(); j++) {
		Sprite s;
		s.setTexture(tex_vector.at(j+2));
		s.scale(0.65f, 0.65f);
		s.setOrigin(49,51);
		s.setPosition(110 + (j%3)*85, 300 + (j/3 * 85));
		sprite_vector.push_back(s);
	}
}

void SinglePlayerState::handleInput(Window & window) {
	sf::Event event;
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
				window.create(sf::VideoMode(1280, 720), "TanX - single player (1280x720)");
				break;

			case sf::Keyboard::F5:
				window.create(sf::VideoMode(1280, 720), "TanX - single player (1280x720)", sf::Style::Fullscreen);
				break;

			case sf::Keyboard::Return:
				nextState_ = std::make_unique<PlayingState>();
				break;
			}
			break;

		case sf::Event::MouseMoved:
			std::cout << "x = " << mouse_position.x << ", y = " << mouse_position.y << std::endl;
			break;

		case sf::Event::MouseButtonPressed:
			
			break;

		default:
			break;
		}
	}
}

void SinglePlayerState::update(double dt) {
}

void SinglePlayerState::draw(Window & window) const {
	window.draw(sprite_vector.at(0));
	for (int i = 0; i < colors.size(); i++)
		window.draw(sprite_vector.at(i+2));

	//std::cout << sprite_vector.size() << std::endl;
}
