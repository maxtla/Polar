#pragma once

#include "Event.h"

namespace Polar
{

	class POLAR_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

		inline float GetX() const { return m_mouseX; }
		inline float GetY() const { return m_mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent (x, y): " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}
		
		EVENT_TYPE_CLASS(OnMouseMoved)
		EVENT_CATEGORY_CLASS(EventCategoryMouse | EventCategoryInput)
	private:
		float m_mouseX, m_mouseY;
	};

	class POLAR_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent (dx, dy): " << m_xOffset << ", " << m_yOffset;
			return ss.str();
		}

		EVENT_TYPE_CLASS(OnMouseScrolled)
		EVENT_CATEGORY_CLASS(EventCategoryMouse | EventCategoryInput)
	private:
		float m_xOffset, m_yOffset;
	};

	class POLAR_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_button; }

		EVENT_CATEGORY_CLASS(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_button(button) {}
		int m_button;
	};

	class POLAR_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_TYPE_CLASS(OnMouseButtonPressed)
	};

	class POLAR_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_TYPE_CLASS(OnMouseButtonReleased)
	};
}