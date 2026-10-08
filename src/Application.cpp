#include "GameMakerStudioChungusDeluxe.h"
#include "ShowcaseScene.h"

namespace GameMakerStudioChungusDeluxe
{
    // Actually define the static Application instance variable 
    Application* Application::instance;

    int Application::init(int width, int height, std::string title)
    {
        AppWindowData data(width, height, title);

        int result = window.init(data);

        if (result == 1)
        {
            targetFrameRate = 0;
            frameTime = 0.0f;
            isRunning = true;
            instance = this;

            window.setWindowEventCallback(
                [this](AppWindowEventType eventType, void* payload)
                {
                    onReceiveAppWindowEvent(eventType, payload);
                });
        }

        return result;
    }

    void Application::run()
    {
        // 0. Late Init 
        // To be removed after OCM is operational ==== 
		Input::init(&window);
		ShowcaseScene* scene = new ShowcaseScene();
		scene->init();

        // =========================================== 

        while (isRunning)
        {
            // 1. Time 
            Time::processTime(frameTime);

            // 2. Input Processing 
			Input::process();

            // 3. Updates 
			scene->update(Time::getDeltaTime());

            // 4. Render 
			scene->draw();

            // 5. Display 
            window.update();
        }

		delete scene;
    }

    void Application::cleanup()
    {
        // empty 
        // window will be automatically cleaned 
        // when main program exits due to 
        // window being an object on the stack. 
    }

    void Application::setTargetFrameRate(unsigned int frameRate)
    {
        instance->targetFrameRate = frameRate;
        instance->frameTime = frameRate > 0 ? 1.0f / frameRate : 0.0f;

		if (frameRate == 0)
			std::cout << "Framerate set to: Unlimited" << std::endl;
		else
			std::cout << "Framerate set to: " << frameRate << " fps" << std::endl;
    }

    void Application::quit()
    {
        instance->isRunning = false;
    }

    void Application::onReceiveAppWindowEvent(AppWindowEventType& eventType, void* payload)
    {
        switch (eventType)
        {
            case AppWindowEventType::CLOSE:
            {
                std::cout << "Window Close Event" << std::endl;
                isRunning = false;
                break;
            }
            // other events 
            case AppWindowEventType::RESIZE:
            {
                std::cout << "Window Resize Event" << std::endl;
                AppWindowData* windowData = static_cast<AppWindowData*>(payload);
                std::cout << "Width: " << windowData->width << std::endl;
                std::cout << "Height: " << windowData->height << std::endl;
                break;

            }
        }
    }

	Vector2 Application::getWindowSize()
	{
		return instance->window.getWindowSize();	
	}

	void Application::setWindowSize(int width, int height)
	{
		instance->window.setWindowSize(width, height);
	}
}