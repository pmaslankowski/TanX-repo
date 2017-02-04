#pragma once
#include <string>
#include "Object.h"

class Stripe : public Object {
public:
	
	Stripe(std::string color, std::string length);
	~Stripe() {}

	void loadTexture();
	void setLocation();

private:
	std::string color;
	std::string length;
	Texture texture;
};

