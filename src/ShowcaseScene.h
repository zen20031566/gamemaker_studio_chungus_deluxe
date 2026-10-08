#pragma once

class ShowcaseScene
{
private:
	void WindowResizeShowcase();
	void ChangeFramerateShowcase();
	void MouseClickShowcase(float deltaTime);
	void BackgroundColorShowcase();

public:
	void init();
	void update(float deltaTime);
	void draw();
};

