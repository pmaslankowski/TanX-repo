#pragma once
#include <memory>
#include <SFML/Graphics.hpp>


using Window = sf::RenderWindow;

/* Interface of state of game.*/
class GameState {
public:
	GameState() {}
	virtual ~GameState() {};

	// Function is supposed to handle input of given window. It's called in main loop repeatedly
	virtual void handleInput(Window &window) = 0;
	// Function is supposed to update state. It's called in main loop repeatedly
	virtual void update(double dt) = 0;
	// Function is supposed to draw state on given window. It's called in main loop repeatedly
	virtual void draw(Window &window) const = 0;

	// Function returns true if state is supposed to change
	bool changed() const { return nextState_ != nullptr; }
	// Function returns next state 
	std::unique_ptr<GameState> next() { return std::move(nextState_); }

protected:
	std::unique_ptr<GameState> nextState_;
};
