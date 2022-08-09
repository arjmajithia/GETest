#pragma once

#include "Core.h"

namespace GE_Test {
	class GETEST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}

