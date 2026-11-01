#include "Bullet.h"
#include "TextureAllocator.h"
#include "Camera.h"

using namespace GMSCD;

Bullet::Bullet(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [Bullet] component created" << std::endl;
}
Bullet::~Bullet()
{
	std::cout << gameObject->getName().c_str() << ": [Bullet] component destroyed" << std::endl;
}

void Bullet::awake()
{
	transform = gameObject->getComponent<Transform>();
	spriteRenderer = gameObject->addComponent<SpriteRenderer>();
}

void Bullet::start()
{
	TextureConfig cfg = { TextureWrapMode::CLAMP, TextureWrapMode::CLAMP, TextureFilterMode::LINEAR };
	Texture2D* bulletTex = TextureAllocator::getTexture("../assets/bullet.png");
	bulletTex->setConfig(cfg);

	spriteRenderer->setTexture(bulletTex);

	transform->setScale(Vector2(0.3f, 0.3f));
	moveSpeed = 2.0f;

	initialized = true;
}

void Bullet::setDir(Vector2 dir)
{
	moveDir = dir;
	moveDir = moveDir.normalized();
}

void Bullet::update(float deltaTime)
{
	if (!initialized) return;

	Vector2 pos = transform->getPosition();
	pos += moveDir * moveSpeed * deltaTime;

	transform->setPosition(pos);

	if (!Camera::isPointVisible(pos, 1.0f))
	{
		gameObject->destroy();
		return;
	}
}

void Bullet::render()
{

}
