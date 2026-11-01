#include "ShowcaseScene.h"    
#include "GameMakerStudioChungusDeluxe.h"

using namespace GMSCD;

void ShowcaseScene::onInitialize()
{
	TextureConfig cfg = { TextureWrapMode::REPEAT, TextureWrapMode::REPEAT, TextureFilterMode::LINEAR };
	Texture2D* grassTex = TextureAllocator::getTexture("../assets/grass.png");
	grassTex->setConfig(cfg);

	//bg
	GameObject* bg = GameObject::create("bg");
	Transform* bgTransform = bg->getComponent<Transform>();
	bgTransform->setScale(Vector2::one * 1000);
	SpriteRenderer* spriteRenderer = bg->addComponent<SpriteRenderer>();
	spriteRenderer->setTexture(grassTex);
	spriteRenderer->setTiling(Vector2(200.0f, 200.0f));

	//player
	GameObject* player = GameObject::create("player");
	player->addComponent<Player>();

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


