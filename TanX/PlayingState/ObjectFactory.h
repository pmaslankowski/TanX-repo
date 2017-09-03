#pragma once

#include <string>
#include <map>

/* ObjectFactory for creating different object by their id. 
   Usage: 
   
   Object* my_object = ObjectFactory::create("RedTank", 10, 10, 200, 200);
   
   Registering object in factory:
   static bool ObjectID_registered = 
		ObjectFactory::register_object("ObjectID", [](int x, int y, int width, int height) {
			// create new object here
			return pointer_to_new_object;
		});

	Alternatively you can use one of predefined macros:
	
	REGISTER_OBJECT(Tank, "Tank"); // if Tank has constructor Tank(int x, int y, int width, int height)
	
	or:
	
	REGISTER_OBJECT_WITH_LAMBDA(Tank, "Tank", [](int x, int y, int width, int height) {
		return new Tank(x, y, width, height, "red"); // Tank doesn't have constructor taking 4 arguments,
		                                             // so we have to create this object in lambda
		});
*/

class Object;

class ObjectFactory final {
	typedef Object* (*CreateFunctionPtr)(int, int, int, int);
public:
	static Object* create(const std::string& id, int x, int y, int width, int height);
	static bool register_object(const std::string& id, CreateFunctionPtr create);
	static void unregister_object(const std::string& id);

private:
	static ObjectFactory& instance();

	ObjectFactory() = default;

	std::map<std::string, CreateFunctionPtr> registered_objects;
};