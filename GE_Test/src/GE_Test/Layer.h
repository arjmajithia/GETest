#pragma once

#include "GE_Test/Core.h"
#include "GE_Test/Events/Event.h"

namespace GE_Test {

	class GETEST_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnUpdate() {};
		virtual void OnDetach() {};
		virtual void OnAttach() {};
		virtual void OnEvent(Event& e) {};

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}