#pragma once

namespace GameMakerStudioChungusDeluxe
{
	class Time
	{
	public:
		Time() = delete; //default constructor is deleted to prevent creation of Time objects because time needs to be single global scoped obj
		static float getTime();
		static float getDeltaTime();
		static void processTime(float frameTime);
	};
}


