#pragma once
#include <string>
#include "GMSCDMath.h"
#include <glad/glad.h>

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
		TextureWrapMode wrapModeX = TextureWrapMode::REPEAT;
		TextureWrapMode wrapModeY = TextureWrapMode::REPEAT;
		TextureFilterMode filterMode = TextureFilterMode::LINEAR;
	};

	class Texture2D
	{
	public:            
		static Texture2D* createTexture(int width, int height, const TextureConfig& cfg, GLenum internalFormat, GLenum dataFormat, unsigned char* data);

		unsigned int getId() const;
		Vector2 getSize() const;

		const std::string& getPath() const;
		void setPath(const std::string& path);

		const TextureConfig& getConfig() const;
		void setConfig(const TextureConfig& cfg);

		~Texture2D();

	private:
		TextureConfig cfg;
		unsigned int id;
		int width, height;
		std::string path;

		Texture2D(int width, int height, TextureConfig cfg);
	};
}