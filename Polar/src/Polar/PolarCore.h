#pragma once

#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define POLAR_API __declspec(dllexport)
	#else
		#define POLAR_API __declspec(dllimport)
	#endif // !PL_BUILD_DLL
#else
	#error Polar API only supported for Windows! 
#endif // !PL_PLATFORM_WINDOWS

//Bit shifting to create a Bit field for our Event system
#define PL_BIT(x) (1 << x)