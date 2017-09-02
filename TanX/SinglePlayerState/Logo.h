#pragma once

#include <string>
#include <memory>

#include <Commons/Object.h>
#include <Commons/GameState.h>
#include <Commons/TextureManager.h>


class Logo {
public:

	Logo() {}
	~Logo() {}

	void loadTexture(TextureManager& textureManager);
	void setLocation();
	void handleInput(sf::Event &event, Window& window, GameState* state);
	void draw(sf::RenderWindow &window) const;

private:
	Texture tex_logo;
	Sprite logo;
	Texture tex_temp_logo;
	Sprite temp_logo;

	bool mouse_on_logo;
};
