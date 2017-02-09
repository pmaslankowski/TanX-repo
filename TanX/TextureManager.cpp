#include<string>
#include<vector>
#include<iostream>
#include<memory>
#include<SFML/Graphics.hpp>
#include "TextureManager.h"
#include "GlobalServices.h"
#include "FileSystem.h"

bool TextureManager::loadTextures() {
	FileSystem *filesystem = GlobalServices::getFileSystem();
	auto files = filesystem->listDirectoryRec("Graphics");

	for (auto& file : files) {
		auto texture = std::make_unique<Texture>();
		if (!texture->loadFromFile(file))
			return false;

		// remove Graphics\\ prefix
		std::string key = file.substr(9);
		textures[key] = std::move(texture);
	}
	return true;
}
