#include <string>

#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <PlayingState/ObjectFactory.h>

#include "Tree.h"




void Tree::loadSprite(TextureManager& texture_manager) {
	sprite_.setTexture(texture_manager.getTexture("Tree_01.png"));
	scaleTexture();
}


REGISTER_OBJECT(Tree, "Tree1");


