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
	
	/* Creating sprites and adding them to the sprite_vector and tan_vector */
	Sprite s_background, s_logo;
	s_background.setTexture(tex_vector.at(0));
	sprite_vector.push_back(s_background); //adding background on position 0
	s_logo.setTexture(tex_vector.at(1));
	sprite_vector.push_back(s_logo); //adding logo on position 1

	for (int j = 0; j < colors.size(); j++) { //adding and setting all colors avaliable
		Sprite s;
		s.setTexture(tex_vector.at(j+2));
		s.scale(0.65f, 0.65f);
		s.setOrigin(49,51);
		s.setPosition(110 + (j%3)*80, 300 + (j/3 * 85));
		sprite_vector.push_back(s);
	}

	for (int k = 0; k < colors.size(); k++) { //adding all colors of tanks to the tank vector
		Sprite s;
		s.setTexture(tex_vector.at(k + 2+colors.size()));
		s.scale(0.23f, 0.23f);
		s.setPosition(350, 180);
		tank_vector.push_back(s);
	}
	sprite_vector.push_back(tank_vector.at(2)); //adding default tank to the sprite_vector = green tank
	sprite_vector.push_back(tank_vector.at(2));
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

		case sf::Event::MouseMoved:
			std::cout << "x = " << mouse_position.x << ", y = " << mouse_position.y << std::endl;
			
			mouse_on_color = -1;
			for (int i = 0; i < colors.size(); i++) 
				if (sprite_vector.at(i + 2).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
					mouse_on_color = i;
					sprite_vector.at(9) = tank_vector.at(i);
				}
			std::cout << mouse_on_color << std::endl;
			break;

		case sf::Event::MouseButtonPressed:
			if (mouse_on_color > -1)
				sprite_vector.at(8) = sprite_vector.at(9);
			break;

		default:
			break;
		}
	}
}

void SinglePlayerState::update(double dt) {

}

void SinglePlayerState::draw(Window & window) const {
	window.draw(sprite_vector.at(0)); //background
	for (int i = 0; i < colors.size()+1; i++) //all colors + default tank
		window.draw(sprite_vector.at(i+2));

	if (mouse_on_color > -1)
		window.draw(sprite_vector.at(9)); //tank on which mouse is on
}
