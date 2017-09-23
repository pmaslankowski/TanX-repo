#include <SFML/Graphics.hpp>
#include "PlayingState.h"
#include "ObjectFactory.h"


void PlayingState::loadSprites(TextureManager& textureManager){
	m_texture_manager = &textureManager;
	for (auto* object : m_objects)
		object->loadSprite(textureManager);
}


void PlayingState::handleInput(Window &window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			window.close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
			std::cout << "Tree added\n";
			m_objects.push_back(ObjectFactory::create("Tree1", 0, 0, 100, 100));
			(*m_objects.rbegin())->loadSprite(*m_texture_manager);
		}
	}
}


void PlayingState::update(double dt) {
}


void PlayingState::draw(Window &window) const {
	for (auto* object : m_objects)
		object->draw(window);
}





void ObjectsLoader::loadFromFile(const std::string & filename)
{

}

std::vector<Object*> ObjectsLoader::getObjects()
{
	if (m_state == State::Success)
		return m_objects;
	return {};
}
