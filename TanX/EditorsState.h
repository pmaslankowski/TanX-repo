#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include <Commons/GameState.h>
#include <Commons/Object.h>
#include <Commons/Vector.h>
#include <Commons/TextureManager.h>


class EditorsState : public GameState {
public:

	EditorsState() {};
	~EditorsState() {};

	void loadSprites(TextureManager& textureManager);
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;

private:
	sf::Text text;



};

