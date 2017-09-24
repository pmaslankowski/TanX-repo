#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <Commons/TextureManager.h>



class Tree final : public Object {
	using Object::Object;
public:
	enum class Type { Tree1, Tree2 };
	
	Tree(float x, float y, float width, float height, float priority, Type type)
		: Object(x, y, width, height, priority), type(type) {}

	virtual void loadSprite(TextureManager& texture_manager) override;

	Type type = Type::Tree1;
};