#pragma once
#include <vector>
#include "GameState.h"
#include "Sprite.h"
#include "Star.h"

using iVector = sf::Vector2i;
using Texture = sf::Texture;


class SinglePlayerState : public GameState {
public:
	SinglePlayerState() : isFullScreen(true), maxTextLength(16) {}
	~SinglePlayerState() {}

	void loadSprites();
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;

private:
	iVector mouse_position;
	bool isFullScreen;
	int mouse_on_color;
	int mouse_on_star;
	bool mouse_on_logo;

	sf::Text name;
	std::string string = "";
	sf::Font font;
	int maxTextLength;

	std::vector <std::string> colors;
	std::vector <Texture> tex_vector;
	std::vector <Sprite> sprite_vector;
	std::vector <Sprite> tank_vector;
	std::vector <Star> star_vector;
};

