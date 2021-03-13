#pragma once

#include <SpringEngine/Events/Event.hpp>

namespace SE
{
	class Window;
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(Window* win) : m_window(win) {};

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)

		inline Window* getWindow() { return m_window; };

	private:
		Window* m_window;
	};

	class MouseMove : public Event
	{
	public:
		MouseMove(double x, double y) : m_x(x), m_y(y) {};

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse)

		inline double getX() { return m_x; };
		inline double getY() { return m_y; };

	private:
		double m_x;
		double m_y;
	};

	class MousePressed : public Event
	{
	public:
		MousePressed(int button, int action, int mods) : m_button(button), m_action(action), m_mods(mods) {};
		MousePressed(int button, int action, int mods, double x, double y) : m_button(button), m_action(action), m_mods(mods), m_x(x), m_y(y) {};

		EVENT_CLASS_TYPE(MouseButtonPressed)
		EVENT_CLASS_CATEGORY(EventCategoryMouse)

		inline int getButton() { return m_button; };
		inline int getAction() { return m_action; };
		inline int getMods()   { return m_mods;   };

		inline double getX() { return m_x; };
		inline double getY() { return m_y; };
	private:
		int m_button;
		int m_action;
		int m_mods;
		double m_x;
		double m_y;
	};
	class MouseReleased : public Event
	{
	public:
		MouseReleased(int button, int action, int mods) : m_button(button), m_action(action), m_mods(mods) {};
		MouseReleased(int button, int action, int mods, double x, double y) : m_button(button), m_action(action), m_mods(mods), m_x(x), m_y(y) {};

		EVENT_CLASS_TYPE(MouseButtonReleased)
		EVENT_CLASS_CATEGORY(EventCategoryMouse)

		inline int getButton() { return m_button; };
		inline int getAction() { return m_action; };
		inline int getMods() { return m_mods; };

		inline double getX() { return m_x; };
		inline double getY() { return m_y; };
	private:
		int m_button;
		int m_action;
		int m_mods;
		double m_x;
		double m_y;
	};
}