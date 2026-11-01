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

Matrix4x4 Transform::getTransformMatrix() const
{
	return Matrix4x4::TRS(
		Vector3(position.x, position.y, 0.0f),
		rotation,
		Vector3(0.0f, 0.0f, 1.0f),
		Vector3(scale.x, scale.y, 1.0f)
	);
}