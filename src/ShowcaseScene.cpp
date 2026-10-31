#include "ShowcaseScene.h"    
#include "GameMakerStudioChungusDeluxe.h"

using namespace GMSCD;

void ShowcaseScene::onInitialize()
{
	GameObject* go1 = GameObject::create("test");
	go1->addComponent<SpriteRenderer>();
	go1->addComponent<SpriteRenderer>();
	go1->addComponent<Transform>();
	go1->addComponent<Transform>();
}

void ShowcaseScene::onActivate()
{

}

void ShowcaseScene::onDeactivate()
{

}

void ShowcaseScene::onUpdate(float deltaTime)
{

}

void ShowcaseScene::onRender()
{
	
}


