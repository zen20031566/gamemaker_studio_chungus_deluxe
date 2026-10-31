#include "SceneStateMachine.h"
#include "GameObjectCollection.h"

namespace GMSCD
{
	std::unordered_map<std::string, BaseScene*> SceneStateMachine::scenes;
	BaseScene* SceneStateMachine::currentScene;
	unsigned int SceneStateMachine::sceneIdCounter;
	std::vector<BaseScene*> SceneStateMachine::sceneList;

	void SceneStateMachine::loadScene(const std::string name)
	{
		// 1. Look for the scene matching the name
		// 2. If found:
		//    a. Deactivate currentScene, if there is one (Note: there won't be one on launch!)
		//    b. Dispose all currently active gameObjects.
		//    b. Point currentScene to the new scene.
		//    c. Initialize and activate the new scene.
		// 3. Otherwise, log error

		auto it = scenes.find(name);
		if (it != scenes.end())
		{
			if (currentScene != nullptr) currentScene->deactivate();
			GameObjectCollection::dispose();
			BaseScene* newScene = it->second;
			currentScene = newScene;
			currentScene->initialize();
			currentScene->activate();
		}
		else
		{
			std::cout << "Failed to load scene " << name << ", scene not found" << std::endl;
		}
	}

	void SceneStateMachine::update(float deltaTime)
	{
		// Update current scene if there is one.
		if (currentScene != nullptr) currentScene->update(deltaTime);
	}

	void SceneStateMachine::render()
	{
		// Render current scene if there is one.
		if (currentScene != nullptr) currentScene->render();
	}

	void SceneStateMachine::dispose()
	{
		// Dispose all currently active gameObjects.
		GameObjectCollection::dispose();

		// For each element in scenes
		for (auto kvp : scenes)
		{
			// Delete the element
			delete kvp.second;
		}

		// Clear the collection
		scenes.clear();
		sceneList.clear();

		// Reset sceneIdCounter
		sceneIdCounter = 0;

		// set currentScene to nullptr for safety.
		currentScene = nullptr;
	}

	void SceneStateMachine::loadScene(const unsigned int index)
	{
		if (index >= sceneList.size())
		{
			std::cout << "Failed to load scene at index " << index << ", out of range" << std::endl;
			return;
		}
		loadScene(sceneList[index]->getName());
	}

	BaseScene* SceneStateMachine::getCurrentScene()
	{
		return currentScene;
	}
}