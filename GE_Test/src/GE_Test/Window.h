#pragma once

#include "getpch.h"
#include "Core.h"
#include "Events/Event.h"

namespace GE_Test {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Game Engine Test",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	/*class GETEST_API Window
	{
	};*/
}