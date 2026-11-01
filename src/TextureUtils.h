#pragma once
#include <string>
#include "Texture2D.h"

namespace GMSCD
{
	class TextureUtils
	{
	public:
		TextureUtils() = delete;

		static Texture2D* loadTexture2D(const std::string& path, TextureConfig cfg = TextureConfig());

		static Texture2D* blackTexture2D();
		static Texture2D* whiteTexture2D();
		static Texture2D* checkerTexture2D();
	};
}
