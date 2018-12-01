#include "../PolarPCH.h"
#include "Log.h"


namespace Polar
{
	std::shared_ptr<spdlog::logger> Log::s_PolarCoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	//Prints: "[TIME] Logger's Name (log level): Message"
	const char Log::logger_pattern[32] = "%^ [%T] %n\t (%l):\t %v%$";

	void Log::Init()
	{
		try
		{
			//Set the pattern
			spdlog::set_pattern(Log::logger_pattern);

			//Init PolarCore logger
			s_PolarCoreLogger = spdlog::stdout_color_mt("POLAR");
			s_PolarCoreLogger->set_level(spdlog::level::trace);
			//Init Client logger
			s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			std::cout << "Log initialization failed: " << ex.what() << std::endl;
		}
		
	}

}

