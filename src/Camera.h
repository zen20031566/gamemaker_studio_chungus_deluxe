#pragma once
#include "GMSCDMath.h"

namespace GMSCD
{
	struct CameraConfig
	{
		float orthoSize = 1.0f;
	};

	class Camera
	{
	public:
		Camera() = delete;
		static void init(CameraConfig cfg, int width, int height);
		static void recalculate(int width, int height);
		static void recalculateProjection();
		static float getAspectRatio();
		static Matrix4x4 getMatrix_projection();
		static void setOrthoSize(float size);
		static float getOrthoSize();
		static Matrix4x4 getMatrix_view();
		static Matrix4x4 getMatrix_viewProjection();
		static void recalculateView();
		static void recalculateViewProjection();
		static void translate(Vector3 translation);
		static void translate(float x, float y, float z);
		static void setPosition(Vector3 position);
		static void setPosition(float x, float y, float z);
		static Vector3 screenToWorld(Vector2 screenPos);

	private:
		static Matrix4x4 projection;
		static int windowWidth;
		static int windowHeight;
		static float aspectRatio;
		static CameraConfig config;
		static Matrix4x4 view;
		static Matrix4x4 vp;
		static Vector3 position;
		static bool isDirty;
	};
}

