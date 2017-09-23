#pragma once

#include <map>
#include <type_traits>
#include <typeindex>
#include <functional>


/* This is hardcore template-hacking code, but it has to look like this, because of lack of 
   double dispatch support in C++. 

   This class shouldn't be used outside CollisionDetector class.

   Usage of this class. If you want to register new type of collision, you should use REGISTER_COLLISION macro.
   Collision callback has to be function of type: void(CollisionDetector&,SomeObject1*,SomeObject2*). For example:

   void collision_tree_tank(CollisionDetector& detector, Tree* tree, Tank* tank) {
		// logic performing tank and tree colision
   }
   REGISTER_COLLISION(collision_tree_tank);

   If you want to perform collision of two objects you should call dispatch method. For example:
   Tree tree1;
   Tank tank1;
   CollisionDetector detector;
   CollisionDispatcher::instance().dispatch(detector, tree1, tank1);

   You can treat this code like working blackbox.
*/


class Object;
class CollisionDetector;


class CollisionDispatcher final {
	using KeyType = std::pair<std::type_index, std::type_index>;
	using BaseCallbackType = std::function<void(CollisionDetector&, Object*, Object*)>;

public:
	template< typename Lhs, typename Rhs >
	auto registerCollision(void (*callback)(CollisionDetector&, Lhs*, Rhs*)) -> std::enable_if_t<std::is_base_of<Object, Lhs>::value && std::is_base_of<Object, Rhs>::value, bool> { 
		BaseCallbackType thunk = [callback](CollisionDetector& detector, Object* lhs, Object* rhs) { 
			callback(detector, static_cast<Lhs*>(lhs), static_cast<Rhs*>(rhs)); 
		};
		KeyType key{ typeid(Lhs), typeid(Rhs) };
		auto& it = dispatchMap.find(key);
		if (it != dispatchMap.end()) {
			char msg[128];
			sprintf(msg, "Collision callback for types: %s and %s already registered.", key.first.name(), key.second.name());
			throw std::runtime_error(msg);
		}
		dispatchMap[key] = thunk;
		return true;
	}

	template< typename Lhs, typename Rhs >
	auto registerCollision(void (*callback)(CollisionDetector&, Lhs*, Rhs*)) -> std::enable_if_t<!(std::is_base_of<Object, Lhs>::value && std::is_base_of<Object, Rhs>::value), bool> {
		static_assert(false, "Lhs and Rhs in CollisionDispatcher should be Objects.");
		return false;
	}

	template< typename Lhs, typename Rhs >
	void dispatch(CollisionDetector& detector, Lhs* lhs, Rhs* rhs) {
		KeyType key{ typeid(lhs), typeid(rhs) };
		auto& it = dispatchMap.find(key);
		if (it == dispatchMap.end()) {
			char msg[128];
			sprintf(msg, "Collision callback for types: %s and %s not found.", key.first.name(), key.second.name());
			throw std::runtime_error(msg);
		}
		it->second(detector, lhs, rhs);
	}

	static CollisionDispatcher& instance() { static CollisionDispatcher instance{}; return instance; }
	
private:
	CollisionDispatcher() = default;

private:
	std::map<KeyType, BaseCallbackType> dispatchMap;
};


#define REGISTER_COLLISION(CALLBACK) static bool __COUNTER__##registered_in_collision_dispatcher = \
	CollisionDispatcher::instance().registerCollision((CALLBACK));

