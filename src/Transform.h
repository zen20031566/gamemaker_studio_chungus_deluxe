#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Vector2.h"

class Transform : public GMSCD::BaseComponent
{
public:
	Transform(GMSCD::GameObject* go);
	~Transform();

	GMSCD::Vector2 getPosition() const;
	float getRotation() const;
	GMSCD::Vector2 getScale() const;

	void setPosition(GMSCD::Vector2 value);
	void setRotation(float value);
	void setScale(GMSCD::Vector2 value);

	static constexpr bool disallowMultipleInstance = true;

private:
	GMSCD::Vector2 position = GMSCD::Vector2::zero;
	float rotation = 0.0f;
	GMSCD::Vector2 scale = GMSCD::Vector2::one;
	
};