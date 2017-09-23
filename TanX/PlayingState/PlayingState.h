#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include <Commons/GameState.h>
#include <Commons/Object.h>
#include <Commons/TextureManager.h>


using Window = sf::RenderWindow;

class PlayingState : public GameState {
public:
	PlayingState() {}
	~PlayingState() {}

	void loadSprites(TextureManager& textureManager);
	void handleInput(Window& window);
	void update(double dt);
	void draw(Window& window) const;

private:
	TextureManager* m_texture_manager;
	std::vector<Object*> m_objects;
};


class ObjectsLoader {
public:
	enum class State { Success = 0, Pending, InvalidFileName, ParseError, UnknownObject };

	void loadFromFile(const std::string& filename);
	std::vector<Object*> getObjects();
	State getState() const { return m_state; }

private:
	std::vector<Object*> m_objects;
	State m_state = State::Pending;
};