#pragma once
#include "GMSCDComponents.h"
#include "GMSCDMath.h"

class Bullet : public GMSCD::BaseComponent
{
public:
	Bullet(GMSCD::GameObject* go);
	~Bullet();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;

	void setDir(GMSCD::Vector2 dir);

private:
	Transform* transform;
	SpriteRenderer* spriteRenderer;
	float moveSpeed;
	GMSCD::Vector2 moveDir;
	bool initialized = false;
};

