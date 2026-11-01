#include "Renderer.h"
#include <glad/glad.h>
#include <glfw/glfw3.h> 
#include <iostream>
#include "Camera.h"

namespace GMSCD
{
	std::vector<DrawCommand> Renderer::draws;
	bool Renderer::isRendering;
	Matrix4x4 Renderer::vpMatrix;

	void Renderer::init()
	{
		glEnable(GL_TEXTURE_2D); // Enable texturing 
		glEnable(GL_BLEND); // Enable blending 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Standard alpha blending 
	}

	int Renderer::load()
	{
		// if glad init is successful, return 1. Otherwise return 0. 
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return 0;
		}

		return 1;
	}

	void Renderer::setViewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
		Camera::setViewportSize(width, height);
	}

	void Renderer::setClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void Renderer::clear()
	{
		// TODO: clear the framebuffer. This is a gl function.
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void Renderer::submitCommand(DrawCommand dc)
	{
		if (!isRendering)
		{
			std::cout << "Rendering commands only submittable in render step!" << std::endl;
			return;
		}
		else
		{
			draws.push_back(dc);
		}
	}

	void Renderer::beginFrame()
	{
		isRendering = true;
		Renderer::clear();
		Renderer::vpMatrix = Camera::getMatrix_viewProjection();
	}

	void Renderer::endFrame()
	{
		// Set common settings 
		glPushMatrix(); // Push matrix to stack.
		glLoadMatrixf(&vpMatrix[0][0]); // Load view-projection matrix.
		glEnableClientState(GL_VERTEX_ARRAY); // Enable vertex array state.
		glEnableClientState(GL_TEXTURE_COORD_ARRAY); // Enable texcoord array state

		// Draw all render requests 
		for (DrawCommand dc : draws)
		{
			glPushMatrix();

			// Apply Transformation 
			glTranslatef(dc.translation.x, dc.translation.y, dc.translation.z);
			glRotatef(dc.rotationZ, 0.0f, 0.0f, 1.0f);
			glScalef(dc.scale.x, dc.scale.y, dc.scale.z);

			// Apply materials 
			glColor4fv(&dc.tint[0]);
			glBindTexture(GL_TEXTURE_2D, dc.textureId);

			// Draw Object 
			glBindBuffer(GL_ARRAY_BUFFER, dc.meshId);
			glVertexPointer(3, GL_FLOAT, dc.vertexStride, 0);
			glTexCoordPointer(2, GL_FLOAT, dc.vertexStride, (void*)12);
			glDrawArrays(GL_TRIANGLES, 0, dc.vertexCount);

			glPopMatrix();
		}

		// Unset common settings 
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind any bounded VBO 
		glDisableClientState(GL_VERTEX_ARRAY); // Disable vertex array state.
		glDisableClientState(GL_TEXTURE_COORD_ARRAY); // Disable texcoord array state. 
		glPopMatrix(); // Pop matrix from stack

		// Clear draws and set isRendering to false 
		draws.clear();
		isRendering = false;
	}
}
