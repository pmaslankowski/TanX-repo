#pragma once

#include <vector>

#include <Commons/GameState.h>
#include <Commons/Sprite.h>

#include "Stars.h"
#include "NameStripe.h"
#include "ColoredTank.h"
#include "Logo.h"


using iVector = sf::Vector2i;
using Texture = sf::Texture;


class SinglePlayerState : public GameState {
public:
	SinglePlayerState() : isFullScreen(true) {}
	~SinglePlayerState() {}

	void loadSprites(TextureManager& textureManager);
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;

	friend Logo;
private:
	iVector mouse_position;
	bool isFullScreen;

	Texture tex_background;
	Sprite background;

	Stars star_vector;
	ColoredTank colors_and_tank;
	NameStripe name_stripe;
	Logo logo;
};

