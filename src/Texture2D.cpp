#pragma once
#include "Texture2D.h"
#include <glad/glad.h>
#include <iostream> 
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

namespace GMSCD
{
	static GLint toGLFormat_WrapMode(TextureWrapMode wrapMode)
	{
		switch (wrapMode)
		{
			case TextureWrapMode::REPEAT: return GL_REPEAT;
			case TextureWrapMode::CLAMP: return GL_CLAMP;
		}
		return 0;
	}

	static GLint toGLFormat_MagFilter(TextureFilterMode filterMode)
	{
		switch (filterMode)
		{
			case TextureFilterMode::LINEAR: return GL_LINEAR;
			case TextureFilterMode::NEAREST: return GL_NEAREST;
		}
		return 0;
	}

	static GLint toGLFormat_MinFilter(TextureFilterMode filterMode)
	{
		switch (filterMode)
		{
			case TextureFilterMode::LINEAR: return GL_LINEAR;
			case TextureFilterMode::NEAREST: return GL_NEAREST;
		}
		return 0;
	}

	unsigned int Texture2D::getID() const
	{
		return id;
	}

	Vector2 Texture2D::getSize() const
	{
		return Vector2(width, height);
	}

	const std::string& Texture2D::getPath() const
	{
		return path;
	}

	const TextureConfig& Texture2D::getConfig() const
	{
		return cfg;
	}

	Texture2D::~Texture2D()
	{
		glDeleteTextures(1, &id);
	}

	Texture2D::Texture2D(const std::string& path, TextureConfig cfg) : path(path), cfg(cfg)
	{
		int w, h, channels;
		stbi_set_flip_vertically_on_load(1);

		unsigned char* data = stbi_load(path.c_str(), &w, &h, &channels, 0);

		if (data)
		{
			width = w;
			height = h;

			GLenum internalFormat = 0;
			GLenum dataFormat = 0;

			// if channels is 4 
			//    internalFormat is GL_RGBA8 
			//    dataFormat is GL_RGBA 
			// otherwise if channels is 3 
			//    internalFormat is GL_RGB8 
			//    dataFormat is GL_RGB 
			if (channels == 4)
			{
				internalFormat = GL_RGBA8;
				dataFormat = GL_RGBA;
			}
			else if (channels == 3)
			{
				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
			}

			// generate 1 texture, pass id as reference 
			// bind the texture 
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			// set wrap modes 
			//    use toGLFormat_WrapMode to convert TextureWrapMode to GL equivalent 
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, toGLFormat_WrapMode(cfg.wrapModeX));
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, toGLFormat_WrapMode(cfg.wrapModeY));

			// set filter modes 
			//    use toGLFormat_MagFilter and toGLFormat_MinFilter to convert 
			//    TextureFilterMode to GL equivalent 
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, toGLFormat_MinFilter(cfg.filterMode));
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, toGLFormat_MagFilter(cfg.filterMode));

			// upload data 
			//    refer to OpenGL documentation on what goes where 
			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, w, h, 0, dataFormat, GL_UNSIGNED_BYTE, data);

			// free memory as image data is uploaded to GPU 
			stbi_image_free(data);

			// log success 
			std::cout << "[Texture2D] Image loaded: " << path.c_str() << std::endl;
		}
		else
		{
			// log error 
			std::cout << "[Texture2D] Failed to load image: " << path.c_str() << std::endl;
		}
	}
}

