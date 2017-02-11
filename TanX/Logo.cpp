#include "Logo.h"


void Logo::loadTexture() {
	tex_logo.loadFromFile("Graphics/Single_player/Logo.png");
	tex_temp_logo.loadFromFile("Graphics/Single_player/Logo_red.png");
}

void Logo::setLocation() {
	logo.setTexture(tex_logo);
	logo.setPosition(1100, 25);
	logo.scale(0.55f, 0.55f);

	temp_logo.setTexture(tex_temp_logo);
	temp_logo.setPosition(1090, 16);
	temp_logo.scale(0.55f, 0.55f);
}

void Logo::handleInput(sf::Event & event, sf::Vector2i mouse_position) {
	switch (event.type) {
	case sf::Event::MouseMoved:
		mouse_on_logo = false;
		if (logo.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
			mouse_on_logo = true;
		break;

	case sf::Event::MouseButtonPressed:
		if (mouse_on_logo)
//			nextState_ = std::make_unique<PlayingState>();
		break;

	default:
		break;
	}
}

void Logo::draw(sf::RenderWindow & window) const {
	if (mouse_on_logo)
		window.draw(temp_logo);
	else
		window.draw(logo);
}

