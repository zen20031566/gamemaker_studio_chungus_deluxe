#include "Transform.h"

using namespace GMSCD;

Transform::Transform(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [Transform] component created" << std::endl;
}

Transform::~Transform()
{
	std::cout << gameObject->getName().c_str() << ": [Transform] component destroyed" << std::endl;
}

Vector2 Transform::getPosition() const
{
	return position;
}

float Transform::getRotation() const
{
	return rotation;
}

Vector2 Transform::getScale() const
{
	return scale;
}

void Transform::setPosition(Vector2 value)
{
	position = value;
}

void Transform::setRotation(float value)
{
	rotation = value;
}

void Transform::setScale(Vector2 value)
{
	scale = value;
}
