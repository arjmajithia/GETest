#pragma once

#ifdef GETEST_PLATFORM_WINDOWS

extern GE_Test::Application* GE_Test::CreateApplication();

int main(int argc, char** argv)
{
	GE_Test::Log::Init();
	GETEST_CORE_WARN("Core Testing");
	GETEST_INFO("Client Testing");
	int a = 5;
	GETEST_ERROR("Var={0}", a);


	if (__cplusplus == 201703L) GETEST_CORE_INFO("C++17\n");
	else if (__cplusplus == 201402L) GETEST_CORE_INFO("C++14\n");
	else if (__cplusplus == 201103L) GETEST_CORE_INFO("C++11\n");
	else if (__cplusplus == 199711LL) GETEST_CORE_INFO("C++98\n");
	else GETEST_CORE_INFO("idk");


	auto app = GE_Test::CreateApplication();
	app->Run();
	delete app;
}

#endif