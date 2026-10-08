#include "ShowcaseScene.h"
#include <glad/glad.h>     
#include "GameMakerStudioChungusDeluxe.h"
using namespace GameMakerStudioChungusDeluxe;

float speed = 1.0f;
float angle = 0.0f;
bool doSineWave = false;

Vector3 squareColor = Vector3(0.0f, 1.0f, 1.0f);
Vector3 squarePos = Vector3(0.0f, 0.0f, 0.0f);
Vector3 backGroundColor = Vector3(0.5f, 0.0f, 0.0f);
float t = 0.0f;

void ShowcaseScene::init()
{

}

void ShowcaseScene::update(float deltaTime)
{
	if (Input::getKey(KeyCode::ESCAPE))
	{
		Application::quit();
	}

	WindowResizeShowcase();
	ChangeFramerateShowcase();
	MouseClickShowcase(deltaTime);
	BackgroundColorShowcase();
}

void ShowcaseScene::draw()
{
	glClearColor(backGroundColor.x, backGroundColor.y, backGroundColor.z, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(squarePos.x, squarePos.y, 0);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glColor3f(squareColor.x, squareColor.y, squareColor.z);
	glBegin(GL_QUADS);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glEnd();

	glPopMatrix();
}

void ShowcaseScene::WindowResizeShowcase()
{
	if (Input::getKey(KeyCode::F1))
	{
		Application::setWindowSize(200, 200);
	}

	if (Input::getKey(KeyCode::F2))
	{
		Application::setWindowSize(400, 300);
	}

	if (Input::getKey(KeyCode::F3))
	{
		Application::setWindowSize(300, 500);
	}

	if (Input::getKey(KeyCode::F4))
	{
		Application::setWindowSize(600, 600);
	}
}
void ShowcaseScene::ChangeFramerateShowcase()
{
	if (Input::getKeyDown(KeyCode::ALPHA1))
	{
		Application::setTargetFrameRate(10);
	}

	if (Input::getKeyDown(KeyCode::ALPHA2))
	{
		Application::setTargetFrameRate(20);
	}

	if (Input::getKeyUp(KeyCode::ALPHA3))
	{
		Application::setTargetFrameRate(30);
	}

	if (Input::getKeyUp(KeyCode::ALPHA4))
	{
		Application::setTargetFrameRate(60);
	}

	if (Input::getKeyUp(KeyCode::ALPHA5))
	{
		Application::setTargetFrameRate(0);
	}
}

void ShowcaseScene::MouseClickShowcase(float deltaTime)
{
		if (Input::getMouseButton(MouseButtonCode::RIGHT))
		{
			angle += 45.0f * deltaTime;
			Vector2 mousePos = Input::getMousePosition();
			Vector2 windowSize = Application::getWindowSize();
			squarePos.x = (mousePos.x / windowSize.x) * 2.0f - 1.0f;
			squarePos.y = 1.0f - (mousePos.y / windowSize.y) * 2.0f;
			squareColor = Vector3(1.0f, 0.0f, 1.0f);
		}
		if (Input::getMouseButtonUp(MouseButtonCode::RIGHT))
		{
			squareColor = Vector3(0.0f, 1.0f, 1.0f);
		}

		if (Input::getMouseButtonDown(MouseButtonCode::LEFT))
		{
			doSineWave = true;
			std::cout << "Left mouse button clicked!"<< std::endl;
			squareColor = Vector3(0.0f, 1.0f, 0.0f);
		}
		if (Input::getMouseButtonUp(MouseButtonCode::LEFT))
		{
			doSineWave = false;
			std::cout << "Left mouse button released!"<< std::endl;
			squareColor = Vector3(0.0f, 1.0f, 1.0f);
		}

		if (doSineWave)
		{
			t += deltaTime;
			squarePos.y = sinf(t) * 0.5f;
		}
}

void ShowcaseScene::BackgroundColorShowcase()
{
	if (Input::getKeyUp(KeyCode::Q))
	{
		backGroundColor = Vector3(0.0f, 0.5f, 0.0f);
	}

	if (Input::getKeyUp(KeyCode::W))
	{
		backGroundColor = Vector3(0.0f, 0.0f, 0.5f);
	}

	if (Input::getKeyUp(KeyCode::E))
	{
		backGroundColor = Vector3(0.5f, 0.0f, 0.0f);
	}
}


