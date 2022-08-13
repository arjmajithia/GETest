#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GE_Test {
	class GETEST_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Logging Macros
#define GETEST_CORE_TRACE(...) ::GE_Test::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GETEST_CORE_INFO(...)  ::GE_Test::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GETEST_CORE_WARN(...)  ::GE_Test::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GETEST_CORE_ERROR(...) ::GE_Test::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GETEST_CORE_FATAL(...) ::GE_Test::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core Logging Macros
#define GETEST_TRACE(...) ::GE_Test::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GETEST_INFO(...)  ::GE_Test::Log::GetClientLogger()->info(__VA_ARGS__)
#define GETEST_WARN(...)  ::GE_Test::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GETEST_ERROR(...) ::GE_Test::Log::GetClientLogger()->error(__VA_ARGS__)
#define GETEST_FATAL(...) ::GE_Test::Log::GetClientLogger()->fatal(__VA_ARGS__)