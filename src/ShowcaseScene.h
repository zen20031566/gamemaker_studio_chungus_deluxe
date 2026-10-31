#pragma once
#include "SceneStateMachine.h"

class ShowcaseScene : public GMSCD::BaseScene
{
public:
	std::string getName() const override { return "ShowcaseScene"; }

protected:
	void onInitialize() override;
	void onActivate() override;
	void onDeactivate() override;
	void onUpdate(float deltaTime) override;
	void onRender() override;
};

