#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <Commons/TextureManager.h>
#include <Commons/Vector.h>



class Tank final : public Object {
	using Object::Object;
public:
	enum class Type { TankRed, TankGreen, TankBlue, TankYellow, TankPink, TankOrange };

	Tank(float x, float y, float width, float height, float priority, Type type)
		: Object(x, y, width, height, priority), type(type) {}

	virtual void loadSprite(TextureManager& texture_manager) override;
	virtual void setDefaultOrigin() override;

	Type type = Type::TankRed;
	static const float VELOCITY_SCALE; //the number of times velocity will be reduced
};