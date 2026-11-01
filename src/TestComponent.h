#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "GMSCDMath.h"

class TestComponent : public GMSCD::BaseComponent
{
	TestComponent(GMSCD::GameObject* go);
	~TestComponent();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;
};

