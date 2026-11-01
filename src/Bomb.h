#pragma once
#include "BaseComponent.h"
#include "GameObject.h"

class Bomb : public GMSCD::BaseComponent
{
public:
	Bomb(GMSCD::GameObject* go);
	~Bomb();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;
};

