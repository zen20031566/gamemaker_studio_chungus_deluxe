#include "GameObject.h"
#include <iostream>
#include "GameObjectCollection.h"
#include "Transform.h"

namespace GMSCD
{
	GameObject* GameObject::create(const std::string& name)
	{
		std::string finalName = name;

		//if duplicate name rename to match dupe count
		int n = 1;
		while (GameObjectCollection::find(finalName) != nullptr)
		{
			finalName = name + std::to_string(n++);;
		}

		GameObject* go = new GameObject(finalName);
		go->addComponent<Transform>();
		GameObjectCollection::add(go);
		return go;
	}

	GameObject::GameObject(std::string name)
	{
		this->name = name;
	}

	GameObject::~GameObject()
	{
		for (BaseComponent* component : components)
		{
			delete component;
		}
		std::cout << GameObject::getName() << " deleted" << std::endl;
	}

	void GameObject::runComponentAwake()
	{
		if (componentsJustAdded.empty()) return;

		for (BaseComponent* newComponent : componentsJustAdded)
		{
			newComponent->awake();
		}
	}

	void GameObject::runComponentStart()
	{
		if (componentsJustAdded.empty()) return;

		for (BaseComponent* newComponent : componentsJustAdded)
		{
			newComponent->start();
		}

		componentsJustAdded.clear();	
	}

	void GameObject::runComponentUpdate(float deltaTime)
	{
		for (int i = components.size() - 1; i >= 0; i--)
		{
			BaseComponent* component = components[i];
			if (component->shouldDestroy())
			{
				components.erase(components.begin() + i);
				delete component;
			}
		}

		for (BaseComponent* component : components)
		{
			component->update(deltaTime);
		}
	}

	void GameObject::runComponentRender()
	{
		for (BaseComponent* component : components)
		{
			component->render();
		}
	}

	std::string GameObject::getName() const
	{
		return name;
	}

	void GameObject::setName(std::string value)
	{
		name = value;
	}

	void GameObject::destroy()
	{
		flaggedForDeletion = true;
	}

	bool GameObject::shouldDestroy() const
	{
		return flaggedForDeletion;
	}
}