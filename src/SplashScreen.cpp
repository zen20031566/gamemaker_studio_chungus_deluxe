#include "SplashScreen.h"
#include "GameMakerStudioChungusDeluxe.h"

using namespace GMSCD;

void SplashScreen::onInitialize()
{
	lifeTime = 0.0f;
	alpha = 0.0f;
	fadeDuration = 0.5f;
	fadeTimer = 0.0f;
	fadeout = false;
	startDelay = 1.0f;

	TextureConfig cfg = { TextureWrapMode::CLAMP, TextureWrapMode::CLAMP, TextureFilterMode::LINEAR };

	//logo
	logoTex = TextureAllocator::getTexture("../assets/logo.jpg");
	logoTex->setConfig(cfg);

	GameObject* logo = GameObject::create("logo");
	logoSpriteRenderer = logo->addComponent<SpriteRenderer>();
	logoSpriteRenderer->setTexture(logoTex);
	logoSpriteRenderer->setTint(Vector4(1.0f, 1.0f, 1.0f, alpha));
	Transform* logoTransform = logo->getComponent<Transform>();
	logoTransform->setScale(Vector2(2.0f, 1.0f));
	logoTransform->setPosition(Vector2(0.0f, 0.2f));



	infoTex = TextureAllocator::getTexture("../assets/studentinfo.jpg");
	infoTex->setConfig(cfg);
	GameObject* info = GameObject::create("info");
	infoSpriteRenderer = info->addComponent<SpriteRenderer>();
	infoSpriteRenderer->setTexture(infoTex);
	infoSpriteRenderer->setTint(Vector4(1.0f, 1.0f, 1.0f, alpha));
	Transform* infoTransform = info->getComponent<Transform>();
	infoTransform->setScale(Vector2(2.0f, 1.0f) * 0.3f);
	infoTransform->setPosition(Vector2(0.0f, -0.5f));
}

void SplashScreen::onActivate()
{

}

void SplashScreen::onDeactivate()
{

}

void SplashScreen::onUpdate(float deltaTime)
{
	lifeTime += deltaTime;
	if (lifeTime <= startDelay) return;

	fadeTimer += deltaTime;

	if (!fadeout)
	{
		//fade in
		alpha = Mathf::lerp(0.0f, 1.0f, Mathf::clamp01(fadeTimer / fadeDuration));

		if (lifeTime >= 3.0f + startDelay || Input::getKeyDown(KeyCode::SPACE))
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
			//switch screen after fade out
			SceneStateMachine::loadScene("ShowcaseScene");
		}
	}

	logoSpriteRenderer->setTint(Vector4(1.0, 1.0, 1.0, alpha));
	infoSpriteRenderer->setTint(Vector4(1.0, 1.0, 1.0, alpha));
}

void SplashScreen::onRender()
{

}