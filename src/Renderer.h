#pragma once
#include "Mesh.h"
#include "GMSCDMath.h"

namespace GMSCD
{
	struct DrawCommand
	{
		unsigned int meshId;
		size_t vertexStride;
		int vertexCount;
		Vector4 tint;
		Vector3 translation;
		float rotationZ;
		Vector3 scale;
	};

	class Renderer
	{
	private:
		Renderer() = delete;
		static std::vector<DrawCommand> draws;
		static bool isRendering;
		static Matrix4x4 vpMatrix;

	public:
		static void init();
		static int load();
		static void setViewport(int x, int y, int width, int height);
		static void setClearColor(float r, float g, float b, float a);
		static void clear();
		static void submitCommand(DrawCommand dc);
		static void beginFrame();
		static void endFrame();
	};
}



