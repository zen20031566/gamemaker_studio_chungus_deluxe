#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Texture2D.h"

class SpriteRenderer : public GMSCD::BaseComponent
{
public:
	SpriteRenderer(GMSCD::GameObject* go);
	~SpriteRenderer();

	void awake() override;
	void start() override;
	void update(float deltaTime) override;
	void render() override;

private:
	GMSCD::Mesh* mesh;
	GMSCD::Texture2D* texture;
};