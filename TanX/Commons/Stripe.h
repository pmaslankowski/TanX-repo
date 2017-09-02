#pragma once
#include <string>
#include "Object.h"
#include "TextureManager.h"

class Stripe : public Object {
public:
	
	Stripe(std::string color, std::string length);
	~Stripe() {}

	void loadTexture(const TextureManager& textureManager);
	void setLocation();
	std::string getColor() const { return color; }

private:
	std::string color;
	std::string length;
	Texture texture;
};

