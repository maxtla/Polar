#pragma once

#include "PolarCore.h"

namespace Polar
{
	class POLAR_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	//To be defined in Client
	Application * CreateApplication();

}


