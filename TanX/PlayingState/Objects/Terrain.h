#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <Commons/TextureManager.h>

class Terrain final : public Object {
	using Object::Object;
public:
	enum class Type { TerrainGrass, TerrainSand, TerrainMud };

	Terrain(float x, float y, float width, float height, float priority, Type type)
		: Object(x, y, width, height, priority), type(type) {}

	virtual void loadSprite(TextureManager& texture_manager) override;

	Type type = Type::TerrainGrass;

};

