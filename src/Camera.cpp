#include "Camera.h"

namespace GMSCD
{
	// projection is identity matrix, aspect ratio is 1.0f, and config has the default value. 
	Matrix4x4 Camera::projection = Matrix4x4::identity;
	float Camera::aspectRatio = 1.0f;
	CameraConfig Camera::config;
	int Camera::windowWidth = 600;
	int Camera::windowHeight = 600;
	Matrix4x4 Camera::view = Matrix4x4::identity;
	Matrix4x4 Camera::vp = Matrix4x4::identity;
	Vector3 Camera::position = Vector3::zero;
	bool Camera::isDirty = true;

	void Camera::init(CameraConfig cfg, int width, int height)
	{
		config = cfg;
		setViewportSize(width, height);
	}

	void Camera::setViewportSize(int width, int height)
	{
		if (width <= 0 || height <= 0) return;
		windowWidth = width;
		windowHeight = height;
		recalculate();
	}

	void Camera::recalculate()
	{
		Camera::aspectRatio = windowWidth / (float)windowHeight;

		// minX and minY is -maxX and -maxY respectively. 
		float maxY = config.orthoSize;
		float maxX = maxY * Camera::aspectRatio;
		float minZ = -1.0f;
		float maxZ = 1.0f;

		Camera::projection = Matrix4x4::ortho(-maxX, maxX, -maxY, maxY, minZ, maxZ);
	}

	float Camera::getAspectRatio()
	{
		return aspectRatio;
	}

	Matrix4x4 Camera::getMatrix_projection()
	{
		return projection;
	}

	void Camera::setOrthoSize(float size)
	{
		if (size <= 0.0f) return;

		config.orthoSize = size;
		recalculate();
	}

	float Camera::getOrthoSize()
	{
		return config.orthoSize;
	}

	Matrix4x4 Camera::getMatrix_view()
	{
		if (isDirty)
		{
			Matrix4x4 camTransform = Matrix4x4::translate(position);
			view = camTransform.inverse();
			vp = projection * view;
			isDirty = false;
		}
		return view;
	}

	Matrix4x4 Camera::getMatrix_viewProjection()
	{
		if (isDirty)
		{
			Matrix4x4 camTransform = Matrix4x4::translate(position);
			view = camTransform.inverse();
			vp = projection * view;
			isDirty = false;
		}
		return vp;
	}

	void Camera::translate(Vector3 translation)
	{
		position += translation;
		isDirty = true;
	}

	void Camera::translate(float x, float y, float z)
	{
		translate(Vector3(x, y, z));
	}

	void Camera::setPosition(Vector3 position)
	{
		Camera::position = position;
		isDirty = true;
	}

	void Camera::setPosition(float x, float y, float z)
	{
		setPosition(Vector3(x, y, z));
	}

	Vector3 Camera::screenToWorld(Vector2 screenPos)
	{
		// Normalize screenPos to -1~1 range 
		float normX = 2.0f * (screenPos.x / windowWidth) - 1.0f;
		float normY = 2.0f * (screenPos.y / windowHeight) - 1.0f;

		// Make a homogeneous vector 
		Vector4 ndcPos(normX, normY, 0.0f, 1.0f);

		// Calculation is by multiplying the homogenous vector 
		// with the inverse of view-projection 
		Matrix4x4 vpInv = vp.inverse();
		Vector4 wPos = vpInv * ndcPos;

		// return the x,y,0 coordinate which is in the world space. 
		return Vector3(wPos.x, wPos.y, 0.0f);
	}

	bool Camera::isPointVisible(Vector2 worldPos, float padding)
	{
		float halfHeight = config.orthoSize + padding;
		float halfWidth = halfHeight * aspectRatio;

		float minX = position.x - halfWidth;
		float maxX = position.x + halfWidth;
		float minY = position.y - halfHeight;
		float maxY = position.y + halfHeight;

		return worldPos.x >= minX && worldPos.x <= maxX &&
			worldPos.y >= minY && worldPos.y <= maxY;
	}
}
