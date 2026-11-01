#pragma once
#include "Texture2D.h"
#include <glad/glad.h>
#include <iostream> 

namespace GMSCD
{
	Texture2D::Texture2D(int width, int height, TextureConfig cfg) : width(width), height(height), cfg(cfg) {}

	Texture2D* Texture2D::createTexture(int width, int height, const TextureConfig& cfg, GLenum internalFormat, GLenum dataFormat, unsigned char* data)
	{
		Texture2D* tex = new Texture2D(width, height, cfg);

		// generate 1 texture, pass id as reference 
		// bind the texture 
		glGenTextures(1, &tex->id);
		glBindTexture(GL_TEXTURE_2D, tex->id);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		// upload data  
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);

		tex->setConfig(cfg);

		glBindTexture(GL_TEXTURE_2D, 0);

		return tex;
	}

	unsigned int Texture2D::getId() const
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

	void Texture2D::setPath(const std::string& path)
	{
		this->path = path;
	}

	const TextureConfig& Texture2D::getConfig() const
	{
		return cfg;
	}

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

	void Texture2D::setConfig(const TextureConfig& cfg)
	{
		if (id == 0) return;
		this->cfg = cfg;

		glBindTexture(GL_TEXTURE_2D, id);

		// set wrap modes 
			//    use toGLFormat_WrapMode to convert TextureWrapMode to GL equivalent 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, toGLFormat_WrapMode(cfg.wrapModeX));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, toGLFormat_WrapMode(cfg.wrapModeY));

		// set filter modes 
		//    use toGLFormat_MagFilter and toGLFormat_MinFilter to convert 
		//    TextureFilterMode to GL equivalent 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, toGLFormat_MinFilter(cfg.filterMode));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, toGLFormat_MagFilter(cfg.filterMode));

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture2D::~Texture2D()
	{
		glDeleteTextures(1, &id);
	}


}

