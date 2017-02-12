#pragma once
#include "Object.h"


class InterferingObject : public Object {
public:
	using Object::Object;

	virtual void collideWith(InterferingObject& other) { other.collideWith(*this); }
};