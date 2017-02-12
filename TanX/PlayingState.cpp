#include <SFML/Graphics.hpp>
#include "PlayingState.h"


void PlayingState::loadSprites() {
}


void PlayingState::handleInput(Window &window) {
	sf::Event event;
	while (window.pollEvent(event))
		for (auto& objectPair : controlledObjects)
			objectPair.second->handleEvent(event);
}


void PlayingState::update(double dt) {
	for (auto& objectPair : objects)
		objectPair.second->update(dt);
}


void PlayingState::draw(Window &window) const {
	for (auto& objectPair : objects)
		objectPair.second->draw(window);
}
