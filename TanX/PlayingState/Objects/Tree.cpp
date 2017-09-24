#include <string>

#include <SFML/Graphics.hpp>
#include <Commons/Sprite.h>
#include <Commons/Object.h>
#include <PlayingState/ObjectFactory.h>

#include "Tree.h"




void Tree::loadSprite(TextureManager& texture_manager) {
	switch (type) {
	case Type::Tree1:
		sprite_.setTexture(texture_manager.getTexture("Tree_01.png"));
		break;
	case Type::Tree2:
		sprite_.setTexture(texture_manager.getTexture("Tree_02.png"));
		break;
	}
	scaleTexture();
}


REGISTER_OBJECT(Tree, "Tree1");
REGISTER_OBJECT_WITH_LAMBDA(Tree, "Tree2", [](float x, float y, float width, float height, float priority) -> Object* {
	return new Tree(x, y, width, height, priority, Tree::Type::Tree2);
});


