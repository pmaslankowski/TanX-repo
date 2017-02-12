#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Object.h"
#include "TextureManager.h"

using Window = sf::RenderWindow;

class PlayingState : public GameState {
public:
	PlayingState(TextureManager& textureManager) : 
		textureManager(textureManager) {}
	~PlayingState() {}

	void loadSprites();
	void handleInput(Window& window);
	void update(double dt);
	void draw(Window& window) const;
private:
	TextureManager& textureManager;
};