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
