#pragma once

#ifdef GETEST_PLATFORM_WINDOWS
	#ifdef GETEST_BUILD_DLL
		#define GETEST_API __declspec(dllexport)
	#else
		#define GETEST_API __declspec(dllimport)
	#endif
#else
	#error GE_TEST is only for Windows currently, because I am an idiot!
#endif // DEBUG

#ifdef GETEST_ENABLE_ASSERTS
	#define GETEST_ASSERT(x, ...) {if(!(x)) {GETEST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GETEST_CORE_ASSERT(x, ...) {if(!(x)) {GETEST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GETEST_ASSERT(x, ...)
	#define GETEST_CORE_ASSERT(x, ...)
#endif // GETEST_ENABLE_ASSERTS

#define GETEST_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#define BIT(x) (1 << x)