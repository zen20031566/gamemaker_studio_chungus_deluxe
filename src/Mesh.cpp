#include "Mesh.h"
#include <glad/glad.h> 

namespace GMSCD
{
	Mesh::Mesh(std::vector<Vertex> vInput)
	{
		//Assign the size of vInput to vertexCount 
		vertexCount = vInput.size();

		// Generate VBO, and upload data to the VBO 
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex), &vInput[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Mesh::~Mesh()
	{
		// Delete the VBO on mesh destruction. 
		glDeleteBuffers(1, &id);
	}

	unsigned int Mesh::getID()
	{
		return id;
	}

	int Mesh::getVertexCount()
	{
		return vertexCount;
	}
}