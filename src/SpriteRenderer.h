#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "GMSCDMath.h"
#include "Mesh.h"
#include "Texture2D.h"

class SpriteRenderer : public GMSCD::BaseComponent
{
public:
	SpriteRenderer(GMSCD::GameObject* go);
	~SpriteRenderer();

	void render() override;

	void setTexture(GMSCD::Texture2D* t);
	void setTint(GMSCD::Vector4 t);
	void setTiling(GMSCD::Vector2 t);
private:
	GMSCD::Mesh* mesh;
	GMSCD::Texture2D* texture;
	GMSCD::Vector4 tint = GMSCD::Vector4::one;
	GMSCD::Vector2 tiling = GMSCD::Vector2::one;

	void buildMesh();
};