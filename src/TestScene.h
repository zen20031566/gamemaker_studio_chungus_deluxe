#pragma once
class TestScene
{
public:
	TestScene() = delete;
	static void init();
	static void draw(float x, float y, float z, float r, float g, float b);
};

