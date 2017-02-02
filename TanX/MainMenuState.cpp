#include "MainMenuState.h"
#include "PlayingState.h"
#include <memory>


void MainMenuState::handleInput(Window &window) {
	/* Replace this with your code */
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			window.close();
		//Test of state change:
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			nextState_ = std::make_unique<PlayingState>();
	}
}


void MainMenuState::update(double dt) {
	/* Put your code here */
}


void MainMenuState::draw(Window &window) const {
	/* Put your code here*/
	// creating new objects here is bad idea - this code repeats in a loop
	sf::CircleShape shape(350.f);
	shape.setFillColor(sf::Color::Green);

	window.draw(shape);
}