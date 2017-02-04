#include <memory>
#include <iostream>
#include "MainMenuState.h"
#include "PlayingState.h"


void MainMenuState::loadSprites() {

	//loading and setting everything for stripes
	std::string stripe_length = "short";
	const std::string stripe_color[] = { "sp", "m", "e", "s", "exit" };
	for (int i = 0; i < 2; i++) { //we have 2 lengths of stripes to load - short and long ones
		for (int j=0; j < 5; j++) //we have 5 colors of stripes to load (named in the array above)
			stripe_vector.push_back(Stripe(stripe_color[j], stripe_length));
		stripe_length = "long";
	}
	for (int j = 0; j < stripe_vector.size(); j++) {
		stripe_vector.at(j).loadTexture();
		stripe_vector.at(j).setLocation();
	}

	Texture t_background;
	t_background.loadFromFile("Graphics/Main_menu/Background.png");
	tex_vector.push_back(t_background);

	Sprite s_background;
	s_background.setTexture(tex_vector.at(0));
	sprite_vector.push_back(s_background);

	for (int k = 0; k < stripe_vector.size() / 2; k++)
		sprite_vector.push_back(stripe_vector.at(k).getSprite()); //loading all short stripes to the vector of sprites - cause only this vector will be drawn
}

void MainMenuState::handleInput(Window &window) {
	mouse_position = sf::Mouse::getPosition(window);

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
				window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)");
				isFullScreen = false;
				break;

			case sf::Keyboard::F5:
				window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)", sf::Style::Fullscreen);
				isFullScreen = true;
				break;
			
			case sf::Keyboard::Return:
				nextState_ = std::make_unique<PlayingState>();
				break;
			}
			break;

		case sf::Event::MouseMoved:
			for (int i = 0; i < stripe_vector.size() / 2; i++)
				if (sprite_vector.at(i + 1).getGlobalBounds().contains(mouse_position.x, mouse_position.y))
					sprite_vector.at(i + 1) = stripe_vector.at(i + stripe_vector.size()/2).getSprite();
				else
					sprite_vector.at(i + 1) = stripe_vector.at(i).getSprite();
			break;

		default:
			break;
		}
	}
}


void MainMenuState::update(double dt) {
	/* Put your code here */
}


void MainMenuState::draw(Window &window) const {
	for (int i=0; i<6; i++)
		window.draw(sprite_vector.at(i));

	
}