#include "Explosion.h"
#include "TextureAllocator.h"

using namespace GMSCD;

Explosion::Explosion(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [Explosion] component created" << std::endl;
}
Explosion::~Explosion()
{
	std::cout << gameObject->getName().c_str() << ": [Explosion] component destroyed" << std::endl;
}

void Explosion::awake()
{
	transform = gameObject->getComponent<Transform>();
	spriteRenderer = gameObject->addComponent<SpriteRenderer>();
}

void Explosion::start()
{
	TextureConfig cfg = { TextureWrapMode::CLAMP, TextureWrapMode::CLAMP, TextureFilterMode::LINEAR };
	Texture2D* explosionTex = TextureAllocator::getTexture("../assets/explosion.png");
	explosionTex->setConfig(cfg);

	spriteRenderer->setTexture(explosionTex);
	transform->setScale(Vector2(0.3f, 0.3f));
}

void Explosion::update(float deltaTime)
{
	lifeTime += deltaTime;

	if (lifeTime >= 1.0f)
	{
		gameObject->destroy();
	}
}

void Explosion::render()
{

}