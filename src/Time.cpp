#include "Time.h"
#include <glfw/glfw3.h>            
#include "Mathf.h"

namespace GameMakerStudioChungusDeluxe
{
	static float currentTime = 0.0f;
	static float deltaTime = 0.0f;
	static float unscaledTime = 0.0f;
	static float unscaledDeltaTime = 0.0f;
	static float timeScale = 1.0f;
	static double prevTime = 0.0;

    float Time::getTime()
    {
        return currentTime;
    }

    float Time::getDeltaTime()
    {
        return deltaTime;
    }

	float Time::getUnscaledTime()
	{
		return unscaledTime;
	}

	float Time::getUnscaledDeltaTime()
	{
		return unscaledDeltaTime;
	}

	float Time::getTimeScale()
	{
		return timeScale;
	}

	void Time::setTimeScale(float scale)
	{
		timeScale = Mathf::max(scale, 0.0f);
	}

    void Time::processTime(float frameTime)
    {
		unscaledTime = glfwGetTime();
		unscaledDeltaTime = unscaledTime - prevTime;

		while (unscaledDeltaTime < frameTime)
		{
			unscaledTime = glfwGetTime();
			unscaledDeltaTime = unscaledTime - prevTime;
		}

		prevTime = unscaledTime;

		deltaTime = unscaledDeltaTime * timeScale;
		currentTime += deltaTime;
    }
}
