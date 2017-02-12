#pragma once
#include <string>
#include "Object.h"
#include "TextureManager.h"


class ColoredTank {
public:

	ColoredTank();
	~ColoredTank() {}

	void loadTexture(TextureManager& textureManager);
	void setLocation();
	void handleInput(sf::Event &event, sf::Vector2i mouse_position);
	void draw(sf::RenderWindow &window) const;

private:
	std::vector <std::string> colors;
	std::vector <Texture*> tex_vector;
	std::vector <Sprite> color_vector;

	Sprite default_tank;
	std::vector <Sprite> temp_tank_vector;

	int mouse_on_color;
};

