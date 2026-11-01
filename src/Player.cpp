#include "Player.h"
#include "GMSCDMath.h"
#include "Input.h"
#include "TextureAllocator.h"
#include "Camera.h"
#include "Bullet.h"
#include "Bomb.h"

using namespace GMSCD;

Player::Player(GameObject* go) : BaseComponent(go)
{
	std::cout << gameObject->getName().c_str() << ": [Player] component created" << std::endl;
}
Player::~Player()
{
	std::cout << gameObject->getName().c_str() << ": [Player] component destroyed" << std::endl;
}

void Player::awake()
{
	transform = gameObject->getComponent<Transform>();
	spriteRenderer = gameObject->addComponent<SpriteRenderer>();
}

void Player::start()
{
	transform->setScale(Vector2(0.3f, 0.3f));

	TextureConfig cfg = { TextureWrapMode::CLAMP, TextureWrapMode::CLAMP, TextureFilterMode::LINEAR };
	Texture2D* eexuanTex = TextureAllocator::getTexture("../assets/john.jpg");
	eexuanTex->setConfig(cfg);
	sprite = eexuanTex;

	moveSpeed = 1.0f;
	spriteRenderer->setTexture(sprite);
}

void Player::update(float deltaTime)
{
	Vector2 moveDir = Vector2::zero;

	if (Input::getKey(KeyCode::W)) moveDir += Vector2::up;
	if (Input::getKey(KeyCode::S)) moveDir += Vector2::down;
	if (Input::getKey(KeyCode::A)) moveDir += Vector2::left;
	if (Input::getKey(KeyCode::D)) moveDir += Vector2::right;

	moveDir = moveDir.normalized();

	Vector2 pos = transform->getPosition();
	pos += moveDir * moveSpeed * deltaTime;

	transform->setPosition(pos);
	Camera::setPosition(pos.x, pos.y, 0.0f);

	//bullet
	if (Input::getMouseButtonDown(MouseButtonCode::LEFT))
	{
		Vector2 mouseScreenPos = Input::getMousePosition();
		Vector2 mouseWorldPos = Camera::screenToWorld(mouseScreenPos);

		Vector2 bulletDir = (mouseWorldPos - pos).normalized();

		GameObject* bulletObj = GameObject::create("bullet", pos);
		Bullet* bullet = bulletObj->addComponent<Bullet>();
		bullet->setDir(bulletDir);
	}

	//bomb
	if (Input::getKeyDown(KeyCode::E))
	{
		GameObject* bombObj = GameObject::create("bomb", pos);
		bombObj->addComponent<Bomb>();

	}
}

void Player::render()
{

}