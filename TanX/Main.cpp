#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	GameSettings settings; //default settings
	settings.screenWidth = 1920;
	settings.screenHeight = 1080;

	Game game(settings);
	game.mainLoop();
	return 0;
}