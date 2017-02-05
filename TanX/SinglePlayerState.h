#pragma once
#include <vector>
#include "GameState.h"
#include "Sprite.h"

using iVector = sf::Vector2i;
using Texture = sf::Texture;


class SinglePlayerState : public GameState {
public:
	SinglePlayerState() {}
	~SinglePlayerState() {}

	void loadSprites();
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;

private:
	iVector mouse_position;
	std::vector <std::string> colors;
	std::vector <Texture> tex_vector;
	std::vector <Sprite> sprite_vector;
};

