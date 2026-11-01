#include "Bullet.h"

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

}

void Bullet::start()
{

}

void Bullet::update(float deltaTime)
{

}

void Bullet::render()
{

}