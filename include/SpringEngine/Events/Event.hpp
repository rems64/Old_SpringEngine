#pragma once

#include <ostream>


#define EVENT_CLASS_TYPE(type) static  EventType     getStaticType()                  { return EventType::type; }\
							   virtual EventType     getEventType()  const override   { return getStaticType(); }\
							   virtual const char*   getName()       const override   { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }


namespace SE
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication     = (1 << 0),
		EventCategoryWindow          = (1 << 1),
		EventCategoryInput           = (1 << 2),
		EventCategoryKeyboard        = (1 << 3),
		EventCategoryMouse           = (1 << 4),
		EventCategoryMouseButton     = (1 << 5)
	};
	class Event
	{
	public:
		virtual ~Event() = default;

		bool handled = false;

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); };

		bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		};
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event) : m_event(event)
		{
		}

		template <typename T, typename F>
		bool Dispatch(const F& function)
		{
			if (m_event.getEventType() == T::getStaticType())
			{
				m_event.handled |= function(static_cast<T&>(m_event));
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.toString();
	}
}