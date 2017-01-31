#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <string>


typedef sf::RenderWindow Window;


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
	Window window_;
	double maxFPS;
};