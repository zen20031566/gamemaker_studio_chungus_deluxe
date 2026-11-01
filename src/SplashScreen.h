#pragma once
#include "SceneStateMachine.h"
#include "SpriteRenderer.h"
#include "TextureUtils.h"
#include "Texture2D.h"

class SplashScreen : public GMSCD::BaseScene
{
public:
	std::string getName() const override { return "SplashScreen"; }

protected:
	void onInitialize() override;
	void onActivate() override;
	void onDeactivate() override;
	void onUpdate(float deltaTime) override;
	void onRender() override;

private:
	float lifetime = 0.0f;
	float alpha;
	float fadeDuration;
	float fadeTimer;
	bool fadeout;
	SpriteRenderer* logoSpriteRenderer;
	float startDelay;
	GMSCD::Texture2D* logoTex;
};

