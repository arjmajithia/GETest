#pragma once

#include "GE_Test/Layer.h"

#include "GE_Test/Events/ApplicationEvent.h"
#include "GE_Test/Events/KeyEvent.h"
#include "GE_Test/Events/MouseEvent.h"


namespace GE_Test {

	class GETEST_API imguiLayer : public Layer
	{
	public:
		imguiLayer();
		~imguiLayer();

		void OnUpdate();
		void OnEvent(Event& e);
		void OnAttach();
		void OnDetach();

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressed& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleased& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);


	private:
		float m_Time = 0.0f;
	};
}
