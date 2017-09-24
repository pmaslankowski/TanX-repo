#include <string>

#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <PlayingState/ObjectFactory.h>

#include "Terrain.h"


void Terrain::loadSprite(TextureManager& texture_manager) {
	switch (type) {
	case Type::TerrainGrass:
		sprite_.setTexture(texture_manager.getTexture("Terrain_grass.png"));
		break;
	case Type::TerrainSand:
		sprite_.setTexture(texture_manager.getTexture("Terrain_sand.png"));
		break;
	case Type::TerrainMud:
		sprite_.setTexture(texture_manager.getTexture("Terrain_mud.png"));
		break;
	}
	scaleTexture();
}


REGISTER_OBJECT(Terrain, "TerrainGrass");
REGISTER_OBJECT_WITH_LAMBDA(Terrain, "TerrainSand", [](float x, float y, float width, float height, float priority) -> Object* {
	return new Terrain(x, y, width, height, priority, Terrain::Type::TerrainSand);
});
//REGISTER_OBJECT_WITH_LAMBDA(Terrain, "TerrainMud", [](float x, float y, float width, float height, float priority) -> Object* {
//	return new Terrain(x, y, width, height, priority, Terrain::Type::TerrainMud);
//});


