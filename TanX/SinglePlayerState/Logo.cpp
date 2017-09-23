#include <PlayingState/PlayingState.h>

#include "Logo.h"


void Logo::loadTexture(TextureManager& textureManager) {
	tex_logo = textureManager.getTexture("Single_player\\Logo.png");
	tex_temp_logo = textureManager.getTexture("Single_player\\Logo_red.png");
}

void Logo::setLocation() {
	logo.setTexture(tex_logo);
	logo.setPosition(1100, 25);
	logo.scale(0.55f, 0.55f);

	temp_logo.setTexture(tex_temp_logo);
	temp_logo.setPosition(1090, 16);
	temp_logo.scale(0.55f, 0.55f);
}

void Logo::handleInput(sf::Event & event, Window& window, GameState* current_state) {
	const auto& mouse_position = sf::Mouse::getPosition(window);

	switch (event.type) {
	case sf::Event::MouseMoved:
		mouse_on_logo = false;
		if (logo.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
			mouse_on_logo = true;
		break;

	case sf::Event::MouseButtonPressed:
		if (mouse_on_logo)
			current_state->m_nextState = std::make_unique<PlayingState>("Levels\\test.level");
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

