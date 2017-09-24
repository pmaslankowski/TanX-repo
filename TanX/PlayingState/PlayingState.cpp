#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "PlayingState.h"
#include "ObjectFactory.h"


PlayingState::PlayingState(const std::string& level_filename) {
	ObjectsLoader loader;
	std::cout << "Ladowanie obiektow z pliku: " << level_filename << "\n";
	loader.loadFromFile(level_filename);
	std::cout << "Stan loadera:" << static_cast<int>(loader.getState()) << "\n";
	m_objects = loader.getObjects();
}


PlayingState::~PlayingState() {
	for (auto* object : m_objects)
		delete object;
}


void PlayingState::loadSprites(TextureManager& textureManager){
	m_texture_manager = &textureManager;
	for (auto* object : m_objects)
		object->loadSprite(textureManager);
}


void PlayingState::handleInput(Window &window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				if (isFullScreen)
					window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)");
				isFullScreen = false;
				break;

			case sf::Keyboard::F5:
				if (!isFullScreen)
					window.create(sf::VideoMode(1280, 720), "TanX - main menu (1280x720)", sf::Style::Fullscreen);
				isFullScreen = true;
				break;

			case sf::Keyboard::A:
				std::cout << "Tree added\n";
				m_objects.push_back(ObjectFactory::create("Tree1", 200, 500, 100, 100, 1));
				(*m_objects.rbegin())->loadSprite(*m_texture_manager);
				break;

			case sf::Keyboard::Return:
				window.close();
				break;
			}
			break;

		case sf::Event::MouseMoved:
			break;

		case sf::Event::MouseButtonPressed:
			break;

		default:
			break;
		}
	}
}


void PlayingState::update(double dt) {
}


void PlayingState::draw(Window &window) const {
	for (auto* object : m_objects)
		object->draw(window);
}





void ObjectsLoader::loadFromFile(const std::string & filename) {
	std::fstream file_stream{ filename, std::ios_base::in };
	if (file_stream.is_open()) {
		std::string line;
		while (std::getline(file_stream, line))
			parse_object_line(line);
		file_stream.close();
		if (m_state == State::Pending) 
			m_state = State::Success;
		std::sort(m_objects.begin(), m_objects.end(), [](auto obj1, auto obj2) { return obj1->getPriority() < obj2->getPriority(); });
	} else {
		m_state = State::InvalidFileName;
	}
}

std::vector<Object*> ObjectsLoader::getObjects()
{
	if (m_state == State::Success)
		return m_objects;
	return {};
}

void ObjectsLoader::parse_object_line(const std::string& line) {
	std::istringstream stream{ line };
	std::string object_id;
	float x, y, width, height, priority;
	stream >> object_id >> x >> y >> width >> height >> priority;
	if (stream.fail())
		m_state = State::ParseError;

	try {
		m_objects.push_back(ObjectFactory::create(object_id, x, y, width, height, priority));
	}
	catch (std::runtime_error& e) {
		m_state = State::UnknownObject;
	}
}
