#include <SFML/Graphics.hpp>
#include "PlayingState.h"


void PlayingState::handleInput(Window & window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			window.close();
	}
}


void PlayingState::update(double dt) {
}


void PlayingState::draw(Window & window) const {
}
