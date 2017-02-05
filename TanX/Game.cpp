#include <memory>
#include "Game.h"
#include "MainMenuState.h"
#include "SinglePlayerState.h"


Game::Game(const GameSettings& settings) {
	int screenStyle = settings.fullscreen ? sf::Style::Fullscreen : sf::Style::Default;
	window_.create(sf::VideoMode(settings.screenWidth, settings.screenHeight), settings.title, screenStyle);
	
	this->maxFPS = settings.maxFPS;
	state_ = std::make_unique<SinglePlayerState>(); //changed from MainMenuState for testing
}


void Game::mainLoop() {
	sf::Clock clock;
	sf::Time elapsed;
	double dt; //duration of one tick of loop
	state_->loadSprites();

	while (window_.isOpen()) {
		elapsed = clock.restart();
		dt = elapsed.asMilliseconds();

		state_->handleInput(window_);
		state_->update(dt);
		window_.clear();
		state_->draw(window_);
		window_.display();

		//if we have to change state:
		if (state_->changed()) {
			state_ = state_->next();
			state_->loadSprites();
		}

		//if loop goes faster than it is supposed to, program sleeps to not consume all CPU power
		if (dt < 1000 / maxFPS)
			sf::sleep(sf::milliseconds(1000 / maxFPS - dt));
	}
}


void Game::printAvailableVideoModes() {
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	for (std::size_t i = 0; i < modes.size(); ++i) {
		sf::VideoMode mode = modes[i];
		std::cout << "Mode #" << i << ": "
			<< mode.width << "x" << mode.height << " - "
			<< mode.bitsPerPixel << " bpp" << std::endl;
	}
}
