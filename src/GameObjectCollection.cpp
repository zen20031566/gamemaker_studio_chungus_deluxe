#include "GameObjectCollection.h"
#include <iostream>

namespace GMSCD
{
	std::unordered_set<GameObject*> GameObjectCollection::gameObjects;
	std::unordered_set<GameObject*> GameObjectCollection::gameObjectsToAdd;

	void GameObjectCollection::add(GameObject* go)
	{
		gameObjectsToAdd.insert(go);
		gameObjects.insert(go);
	}

	void GameObjectCollection::update(float deltaTime)
	{
		// 1. Remove any gameObject in gameObjects array that are flagged for removal
		for (auto it = gameObjects.begin(); it != gameObjects.end();)
		{
			GameObject* go = *it;
			if (go->shouldDestroy())
			{
				delete go;
				it = gameObjects.erase(it);
			}
			else
			{
				++it;
			}
		}

		//Only if there are new objects
		if (!gameObjectsToAdd.empty())
		{
			// 2. For all element in gameObjectsToAdd, run its awake fn
			for (GameObject* go : gameObjectsToAdd)
			{
				go->runComponentAwake();
			}

			// 3. For all element in gameObjectsToAdd, run its start fn
			for (GameObject* go : gameObjectsToAdd)
			{
				go->runComponentStart();
			}

			// 4. clear gameObjectsToAdd
			gameObjectsToAdd.clear();
		}

		// 5. For all element in gameObjects, run its update(deltaTime) fn
		for (GameObject* go : gameObjects)
		{
			go->runComponentUpdate(deltaTime);
		}
	}

	void GameObjectCollection::render()
	{
		// For all element in gameObjects, run its render() fn
		for (GameObject* go : gameObjects)
		{
			go->runComponentRender();
		}
	}

	// This function is to be called when the current scene is being deactivated or destroyed.
	// With SceneStateMachine:
	// - current scene is deactivated before changing to a different scene.
	void GameObjectCollection::dispose()
	{
		// delete all element in gameObjects
		for (GameObject* go : gameObjects)
		{
			delete go;
		}

		// clear gameObjects array
		gameObjects.clear();

		// clear gameObjectsToAdd array
		gameObjectsToAdd.clear();
	}

	GameObject* GameObjectCollection::find(std::string name)
	{
		// Find the first game object that matches the name and return it.
		for (GameObject* go : gameObjects)
		{
			if (go->getName() == name) return go;
		}
		return nullptr;
	}

	void GameObjectCollection::printAll()
	{
		std::cout << "GameObjects (" << gameObjects.size() << "):" << std::endl;
		for (GameObject* go : gameObjects)
		{
			std::cout << "  " << go->getName();
			if (go->shouldDestroy()) std::cout << " [flagged for deletion]";
			std::cout << std::endl;
		}
	}
}