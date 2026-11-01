#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "GMSCDMath.h"

class Bomb : public GMSCD::BaseComponent
{
public:
	Bomb(GMSCD::GameObject* go);
	~Bomb();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;

private:
	Transform* transform;
	SpriteRenderer* spriteRenderer;
	float lifeTime = 0.0f;
};

