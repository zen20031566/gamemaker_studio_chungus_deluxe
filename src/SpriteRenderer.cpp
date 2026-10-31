#include "SpriteRenderer.h"
#include "Graphics.h"
#include "Transform.h"
#include "Vector2.h"

using namespace GMSCD;

SpriteRenderer::SpriteRenderer(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [SpriteRenderer] component created" << std::endl;
}

SpriteRenderer::~SpriteRenderer()
{
	std::cout << gameObject->getName().c_str() << ": [SpriteRenderer] component destroyed" << std::endl;
}

void SpriteRenderer::awake()
{
	std::vector<Vertex> vertices;

	vertices.push_back(Vertex({ -0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f }));
	vertices.push_back(Vertex({ -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f }));
	vertices.push_back(Vertex({ 0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f }));

	vertices.push_back(Vertex({ 0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f }));
	vertices.push_back(Vertex({ 0.5f, 0.5f, 0.0f }, { 1.0f, 1.0f }));
	vertices.push_back(Vertex({ -0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f }));

	TextureConfig cfg = { TextureWrapMode::REPEAT, TextureWrapMode::REPEAT, TextureFilterMode::LINEAR };

	mesh = new Mesh(vertices);
	texture = new Texture2D("../assets/eexuan_texture.png", cfg);
}

void SpriteRenderer::start()
{

}

void SpriteRenderer::update(float deltaTime)
{

}

void SpriteRenderer::render()
{
	Transform* transform = gameObject->getComponent<Transform>();
	Vector2 pos = transform->getPosition();
	float rot = transform->getRotation();
	Vector2 scale = transform->getScale();

	RenderParams param{};
	param.tint = { 0.0f, 1.0f, 1.0f, 0.5f };
	param.translation = { pos.x, pos.y, 0.0f };
	param.rotationZ = rot;
	param.scale = { scale.x, scale.y, 1.0f };

	Graphics::drawMesh(mesh, param);
}