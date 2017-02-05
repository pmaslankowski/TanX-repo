#pragma once
#include <vector>
#include "GameState.h"
#include "Sprite.h"
#include "Stripe.h"

using iVector = sf::Vector2i;

class MainMenuState : public GameState {
public:
	MainMenuState() {}
	~MainMenuState() {}

	void loadSprites();
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;
	float getAngle();

private:
	int bullet_fired;
	iVector mouse_position;
	Sprite s_tower;
	std::vector <Texture> tex_vector;
	std::vector <Sprite> sprite_vector;
	std::vector <Stripe> stripe_vector;
};


using Window = sf::RenderWindow;