#include "Bomb.h"

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

}

void Bomb::start()
{

}

void Bomb::update(float deltaTime)
{

}

void Bomb::render()
{

}