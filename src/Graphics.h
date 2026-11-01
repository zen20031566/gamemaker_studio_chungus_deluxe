#pragma once
#include "Mesh.h"
#include "GMSCDMath.h"
#include "Texture2D.h"

namespace GMSCD
{
	struct RenderParams
	{
		// Simple material 
		Texture2D* texture;
		Vector4 tint;

		// Transformation 
		Vector3 translation;
		float rotationZ;
		Vector3 scale;
	};

	class Graphics
	{
	public:
		Graphics() = delete;
		static void drawMesh(Mesh* mesh, RenderParams params);
	};
}
