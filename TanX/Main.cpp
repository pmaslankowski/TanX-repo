#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	GameSettings settings; //default settings
	settings.screenHeight = 1280;
	settings.screenWidth = 720;

	Game game(settings);
	game.mainLoop();
	return 0;
}