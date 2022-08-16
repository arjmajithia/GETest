#pragma once

#include "GE_Test/Layer.h"

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
		float m_Time = 0.0f;
	};
}
