#include "Application.h" 
#include "Time.h"
#include "TestScene.h" 
#include "iostream"

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
        float x = 0.0f, y = 0.0f, z = 0.0f;
        float r = 0.0f, g = 1.0f, b = 1.0f;
        TestScene::init();
        // =========================================== 

        while (isRunning)
        {
            // 1. Time 
            Time::processTime(frameTime);

            // 2. Input Processing 

            // 3. Updates 

            // 4. Render 
            TestScene::draw(x, y, z, r, g, b);

            // 5. Display 
            window.update();
        }
    }

    void Application::cleanup()
    {
        // empty 
        // window will be automatically cleaned 
        // when main program exits due to 
        // window being an object on the stack. 
    }

    void GameMakerStudioChungusDeluxe::Application::setTargetFrameRate(unsigned int frameRate)
    {
        instance->targetFrameRate = frameRate;
        instance->frameTime = frameRate > 0 ? 1.0f / frameRate : 0.0f;
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
                AppWindowResizeData* resizeData = static_cast<AppWindowResizeData*>(payload);
                std::cout << "Width: " << resizeData->width << std::endl;
                std::cout << "Height: " << resizeData->height << std::endl;
                break;

            }
        }
    }
}