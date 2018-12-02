#pragma once

#include <Polar/PolarCore.h>
#include<functional>
#include <sstream>

namespace Polar
{
	enum class EventType
	{
		NoEventType = 0,
		//Window events
		OnWindowClose, 
		OnWindowResize,
		OnWindowFocus,
		OnWindowFocusLost,
		OnWindowMoved,
		//Application events
		OnAppTick,
		OnAppUpdate,
		OnAppRender,
		//Keyboard events
		OnKeyPressed,
		OnKeyReleased,
		//Mouse events
		OnMouseButtonPressed,
		OnMouseButtonReleased,
		OnMouseMoved,
		OnMouseScrolled
	};

	enum EventCategory
	{
		NoEventCategory = 0,
		EventCategoryApplication		= PL_BIT(0),
		EventCategoryInput					= PL_BIT(1),
		EventCategoryKeyboard			= PL_BIT(2),
		EventCategoryMouse				= PL_BIT(3),
		EventCategoryMouseButton	= PL_BIT(4)
	};

#define EVENT_TYPE_CLASS(type) static EventType GetStaticType() { return EventType::##type; }\
														virtual EventType GetEventType() const override { return GetStaticType(); }\
														virtual const char * GetName() const override { return #type; }

#define EVENT_CATEGORY_CLASS(category) virtual int GetCategoryFlags() const override { return category; }

	//Abstract Base class for all kind of Events
	class POLAR_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const		= 0;
		virtual const char* GetName() const			= 0;
		virtual int GetCategoryFlags() const			= 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool BelongsToCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_isHandeled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event &event) : m_event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_isHandeled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		Event & m_event;

	};

	//For easy logging of events
	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}



