#pragma once
#include <vector>
#include "GameState.h"
#include "Sprite.h"

using iVector = sf::Vector2i;
using Texture = sf::Texture;


class SinglePlayerState : public GameState {
public:
	SinglePlayerState() : isFullScreen(true) {}
	~SinglePlayerState() {}

	void loadSprites();
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;

private:
	iVector mouse_position;
	bool isFullScreen;
	int mouse_on_color;
	std::vector <std::string> colors;
	std::vector <Texture> tex_vector;
	std::vector <Sprite> sprite_vector;
	std::vector <Sprite> tank_vector;
};

