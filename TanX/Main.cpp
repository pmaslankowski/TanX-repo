#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	GameSettings settings; //default settings
	settings.screenWidth = 1280;
	settings.screenHeight = 720;

	Game game(settings);
	game.mainLoop();
	return 0;
}