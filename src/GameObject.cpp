#include "GameObject.h"
#include <iostream>
#include "GameObjectCollection.h"
#include "Transform.h"

namespace GMSCD
{
	GameObject* GameObject::create(const std::string& name, Vector2 pos)
	{
		std::string finalName = name;

		//if duplicate name rename to match dupe count
		int n = 1;
		while (GameObjectCollection::find(finalName) != nullptr)
		{
			finalName = name + std::to_string(n++);;
		}

		GameObject* go = new GameObject(finalName);
		Transform* transform = go->addComponent<Transform>();
		transform->setPosition(pos);
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

		//move to here so i can loop safely because i want some components to be able to add components to the game obj on awake or start
		componentsToInit.swap(componentsJustAdded);

		for (BaseComponent* component : componentsToInit)
		{
			component->awake();
		}
	}

	void GameObject::runComponentStart()
	{
		if (componentsToInit.empty()) return;

		for (BaseComponent* component : componentsToInit)
		{
			component->start();
		}

		componentsToInit.clear();
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