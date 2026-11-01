#pragma once
#include "BaseComponent.h"
#include "GameObject.h"

class Explosion : public GMSCD::BaseComponent
{
public:
	Explosion(GMSCD::GameObject* go);
	~Explosion();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;
};

