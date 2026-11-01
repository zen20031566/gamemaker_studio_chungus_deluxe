#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "GMSCDMath.h"

class Explosion : public GMSCD::BaseComponent
{
public:
	Explosion(GMSCD::GameObject* go);
	~Explosion();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;

private:
	Transform* transform;
	SpriteRenderer* spriteRenderer;
	float lifeTime = 0.0f;
};

