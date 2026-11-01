#include "Graphics.h"
#include "Renderer.h" 

namespace GMSCD
{
	void Graphics::drawMesh(Mesh* mesh, RenderParams params)
	{
		DrawCommand dc;
		dc.meshId = mesh->getID();
		dc.vertexStride = sizeof(Vertex);
		dc.vertexCount = mesh->getVertexCount();
		dc.textureId = params.texture->getId();
		dc.tint = params.tint;
		dc.translation = params.translation;
		dc.rotationZ = params.rotationZ;
		dc.scale = params.scale;

		Renderer::submitCommand(dc);
	}
}