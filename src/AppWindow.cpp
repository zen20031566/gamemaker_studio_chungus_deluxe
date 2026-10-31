#include "AppWindow.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream> 

namespace GMSCD
{
    AppWindow::~AppWindow()
    {
        GLFWwindow* window = static_cast<GLFWwindow*>(nativeWindow);
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    // return 0 if fail, 1 if success
    int AppWindow::init(AppWindowData data)
    {
        // try init GLFW 
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return 0;
        }

        // cache the window data 
        windowData = data;

        // set window context to OpenGL 2.1 
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

        // try create the window 
        GLFWwindow* window = glfwCreateWindow(
            windowData.width, windowData.height,
            windowData.title.c_str(), nullptr, nullptr);

        if (window == nullptr)
        {
            std::cout << "Failed to create Window" << std::endl;
            return 0;
        }

        // set the window context as the current context 
        // gl operations uses this window context 
        glfwMakeContextCurrent(window);

        // try initialize glad 
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return 0;
        }

        glfwSetWindowUserPointer(window, &windowData);

        glfwSetWindowCloseCallback(window, [](GLFWwindow* win) 
			{
				AppWindowData* windowData = static_cast<AppWindowData*>(glfwGetWindowUserPointer(win));
				windowData->func_cb(AppWindowEventType::CLOSE, nullptr);
            });

        glfwSetFramebufferSizeCallback(window, [](GLFWwindow* win, int width, int height)
			{
				AppWindowData* windowData = static_cast<AppWindowData*>(glfwGetWindowUserPointer(win));
				windowData->width = width;
				windowData->height = height;
				windowData->func_cb(AppWindowEventType::RESIZE, windowData);
            });

        // window created successfully, cache the reference 
        // and then return success 
        nativeWindow = window;
        return 1;
    }

    void AppWindow::update()
    {
        GLFWwindow* window = static_cast<GLFWwindow*>(nativeWindow);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void AppWindow::setWindowEventCallback(const AppWindowEventCallbackFn& fn)
    {
        windowData.func_cb = fn;
    }

	void* AppWindow::getNativeWindow()
	{
		return nativeWindow;
	}

	Vector2 AppWindow::getWindowSize()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(nativeWindow);
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return Vector2(width, height);
	}

	void AppWindow::setWindowSize(int width, int height)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(nativeWindow);
		glfwSetWindowSize(window, width, height);
	}
}