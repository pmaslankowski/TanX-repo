#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"


using Window = sf::RenderWindow;

class PlayingState : public GameState {
public:
	PlayingState() {}
	~PlayingState() {}

	void handleInput(Window& window);
	void update(double dt);
	void draw(Window& window) const;
};