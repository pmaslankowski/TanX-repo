#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include <memory>
#include<SFML/Graphics.hpp>


using Texture = sf::Texture;

class TextureManager {
public:
	TextureManager() {}
	~TextureManager() {}

	// Texture id is path relative to Graphics/ without suffix (for example without .png)
	// If there is no texture with given id, function throws exception: std_out_of_range
	Texture& getTexture(std::string id) const { return *textures.at(id); }

	// function load all textures and put them into memory
	// be careful - it may take some time
	bool loadTextures();

private:
	std::unordered_map<std::string, std::unique_ptr<Texture>> textures;
};
