
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include "Application.h" 
	
int main()
{
	GameMakerStudioChungusDeluxe::Application app;
	int result = app.init(600, 600, "My Game Engine");

	if (result == 1)
	{
		app.setTargetFrameRate(30); // optional 
		app.run();
		app.cleanup();
	}

}