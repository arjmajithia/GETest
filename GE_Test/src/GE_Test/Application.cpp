#include "getpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace GE_Test {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			GETEST_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			GETEST_TRACE(e);
		}
		while (true);
	}
}