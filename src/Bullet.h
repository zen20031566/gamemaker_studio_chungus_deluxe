#pragma once
#include "BaseComponent.h"
#include "GameObject.h"

class Bullet : public GMSCD::BaseComponent
{
public:
	Bullet(GMSCD::GameObject* go);
	~Bullet();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;
};

