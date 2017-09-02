#include <string>
#include <map>
#include <exception>
#include "ObjectFactory.h"



Object* ObjectFactory::create(const std::string& id, int x, int y, int width, int height) {
	auto& registered_objects = instance().registered_objects;
	auto it = registered_objects.find(id);
	if (it == registered_objects.end())
		throw std::runtime_error("[ObjectFactory] Attempt to create unregistered object. id: " + id);
	return it->second(x, y, width, height);
}


void ObjectFactory::register_object(const std::string& id, CreateFunctionPtr create) {
	auto& registered_objects = instance().registered_objects;
	if (registered_objects.find(id) != registered_objects.end())
		throw std::runtime_error("[ObjectFactory] Attempt to register already registered object. id: " + id);
	registered_objects[id] = create;
}


void ObjectFactory::unregister_object(const std::string& id) {
	auto& registered_objects = instance().registered_objects;
	auto it = registered_objects.find(id);
	if (it == registered_objects.end())
		throw std::runtime_error("[ObjectFactory] Attempt to unregister not registered object. id: " + id);
	registered_objects.erase(it);
}


ObjectFactory& ObjectFactory::instance() {
	static auto instance = ObjectFactory();
	return instance;
}