#pragma once
#include <string>                      
#include <functional> 
#include "GMSCDMath.h"

namespace GMSCD
{
    enum class AppWindowEventType
    {
        CLOSE,
        RESIZE
    };
    using AppWindowEventCallbackFn = std::function<void(AppWindowEventType, void*)>; // type aliasing

    struct AppWindowData
    {
        int width;
        int height;
        std::string title;

        AppWindowData() {}

        AppWindowData(int width, int height, std::string title)
            : width(width), height(height), title(title) {}

        AppWindowEventCallbackFn func_cb;
    };

    class AppWindow
    {
    private:
        AppWindowData windowData;
        void* nativeWindow;

    public:
        ~AppWindow();
        int init(AppWindowData data);
        void update();
        void setWindowEventCallback(const AppWindowEventCallbackFn& fn);
		void* getNativeWindow();
		Vector2 getWindowSize();
		void setWindowSize(int width, int height);
    };
}