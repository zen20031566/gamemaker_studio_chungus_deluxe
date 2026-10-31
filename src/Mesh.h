#pragma once
#include "GMSCDMath.h"
#include <vector>

namespace GMSCD
{
	struct Vertex
	{
		float x, y, z;
		float u, v;

		Vertex() : x(0), y(0), z(0), u(0), v(0) {}
		Vertex(Vector3 pos, Vector2 uv) : x(pos.x), y(pos.y), z(pos.z), u(uv.x), v(uv.y) {}
	};

	class Mesh
	{
	private:
		unsigned int id;
		int vertexCount;

	public:
		Mesh(std::vector<Vertex> vInput);
		~Mesh();

		unsigned int getID();
		int getVertexCount();
	};
}