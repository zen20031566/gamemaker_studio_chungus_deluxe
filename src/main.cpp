#include "GameMakerStudioChungusDeluxe.h"
	
int main()
{
	GameMakerStudioChungusDeluxe::Application app;
	int result = app.init(600, 600, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	if (result == 1)
	{
		std::cout << "main started" << std::endl;
		app.setTargetFrameRate(30); // optional 
		app.run();
		app.cleanup();
	}

}