#pragma once

#include <string>
#include <map>

class Object;

class ObjectFactory final {
	typedef Object* (*CreateFunctionPtr)(int, int, int, int);
public:
	static Object* create(const std::string& id, int x, int y, int width, int height);
	static void register_object(const std::string& id, CreateFunctionPtr create);
	static void unregister_object(const std::string& id);

private:
	static ObjectFactory& instance();

	ObjectFactory() = default;

	std::map<std::string, CreateFunctionPtr> registered_objects;
};

#define REGISTER_OBJECT_IN_FACTORY(id, T_obj) ObjectFactory::register_object(id, \
	[](auto x, auto y, auto width, auto height) -> Object* { \
		return new T_obj(x, y, width, height); \
	})