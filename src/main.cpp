#include "GameMakerStudioChungusDeluxe.h"
#include "SplashScreen.h"
#include "ShowcaseScene.h"

using namespace GMSCD;

int main()
{
	Application app;
	int result = app.init(600, 600, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	if (result == 1)
	{
		SceneStateMachine::addScene<SplashScreen>();
		SceneStateMachine::addScene<ShowcaseScene>();
		SceneStateMachine::loadScene("SplashScreen"); 

		std::cout << "main started" << std::endl;
		app.setTargetFrameRate(60); 
		app.run();
		app.cleanup();
	}

}