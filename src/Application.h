#include "AppWindow.h"

namespace GMSCD
{
    class Application
    {
    private:
        static Application* instance;

        AppWindow window;

        unsigned int targetFrameRate;
        float frameTime;
        bool isRunning;

        void onReceiveAppWindowEvent(AppWindowEventType& eventType, void* payload);

    public:
        int init(int width, int height, std::string title);
        void run();
        void cleanup();

        static void setTargetFrameRate(unsigned int frameRate); 
        static void quit();
		static Vector2 getWindowSize();
		static void setWindowSize(int width, int height);
    };
}