#include "TestComponent.h"

using namespace GMSCD;

TestComponent::TestComponent(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [TestComponent] component created" << std::endl;
}
TestComponent::~TestComponent()
{
	std::cout << gameObject->getName().c_str() << ": [TestComponent] component destroyed" << std::endl;
}

void TestComponent::awake()
{

}

void TestComponent::start()
{

}

void TestComponent::update(float deltaTime)
{

}

void TestComponent::render()
{

}