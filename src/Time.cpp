#include "Time.h"
#include <glfw/glfw3.h>            

namespace GameMakerStudioChungusDeluxe
{
    static float currentTime = 0.0f;
    static float prevTime = 0.0f;
    static float deltaTime = 0.0f;

    float Time::getTime()
    {
        return currentTime;
    }

    float Time::getDeltaTime()
    {
        return deltaTime;
    }

    void Time::processTime(float frameTime)
    {
        currentTime = glfwGetTime();
        deltaTime = currentTime - prevTime;

        while (deltaTime < frameTime)
        {
            currentTime = glfwGetTime();
            deltaTime = currentTime - prevTime;
        }

        prevTime = currentTime;
    }
}
