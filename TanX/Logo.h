#pragma once
#include <string>
#include <memory>
#include "Object.h"
#include "GameState.h"

class Logo {
public:

	Logo() {}
	~Logo() {}

	void loadTexture();
	void setLocation();
	void handleInput(sf::Event &event, sf::Vector2i mouse_position);
	void draw(sf::RenderWindow &window) const;

private:
	Texture tex_logo;
	Sprite logo;
	Texture tex_temp_logo;
	Sprite temp_logo;

	bool mouse_on_logo;
};
