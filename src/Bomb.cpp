#include "Bomb.h"
#include "TextureAllocator.h"
#include "Explosion.h"

using namespace GMSCD;

Bomb::Bomb(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [Bomb] component created" << std::endl;
}
Bomb::~Bomb()
{
	std::cout << gameObject->getName().c_str() << ": [Bomb] component destroyed" << std::endl;
}

void Bomb::awake()
{
	transform = gameObject->getComponent<Transform>();
	spriteRenderer = gameObject->addComponent<SpriteRenderer>();
}

void Bomb::start()
{
	TextureConfig cfg = { TextureWrapMode::CLAMP, TextureWrapMode::CLAMP, TextureFilterMode::LINEAR };
	Texture2D* bombTex = TextureAllocator::getTexture("../assets/bomb.png");
	bombTex->setConfig(cfg);

	spriteRenderer->setTexture(bombTex);
	transform->setScale(Vector2(0.3f, 0.3f));
}

void Bomb::update(float deltaTime)
{
	lifeTime += deltaTime;

	if (lifeTime >= 2.0f)
	{
		GameObject* explosionObj = GameObject::create("explosion", transform->getPosition());
		explosionObj->addComponent<Explosion>();
		gameObject->destroy();
	}
}

void Bomb::render()
{

}