#pragma once
#include <iostream>

#ifdef PL_PLATFORM_WINDOWS

extern Polar::Application* Polar::CreateApplication();
	
int main(int argc, char** argv)
{
	//TODO:  write a Wrapper Init that encapsulates all of our Systems Init calls.
	Polar::Log::Init();
	Polar::MLD::Init();

	auto app = Polar::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Polar API only supported for Windows! 
#endif // HZ_PLATFORM_WINDOWS

