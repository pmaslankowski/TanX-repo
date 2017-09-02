#pragma once
#include <SFML/Graphics.hpp>
#include <Commons/TextureManager.h>


class NameStripe {
public:

	NameStripe() : time(0) {}
	~NameStripe() {}

	void loadTexture(TextureManager& textureManager);
	void setLocation();
	void handleInput(sf::Event &event, sf::Vector2i mouse_position);
	void update(double dt);
	void draw(sf::RenderWindow &window) const;

private:
	enum cursor { OFF, ON_hidden, ON_shown };
	cursor cursor;
	sf::RectangleShape s_cursor;
	sf::Sprite s_name_stripe;
	sf::Texture tex_name_stripe;
	
	sf::Text name;
	std::string string = "";
	sf::Font font;
	double time; //in miliseconds; frequency of cursor blinking 
};

