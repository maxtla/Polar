#pragma once
#include "Event.h"

namespace Polar
{
	class POLAR_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent (w, h): " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_TYPE_CLASS(OnWindowResize)
		EVENT_CATEGORY_CLASS(EventCategoryApplication)
	private:
		unsigned int m_width, m_height;
	};

	class POLAR_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		EVENT_TYPE_CLASS(OnWindowClose)
		EVENT_CATEGORY_CLASS(EventCategoryApplication)
	};

	class POLAR_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}
		EVENT_TYPE_CLASS(OnAppTick)
		EVENT_CATEGORY_CLASS(EventCategoryApplication)
	};

	class POLAR_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}
		EVENT_TYPE_CLASS(OnAppUpdate)
		EVENT_CATEGORY_CLASS(EventCategoryApplication)
	};

	class POLAR_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}
		EVENT_TYPE_CLASS(OnAppRender)
		EVENT_CATEGORY_CLASS(EventCategoryApplication)
	};

}