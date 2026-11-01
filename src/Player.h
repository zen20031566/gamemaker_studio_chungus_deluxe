#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "GMSCDMath.h"

class Player : public GMSCD::BaseComponent
{
public:
	Player(GMSCD::GameObject* go);
	~Player();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;

private:
	Transform* transform;
	SpriteRenderer* spriteRenderer;
	GMSCD::Texture2D* sprite;
	float moveSpeed;
};

