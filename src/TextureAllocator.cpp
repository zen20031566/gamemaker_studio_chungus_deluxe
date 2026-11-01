#include "TextureAllocator.h"
#include "TextureUtils.h"
#include <iostream>

namespace GMSCD
{
	// initialize static collection
	std::unordered_map<std::string, AllocatedTexture*> TextureAllocator::collection;

	AllocatedTexture::AllocatedTexture(Texture2D* t) : texture(t), refCount(0) {};

	Texture2D* TextureAllocator::getTexture(std::string texturePath)
	{
		std::cout << "TODO: getTexture" << std::endl;

		// Try find AllocatedTexture object in collection using texturePath
		// If found
		//    Increase refCount by 1
		//    Print to console: Reusing texture: <texturePath> :: refCount: <refCount>
		//    Return the texture
		//
		// Otherwise
		//    Try load texture
		//    If successful
		//        Create AllocatedTexture object with the texture
		//        Increase refCount by 1
		//        Add the object to the collection
		//        Return the texture
		//    Otherwise
		//        Return blank texture

		auto it = collection.find(texturePath);
		if (it != collection.end())
		{
			AllocatedTexture* allocatedTexture = it->second;
			allocatedTexture->refCount++;
			std::cout << "Reusing texture: " << texturePath << " :: refCount: " << allocatedTexture->refCount << std::endl;
			return allocatedTexture->texture;
		}
		else
		{
			Texture2D* texture = TextureUtils::loadTexture2D(texturePath);
			if (texture != nullptr)
			{
				AllocatedTexture* allocatedTexture = new AllocatedTexture(texture);
				allocatedTexture->refCount++;
				collection[texturePath] = allocatedTexture;
				return texture;
			}
		}

		return TextureUtils::checkerTexture2D();
	}

	void TextureAllocator::returnTexture(Texture2D* texture)
	{
		std::cout << "TODO: returnTexture" << std::endl;

		// get texturePath from texture

		// Find the matching AllocatedTexture object using texturePath
		// If found
		//    Decrease the refCount
		//    If refCount is 0
		//        Print to console: <texturePath> refCount is 0!

		std::string texturePath = texture->getPath();

		auto it = collection.find(texturePath);
		if (it != collection.end())
		{
			AllocatedTexture* allocatedTexture = it->second;

			if (allocatedTexture->refCount > 0)
			{
				allocatedTexture->refCount--;
			}

			if (allocatedTexture->refCount == 0)
			{
				std::cout << texturePath << " refCount is 0!" << std::endl;
			}
		}
	}

	void TextureAllocator::releaseUnusedTextures()
	{
		std::cout << "TODO: releaseUnusedTextures" << std::endl;

		// Iterate the collection, for each AllocatedTexture element
		// If element refCount is 0
		//     Delete the texture
		//     Remove element from collection

		for (auto it = collection.begin(); it != collection.end();)
		{
			AllocatedTexture* allocatedTexture = it->second;
			if (allocatedTexture->refCount == 0)
			{
				delete allocatedTexture;
				it = collection.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}
