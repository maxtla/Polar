#pragma once
#include "Event.h"

namespace Polar
{
	class POLAR_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const	{ return m_keyCode; }

		EVENT_CATEGORY_CLASS(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : m_keyCode(keycode) {}
		int m_keyCode;
	};

	class POLAR_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCounter) : KeyEvent(keycode), m_repeatCounter(repeatCounter) {}

		inline int GetRepeatCounter() const { return m_repeatCounter;  }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (Repeated: " << m_repeatCounter << ")";
			return ss.str();
		}

		EVENT_TYPE_CLASS(OnKeyPressed)
	private:
		int m_repeatCounter;
	};

	class POLAR_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_TYPE_CLASS(OnKeyReleased)
	};
}


