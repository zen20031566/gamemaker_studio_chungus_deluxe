#pragma once
#include <string>
#include "GMSCDMath.h"

namespace GMSCD
{
	enum class TextureWrapMode
	{
		REPEAT,
		CLAMP
	};

	enum class TextureFilterMode
	{
		LINEAR,
		NEAREST
	};

	struct TextureConfig
	{
		TextureWrapMode wrapModeX;
		TextureWrapMode wrapModeY;
		TextureFilterMode filterMode;
	};

	class Texture2D
	{
	public:
		unsigned int getID() const;
		Vector2 getSize() const;
		const std::string& getPath() const;
		const TextureConfig& getConfig() const;

		~Texture2D();
		Texture2D(const std::string& path, TextureConfig cfg);

	private:
		TextureConfig cfg;
		std::string path;
		unsigned int id;
		int width;
		int height;
	};
}