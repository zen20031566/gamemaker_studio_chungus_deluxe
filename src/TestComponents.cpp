#include "TestComponents.h"
#include <glad/glad.h>
#include <iostream>

FooComponent::FooComponent(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [FooComponent] created" << std::endl;
}

FooComponent::~FooComponent()
{
	std::cout << gameObject->getName().c_str() << ": [FooComponent] destroyed" << std::endl;
}

void FooComponent::update(float deltaTime)
{
	lifeTime += deltaTime;

	if (!invoked && lifeTime >= 6.0f)
	{
		std::cout << gameObject->getName().c_str() << ": [FooComponent] I am still here by the way!" << std::endl;
		std::cout << gameObject->getName().c_str() << ": [FooComponent] adding [QuadRenderComponent] to self" << std::endl;

		auto qrc = gameObject->addComponent <QuadRenderComponent>();
		qrc->setColour(0.0f, 1.0f, 0.0f);

		invoked = true;
	}
}

RotateComponent::RotateComponent(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [RotateComponent] created" << std::endl;
}

RotateComponent::~RotateComponent()
{
	std::cout << gameObject->getName().c_str() << ": [RotateComponent] destroyed" << std::endl;
}

void RotateComponent::update(float deltaTime)
{
	lifeTime += deltaTime;
	gameObject->setRotation(lifeTime * 20.0f);

	if (lifeTime >= 2.0f)
	{
		std::cout << gameObject->getName().c_str() << ": [RotateComponent] 2 seconds has passed since creation, change colour and destroy self" << std::endl;

		auto qrc = gameObject->getComponent <QuadRenderComponent>();
		qrc->setColour(1.0f, 0.0f, 0.0f);

		destroy();
	}
}

QuadRenderComponent::QuadRenderComponent(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [QuadRenderComponent] created" << std::endl;
}

QuadRenderComponent::~QuadRenderComponent()
{
	std::cout << gameObject->getName().c_str() << ": [QuadRenderComponent] destroyed" << std::endl;
}

void QuadRenderComponent::awake()
{
	r = 0.0f; g = b = 1.0f;
}

void QuadRenderComponent::render()
{
	glm::vec2 pos = gameObject->getPosition();
	float rot = gameObject->getRotation();

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0.0f, 0.0f, 1.0f);

	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(0.5, 0.5, 0);
	glEnd();

	glPopMatrix();
}

void QuadRenderComponent::setColour(float nr, float ng, float nb)
{
	r = nr; g = ng; b = nb;
	std::cout << gameObject->getName().c_str() << ": [QuadRenderComponent] change colour to (" 
		<< r << ", "<< g << ", " << b << ")" << std::endl;
}

DelayedDestroyComponent::DelayedDestroyComponent(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [DelayedDestroyComponent] created" << std::endl;

}

DelayedDestroyComponent::~DelayedDestroyComponent()
{
	std::cout << gameObject->getName().c_str() << ": [DelayedDestroyComponent] destroyed" << std::endl;

}

void DelayedDestroyComponent::update(float deltaTime)
{
	lifeTime += deltaTime;

	if (lifeTime >= 4.0f)
	{
		std::cout << gameObject->getName().c_str() << ": [DelayedDestroyComponent] 4 seconds has passed since creation, destroy owner" << std::endl;
		gameObject->destroy();
	}
}
