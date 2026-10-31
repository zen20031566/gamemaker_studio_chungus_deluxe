#pragma once
#include <string>
#include <vector>
#include "GameObject.h"

namespace GMSCD
{
	class BaseScene
	{
	public:
		virtual std::string getName() const = 0;

	protected:
		virtual void onInitialize() = 0;
		virtual void onActivate() {};
		virtual void onDeactivate() {};
		virtual void onUpdate(float deltaTime) {};
		virtual void onRender() {};

	private:
		friend class SceneStateMachine;

		void initialize();
		void activate();
		void deactivate();
		void update(float deltaTime);
		void render();
	};
}
