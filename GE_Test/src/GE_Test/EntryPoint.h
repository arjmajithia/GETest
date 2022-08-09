#pragma once

#ifdef GETEST_PLATFORM_WINDOWS

extern GE_Test::Application* GE_Test::CreateApplication();

int main(int argc, char** argv)
{
	auto app = GE_Test::CreateApplication();
	app->Run();
	delete app;
}

#endif