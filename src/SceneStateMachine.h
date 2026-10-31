#pragma once
#include "BaseScene.h"
#include <unordered_map>
#include <iostream>

namespace GMSCD
{
	class SceneStateMachine
	{
	public:
		SceneStateMachine() = delete; // disallow construction of class instance

		template<
			typename T, 
			typename = typename std::enable_if<std::is_base_of<BaseScene, T>::value>::type>

		static T* addScene() 
		{
			T* newScene = new T();
			std::string sceneName = newScene->getName();
			auto pair = std::make_pair(sceneName, newScene);

			std::pair < 
				std::unordered_map<std::string, BaseScene*>::iterator, 
				bool > 
				result = scenes.insert(pair);

			// result.first = the (std::string + Scene*) pair
			// result.second = whether the insertion is successful or not.
			//   If successful, pair.first will point to the newly inserted pair.
			//   If not successful, pair.first will point to existing pair inside the map.
			// if successfuly adding the new pair

			if (result.second) 
			{
				std::cout << "Scene " << sceneName << " added" << std::endl;

				// For challenge (see below)
				unsigned int currentId = sceneIdCounter;
				sceneIdCounter++;

				sceneList.push_back(newScene);
				return newScene;
			}
			else 
			{
				std::cout << "Scene " << sceneName << " already exists" << std::endl;
				delete newScene;
				return nullptr;
			}
		}

		static void loadScene(const std::string name);
		static void loadScene(const unsigned int index);
		static BaseScene* getCurrentScene();

	private:
		friend class Application;
		static void update(float deltaTime);
		static void render();
		static void dispose();

		static std::unordered_map<std::string, BaseScene*> scenes;
		static std::vector<BaseScene*> sceneList;
		static BaseScene* currentScene;
		static unsigned int sceneIdCounter;
	};
}
