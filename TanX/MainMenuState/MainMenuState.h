#pragma once

#include <vector>

#include <Commons/GameState.h>
#include <Commons/Sprite.h>
#include <Commons/Stripe.h>
#include <Commons/TextureManager.h>



using Vector = sf::Vector2f;

class MainMenuState : public GameState {
public:
	MainMenuState() :
		isFullScreen(false)
	{}
	~MainMenuState() {}

	void loadSprites(TextureManager& textureManager);
	void handleInput(Window &window);
	void update(double dt);
	void draw(Window &window) const;

private:
	bool isFullScreen;
	int bullet_fired;
	Vector mouse_position;
	Sprite s_tower;
	std::vector <Texture> tex_vector;
	std::vector <Sprite> sprite_vector;
	std::vector <Stripe> stripe_vector;
};


using Window = sf::RenderWindow;