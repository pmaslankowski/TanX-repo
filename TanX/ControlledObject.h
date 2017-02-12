#pragma once
#include<SFML/Graphics.hpp>
#include "Object.h"


class ControlledObject : public Object {
public:
	using Object::Object;

	virtual bool handleEvent(const sf::Event& event) = 0;
};
