#include "TextureUtils.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include <iostream>

namespace GMSCD
{
	Texture2D* TextureUtils::loadTexture2D(const std::string& path, TextureConfig cfg)
	{
		Texture2D* tex = 0;
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);

		unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		if (data)
		{
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

			tex = Texture2D::createTexture(width, height, cfg, internalFormat, dataFormat, data);
			tex->setPath(path);
			// log success 
			std::cout << "[Texture2D] Image loaded: " << path.c_str() << std::endl;
		}
		else
		{
			// log error 
			std::cout << "[Texture2D] Failed to load image: " << path.c_str() << std::endl;
		}

		// free memory as image data is uploaded to GPU 
		stbi_image_free(data);

		return tex;
	}

	Texture2D* TextureUtils::blackTexture2D()
	{
		static unsigned char data[4] = { 0x00, 0x00, 0x00, 0xff };
		static Texture2D* tex = Texture2D::createTexture(1, 1,
			{ TextureWrapMode::REPEAT, TextureWrapMode::REPEAT, TextureFilterMode::NEAREST },
			GL_RGBA8, GL_RGBA, data);

		tex->setPath("black");
		return tex;
	}

	Texture2D* TextureUtils::whiteTexture2D()
	{
		static unsigned char data[4] = { 0xff, 0xff, 0xff, 0xff };
		static Texture2D* tex = Texture2D::createTexture(1, 1,
			{ TextureWrapMode::REPEAT, TextureWrapMode::REPEAT, TextureFilterMode::NEAREST },
			GL_RGBA8, GL_RGBA, data);

		tex->setPath("white");
		return tex;
	}

	Texture2D* TextureUtils::checkerTexture2D()
	{
		static unsigned char data[16] = {
			0xff, 0x00, 0xff, 0xff,   0x70, 0x00, 0x70, 0xff,
			0x70, 0x00, 0x70, 0xff,   0xff, 0x00, 0xff, 0xff
		};
		static Texture2D* tex = Texture2D::createTexture(2, 2,
			{ TextureWrapMode::REPEAT, TextureWrapMode::REPEAT, TextureFilterMode::NEAREST },
			GL_RGBA8, GL_RGBA, data);

		tex->setPath("checker");
		return tex;
	}
}