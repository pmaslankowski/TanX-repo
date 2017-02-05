#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "PlayingState.h"
#include "SinglePlayerState.h"

#define PI 3.14159265

using fVector = sf::Vector2f;
using iVector = sf::Vector2i;

void MainMenuState::loadSprites() {

	/* Loading and setting everything for stripes */
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

	/* Loading rest of the textures */
	Texture t_background;
	t_background.loadFromFile("Graphics/Main_menu/Background.png");
	tex_vector.push_back(t_background);
	for (int l = 0; l < stripe_vector.size() / 2; l++) { //loading bullets textures
		Texture t_bullet;
		t_bullet.loadFromFile("Graphics/Main_menu/Bullet_" + stripe_color[l] + ".png");
		tex_vector.push_back(t_bullet);
	}
	Texture t_tower;
	t_tower.loadFromFile("Graphics/Main_menu/Tower_black.png");
	tex_vector.push_back(t_tower);

	/* Creating rest of the sprites */
	for (int m = 0; m < stripe_vector.size() / 2 + 1; m++) { //adding background and bullets to sprite_vector
		Sprite s;
		s.setTexture(tex_vector.at(m));
		if (m > 0) {
			s.scale(0.65f, 0.65f);
			s.setOrigin(72, 42);
			s.setPosition(stripe_vector.at(m - 1).getBoundingRect().width - 72, stripe_vector.at(m - 1).getPosition().y + stripe_vector.at(m - 1).getBoundingRect().height / 2);
		}
		sprite_vector.push_back(s);
	}
	//loading all (short at the beginning) stripes to the vector of sprites - cause only this vector will be drawn
	for (int k = 0; k < stripe_vector.size() / 2; k++) 
		sprite_vector.push_back(stripe_vector.at(k).getSprite()); 

	s_tower.setTexture(tex_vector.at(tex_vector.size() - 1));
	s_tower.setOrigin(85, 365);
	s_tower.scale(0.6f, 0.6f);
	s_tower.setPosition(980, 465);
	bullet_fired = -1;
}

void MainMenuState::handleInput(Window &window) {
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
					window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)");
				isFullScreen = false;
				break;

			case sf::Keyboard::F5:
				if (!isFullScreen)
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
				if (sprite_vector.at(i + 6).getGlobalBounds().contains(mouse_position.x, mouse_position.y))
					sprite_vector.at(i + 6) = stripe_vector.at(i + stripe_vector.size()/2).getSprite();
				else
					sprite_vector.at(i + 6) = stripe_vector.at(i).getSprite();
			break;

		case sf::Event::MouseButtonPressed:
			for (int i = 0; i < stripe_vector.size() / 2; i++)
				if (sprite_vector.at(i + 6).getGlobalBounds().contains(mouse_position.x, mouse_position.y) && bullet_fired<0)
					bullet_fired = i;
			break;

		default:
			break;
		}
	}
}


void MainMenuState::update(double dt) {
	int current_x = 0;
	if (bullet_fired >= 0) {
		current_x = sprite_vector.at(bullet_fired + 1).getPosition().x;
		int current_y = sprite_vector.at(bullet_fired + 1).getPosition().y;
		sprite_vector.at(bullet_fired + 1).setPosition(current_x + dt, current_y);
	}

	s_tower.setRotation(getAngle());
	//s_tower.setOrientation(fVector(mouse_position.x, mouse_position.y) - fVector(s_tower.getPosition().x, s_tower.getPosition().y));

	if (current_x > 1260 && bullet_fired == 0) {
		nextState_ = std::make_unique<SinglePlayerState>();
		std::cout << "PRZELACZENIE STANU" << std::endl;
	}
}


void MainMenuState::draw(Window &window) const {
	for (int i = 0; i < sprite_vector.size(); i++)
		window.draw(sprite_vector.at(i));
	window.draw(s_tower);
}

float MainMenuState::getAngle() {
	fVector mouse_vector(mouse_position.x - s_tower.getPosition().x, s_tower.getPosition().y - mouse_position.y);
	fVector unit_mouse_vector = mouse_vector / sqrt(mouse_vector.x*mouse_vector.x + mouse_vector.y*mouse_vector.y);
	float cosinus = unit_mouse_vector.x * 0 + unit_mouse_vector.y * 1; //because unit_tower_vector = (0,1)
	return (mouse_vector.x < 0) ? 360 - (acos(cosinus) * 180.0 / PI) : acos(cosinus) * 180.0 / PI;
}
