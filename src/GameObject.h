#pragma once 
#include <vector>
#include <string>
#include "BaseComponent.h" 
#include <iostream>
#include "GMSCDMath.h"

namespace GMSCD
{ 
	class GameObject
	{
	public:
		static GameObject* create(const std::string& name = "New GameObject", Vector2 pos = Vector2::zero);
		~GameObject();

		template <
			typename T, 
			typename = typename std::enable_if<std::is_base_of<BaseComponent, T>::value>::type>
		
		T* addComponent() 
		{
			if (T::disallowMultipleInstance)
			{
				if (T* existing = getComponent<T>())
				{
					std::cout << name << ": [" << typeid(T).name() << "] disallow multiple instances and already exists failed to add component" << std::endl;
					return existing;
				}
			}

			// Create instance of T, expecting that T has a constructor that takes GameObject* 
			T* newComponent = new T(this);

			// Add the instance of T to componentsToAdd 
			componentsJustAdded.push_back(newComponent);

			// Also add it to components 
			components.push_back(newComponent);
			return newComponent;
		}

		template <
			typename T,
			typename = typename std::enable_if<std::is_base_of<BaseComponent, T>::value>::type>

		T* getComponent() 
		{
			// iterate the vector to find component that matches 
			// the type. 
			for (BaseComponent* component : components)
			{
				// find component that matches the type. 
				// return the first item found. 
				T* tryCast = dynamic_cast<T*>(component);
				if (tryCast != nullptr) 
				{
					return tryCast;
				}
			}
			// if nothing found, return null (0) 
			return nullptr;
		}

		template <
			typename T,
			typename = typename std::enable_if<std::is_base_of<BaseComponent, T>::value>::type>

		bool removeComponent()
		{
			T* component = getComponent<T>();
			if (component == nullptr) return false;

			// Remove from componentsJustAdded
			auto it = std::find(componentsJustAdded.begin(), componentsJustAdded.end(),component);
			if (it != componentsJustAdded.end()) componentsJustAdded.erase(it);

			// Remove from componentsToInit
			it = std::find(componentsToInit.begin(), componentsToInit.end(), component);
			if (it != componentsToInit.end()) componentsToInit.erase(it);

			// Remove from components
			it = std::find(components.begin(), components.end(), component);

			if (it != components.end())
			{
				components.erase(it);
				delete component;
				return true;
			}

			return false;
		}

		void runComponentAwake();
		void runComponentStart();
		void runComponentUpdate(float deltaTime);
		void runComponentRender();

		std::string getName() const;
		void setName(std::string value);
	
		void destroy();
		bool shouldDestroy() const;

	protected:
		std::string name;

	private:
		GameObject();
		GameObject(std::string name);

		std::vector<BaseComponent*> components;
		std::vector<BaseComponent*> componentsJustAdded;
		std::vector<BaseComponent*> componentsToInit;
		bool flaggedForDeletion = false;
	};
}