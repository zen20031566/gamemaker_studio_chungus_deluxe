#include "SplashScreen.h"
#include "GameMakerStudioChungusDeluxe.h"

using namespace GMSCD;

void SplashScreen::onInitialize()
{
	lifetime = 0.0f;
	alpha = 0.0f;
	fadeDuration = 0.5f;
	fadeTimer = 0.0f;
	fadeout = false;
	startDelay = 1.0f;

	TextureConfig cfg = { TextureWrapMode::CLAMP, TextureWrapMode::CLAMP, TextureFilterMode::LINEAR };
	logoTex = TextureAllocator::getTexture("../assets/logo.jpg");
	logoTex->setConfig(cfg);

	GameObject* logo = GameObject::create("logo");

	logoSpriteRenderer = logo->addComponent<SpriteRenderer>();
	logoSpriteRenderer->setTexture(logoTex);
	logoSpriteRenderer->setTint(Vector4(1.0f, 1.0f, 1.0f, alpha));
	
	Transform* transform = logo->getComponent<Transform>();
	transform->setScale(Vector2(2.0f, 1.0f));

}

void SplashScreen::onActivate()
{

}

void SplashScreen::onDeactivate()
{
	TextureAllocator::returnTexture(logoTex);
}

void SplashScreen::onUpdate(float deltaTime)
{
	lifetime += deltaTime;
	if (lifetime <= startDelay) return;

	fadeTimer += deltaTime;

	if (!fadeout)
	{
		//fade in
		alpha = Mathf::lerp(0.0f, 1.0f, Mathf::clamp01(fadeTimer / fadeDuration));

		if (lifetime >= 3.0f + startDelay)
		{
			fadeout = true;
			fadeTimer = 0.0f;
		}
	}
	else
	{
		//fade out
		alpha = Mathf::lerp(1.0f, 0.0f, Mathf::clamp01(fadeTimer / fadeDuration));

		if (fadeTimer >= fadeDuration)
		{
			//switch screen after fade oout
			SceneStateMachine::loadScene("ShowcaseScene");
		}
	}

	logoSpriteRenderer->setTint(Vector4(1.0, 1.0, 1.0, alpha));
}

void SplashScreen::onRender()
{

}