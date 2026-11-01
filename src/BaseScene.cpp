#include "BaseScene.h"
#include "GameObjectCollection.h"
#include "TextureAllocator.h"

using namespace GMSCD;

// NOTE: For gameObject related calls, use GameObjectCollection!

// Called first when changed to this scene.
void BaseScene::initialize()
{
	// 1. Call initialize callback
	onInitialize();
}

// Called second when changed to this scene.
void BaseScene::activate()
{
	// 1. Call the relevant virtual function callback
	onActivate();
}

// Called before changing to different scene.
void BaseScene::deactivate()
{
	// 1. Dispose all gameObjects
	GameObjectCollection::dispose();

	// 2. Call the relevant virtual function callback
	onDeactivate();
}

void BaseScene::update(float deltaTime)
{
	// 1. Update all gameObjects
	GameObjectCollection::update(deltaTime);

	// 2. Call the relevant virtual function callback
	onUpdate(deltaTime);
}

void BaseScene::render()
{
	// 1. Render all gameObjects
	GameObjectCollection::render();

	// 2. Call the relevant virtual function callback
	onRender();
}