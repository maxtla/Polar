#pragma once

#include "PolarCore.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h> //console logging

namespace Polar
{
	class POLAR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetPolarCoreLogger()		{ return		s_PolarCoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()				{ return		s_ClientLogger;		 }

	private:
		static std::shared_ptr<spdlog::logger> s_PolarCoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

		//Prints: "[TIME] Logger's Name (log level): Message"
		static const char logger_pattern[];
		
	};
}

//Logging Macros for PolarCore sorted by severity
#define PL_CORE_TRACE(...)		::Polar::Log::GetPolarCoreLogger()->trace(__VA_ARGS__)
#define PL_CORE_INFO(...)			::Polar::Log::GetPolarCoreLogger()->info(__VA_ARGS__)
#define PL_CORE_WARN(...)		::Polar::Log::GetPolarCoreLogger()->warn(__VA_ARGS__)
#define PL_CORE_ERROR(...)		::Polar::Log::GetPolarCoreLogger()->error(__VA_ARGS__)

//Logging Macros for Application sorted by severity
#define PL_TRACE(...)					::Polar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PL_INFO(...)						::Polar::Log::GetClientLogger()->info(__VA_ARGS__)
#define PL_WARN(...)					::Polar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PL_ERROR(...)					::Polar::Log::GetClientLogger()->error(__VA_ARGS__)
