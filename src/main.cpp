#include "GameMakerStudioChungusDeluxe.h"
#include "ShowcaseScene.h"

using namespace GMSCD;

int main()
{
	Application app;
	int result = app.init(600, 600, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	if (result == 1)
	{
		SceneStateMachine::addScene<ShowcaseScene>();
		SceneStateMachine::loadScene("ShowcaseScene"); 

		std::cout << "main started" << std::endl;
		app.setTargetFrameRate(60); 
		app.run();
		app.cleanup();
	}

}