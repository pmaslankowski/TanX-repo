#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Object.h"
#include "InterferingObject.h"
#include "ControlledObject.h"
#include "TextureManager.h"


using Window = sf::RenderWindow;

class PlayingState : public GameState {
public:
	PlayingState(TextureManager& textureManager) : 
		textureManager(textureManager) {}
	~PlayingState() {}

	void loadSprites();
	void handleInput(Window& window);
	void update(double dt);
	void draw(Window& window) const;

private:
	TextureManager& textureManager;

	// auxilary type aliases:
	using ObjectsMap = std::unordered_map<std::string, std::shared_ptr<Object>>;
	using InterferingObjectsMap = std::unordered_map<std::string, std::shared_ptr<InterferingObject>>;
	using ControlledObjectsMap = std::unordered_map<std::string, std::shared_ptr<ControlledObject>>;

	ObjectsMap objects;
	InterferingObjectsMap interferingObjects;
	ControlledObjectsMap controlledObjects;
};