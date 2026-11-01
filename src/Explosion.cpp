#include "Explosion.h"

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

}

void Explosion::start()
{

}

void Explosion::update(float deltaTime)
{

}

void Explosion::render()
{

}