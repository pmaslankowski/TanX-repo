#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include <Commons/GameState.h>
#include <Commons/Object.h>
#include <Commons/TextureManager.h>


using Window = sf::RenderWindow;

class PlayingState : public GameState {
public:
	PlayingState(const std::string& level_filename);
	~PlayingState();

	void loadSprites(TextureManager& textureManager);
	void handleInput(Window& window);
	void update(double dt);
	void draw(Window& window) const;

private:
	TextureManager* m_texture_manager;
	std::vector<Object*> m_objects;
};



/* ObjectLoader - loads objects to PlayingState from file
   Level file format: each object is described in one line, which looks like:
   object_id x y width height
   
   Example: (from file test.level):
   Tree1 0 0 100 100
   Tree1 120 120 100 100
   Tree1 300 400 150 150

   Usage:
   ObjectsLoader loader;
   loader.getFromFile(filename);
   objects = loader.getObjects();

   If there was an error during loading, then getObjects() method returns empty vector.
   To check if there was any errors, use getState() method. 
 */
class ObjectsLoader {
public:
	enum class State { Success = 0, Pending, InvalidFileName, ParseError, UnknownObject };

	void loadFromFile(const std::string& filename);
	std::vector<Object*> getObjects();
	State getState() const { return m_state; }

private:
	void parse_object_line(const std::string& line);
	std::vector<Object*> m_objects;
	State m_state = State::Pending;
};