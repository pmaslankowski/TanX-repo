#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "TextureManager.h"

using Window = sf::RenderWindow;

/* Structure with game settings */
struct GameSettings {
	std::string title = "TanX"; //title displayed on window bar
	int screenWidth = 1280;
	int screenHeight = 720;
	double maxFPS = 60;
	bool fullscreen = true;
};


/* Game main class. */
class Game {
public:
	Game(const GameSettings& settings);
	~Game() {}

	void mainLoop();
private:
	std::unique_ptr<GameState> state_;
	TextureManager textureManager_;
	Window window_;
	double maxFPS;

	void printAvailableVideoModes();

};