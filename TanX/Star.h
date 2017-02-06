#pragma once
#include <string>
#include "Object.h"

class Star : public Object {
public:

	Star(std::string color, int nr);
	~Star() {}

	void loadTexture();
	void setLocation();
	std::string getColor() const { return color; }
	void setColor(std::string color);

private:
	std::string color;
	int number;
	Texture texture;
};

