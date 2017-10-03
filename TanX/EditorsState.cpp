#include "EditorsState.h"



void EditorsState::loadSprites(TextureManager & textureManager) {
	text.setString("This is EDIOTORS mode");
	text.setCharacterSize(100); //in pixels
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//text.setPosition(500, 300);
	std::cout << "Text added\n";
}

void EditorsState::handleInput(Window & window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:

			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				/*if (isFullScreen)
				window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)");
				isFullScreen = false;*/

				window.close();
				break;

			case sf::Keyboard::F5:
				/*if (!isFullScreen)
				window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)", sf::Style::Fullscreen);
				isFullScreen = true;*/
				break;
			}
			break;

		case sf::Event::MouseMoved:
			break;

		case sf::Event::MouseButtonPressed:
			break;

		default:
			break;
		}
	}
}

void EditorsState::update(double dt) {

}

void EditorsState::draw(Window & window) const {	
	window.draw(text);
}
