#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SinglePlayerState.h"
#include "PlayingState.h"
#include "TextureManager.h"


void SinglePlayerState::loadSprites(TextureManager& textureManager) {
	/* Loading textures */
	star_vector.loadTexture(textureManager);
	colors_and_tank.loadTexture();
	name_stripe.loadTexture();
	logo.loadTexture();

	/* Creating and setting sprites */
	background.setTexture(textureManager.getTexture("Single_player\\Background.png"));
	star_vector.setLocation();
	colors_and_tank.setLocation();
	name_stripe.setLocation();
	logo.setLocation();
}

void SinglePlayerState::handleInput(Window & window) {
	sf::Event event;
	sf::Uint32 unicode;

	while (window.pollEvent(event)) {
		mouse_position = sf::Mouse::getPosition(window);

		name_stripe.handleInput(event, mouse_position);
		star_vector.handleInput(event, mouse_position);
		colors_and_tank.handleInput(event, mouse_position);
		logo.handleInput(event, mouse_position);

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
				//nextState_ = std::make_unique<PlayingState>();
				break;
			}
			break;

		default:
			break;
		}
	}
}

void SinglePlayerState::update(double dt) {
	name_stripe.update(dt);
}

void SinglePlayerState::draw(Window & window) const {
	window.draw(background);

	star_vector.draw(window);
	colors_and_tank.draw(window);
	name_stripe.draw(window);
	logo.draw(window);
}
