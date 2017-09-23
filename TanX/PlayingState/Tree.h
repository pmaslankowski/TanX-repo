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
	
	virtual void loadSprite(TextureManager& texture_manager) override;

	Type type;
};