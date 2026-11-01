#pragma once
#include "Texture2D.h"
#include <unordered_map>
#include <string>

namespace GMSCD
{
	// TextureAllocator stores this object type so that it can track
	// how many times it has been requested.
	struct AllocatedTexture
	{
		unsigned int refCount;
		Texture2D* texture;

		AllocatedTexture(Texture2D* t);
		~AllocatedTexture() { delete texture; }
	};

	class TextureAllocator
	{
	public:
		TextureAllocator() = delete;
		static Texture2D* getTexture(std::string texturePath);
		static void returnTexture(Texture2D* texture);
		static void releaseUnusedTextures();

	private:
		static std::unordered_map<std::string, AllocatedTexture*> collection;
	};
}

