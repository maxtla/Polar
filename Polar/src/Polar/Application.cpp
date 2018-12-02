#include <PolarPCH.h>
#include "Application.h"

namespace Polar
{
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		PL_TRACE(e);

		if (e.BelongsToCategory(EventCategoryApplication))
			PL_INFO(true);
		if (!e.BelongsToCategory(EventCategoryInput))
			PL_WARN(false);

		system("PAUSE");
	}


}


