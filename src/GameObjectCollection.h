#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include <unordered_set>

namespace GMSCD
{
	// GameObjectCollection is single global-scoped object
	class GameObjectCollection
	{
	public:
		GameObjectCollection() = delete;

		static void add(GameObject* go);
		static void update(float deltaTime);
		static void render();
		static void dispose();

		static GameObject* find(std::string name);

		//debug
		static void printAll();

	private:

		static std::unordered_set<GameObject*> gameObjects;
		static std::unordered_set<GameObject*> gameObjectsToAdd;
	};
}
