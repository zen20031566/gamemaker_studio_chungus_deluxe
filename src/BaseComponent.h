#pragma once 

namespace GMSCD
{
	// DO NOT #include "GameObject.h" 
	class GameObject; // forward declare that GameObject class exists. 

	class BaseComponent
	{
	public:
		BaseComponent(GameObject* go);
		virtual ~BaseComponent() = 0; // pure virtual 

		virtual void awake();
		virtual void start();
		virtual void update(float deltaTime);
		virtual void render();

		void destroy();
		bool shouldDestroy() const;
	
		static constexpr bool disallowMultipleInstance = false;

	protected:
		GameObject* gameObject;
		bool flaggedForDeletion = false;
	};

}