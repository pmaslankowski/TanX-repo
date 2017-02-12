#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Object.h"
#include "TextureManager.h"

using Window = sf::RenderWindow;

class PlayingState : public GameState {
public:
	PlayingState() {}
	~PlayingState() {}

	void loadSprites(TextureManager& textureManager);
	void handleInput(Window& window);
	void update(double dt);
	void draw(Window& window) const;
};