#include "pch.h"
//Skeleton class run by Polar::Application

class Application : public Polar::Application
{
public:
	Application()
	{

	}
	~Application()
	{

	}
};

Polar::Application* Polar::CreateApplication()
{
	return new Application();
}