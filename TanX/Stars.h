#pragma once
#include <string>
#include "Object.h"

class Stars : public Object {
public:

	Stars();
	~Stars() {}

	void loadTexture();
	void setLocation();
	std::string getColor(int i) const { return star_vector.at(i).id; }
	void setColor(std::vector<Object> &vector, int i, std::string color);
	void setStarsInVector(std::vector<Object> &vector, int i);

	void handleInput(sf::Event &event, sf::Vector2i mouse_position);
	void draw(sf::RenderWindow &window) const;

private:
	std::vector <Texture> tex_vector;
	std::vector <Object> star_vector;
	std::vector <Object> temp_star_vector;
	int levels;
};

