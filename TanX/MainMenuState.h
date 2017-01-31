#pragma once
#include "GameState.h"

class MainMenuState : public GameState {
public:
	MainMenuState() {}
	~MainMenuState() {}

	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;
};
