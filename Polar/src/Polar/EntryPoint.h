#pragma once

#ifdef PL_PLATFORM_WINDOWS

extern Polar::Application* Polar::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Polar::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Polar API only supported for Windows! 
#endif // HZ_PLATFORM_WINDOWS

