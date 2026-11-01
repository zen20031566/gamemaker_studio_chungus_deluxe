#include "SpriteRenderer.h"
#include "Graphics.h"
#include "Transform.h"
#include "Vector2.h"
#include "TextureUtils.h"
#include "TextureAllocator.h"

using namespace GMSCD;

SpriteRenderer::SpriteRenderer(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [SpriteRenderer] component created" << std::endl;

	std::vector<Vertex> vertices;

	buildMesh();
	texture = TextureUtils::checkerTexture2D();
}

SpriteRenderer::~SpriteRenderer()
{
	std::cout << gameObject->getName().c_str() << ": [SpriteRenderer] component destroyed" << std::endl;
	if (texture != nullptr) TextureAllocator::returnTexture(texture);
	delete mesh;
}

void SpriteRenderer::render()
{
	Transform* transform = gameObject->getComponent<Transform>();
	Vector2 pos = transform->getPosition();
	float rot = transform->getRotation();
	Vector2 scale = transform->getScale();

	RenderParams param{};
	param.texture = texture;
	param.tint = tint;
	param.translation = { pos.x, pos.y, 0.0f };
	param.rotationZ = rot;
	param.scale = { scale.x, scale.y, 1.0f };

	Graphics::drawMesh(mesh, param);
}

void SpriteRenderer::setTexture(Texture2D* t)
{
	if (texture == t) return;
	if (texture != nullptr) TextureAllocator::returnTexture(texture);
	texture = t;
}

void SpriteRenderer::setTint(Vector4 t)
{
	tint = t;
}

void SpriteRenderer::setTiling(Vector2 t)
{
	tiling = t;
	buildMesh();
}

void SpriteRenderer::buildMesh()
{
	std::vector<Vertex> vertices;

	vertices.push_back(Vertex({ -0.5f,  0.5f, 0.0f }, { 0.0f, tiling.y }));
	vertices.push_back(Vertex({ -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f }));
	vertices.push_back(Vertex({ 0.5f, -0.5f, 0.0f }, { tiling.x, 0.0f }));

	vertices.push_back(Vertex({ 0.5f, -0.5f, 0.0f }, { tiling.x, 0.0f }));
	vertices.push_back(Vertex({ 0.5f,  0.5f, 0.0f }, { tiling.x, tiling.y }));
	vertices.push_back(Vertex({ -0.5f,  0.5f, 0.0f }, { 0.0f, tiling.y }));

	delete mesh;                
	mesh = new Mesh(vertices);
}


