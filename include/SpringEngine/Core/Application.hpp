#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <string>
#include <SpringEngine/Core/Window.hpp>
#include <SpringEngine/Events/Event.hpp>
#include <SpringEngine/Core/Layer.hpp>
#include <SpringEngine/Core/LayerStack.hpp>
#include <SpringEngine/Layers/ImGuiLayer.hpp>


namespace SE
{
	class Application
	{
	public:
		//Application();
		Application(std::string name);
		Application(const SE::Application& src);
		~Application();

		void init();
		int mainLoop();

		SE::Window& getMainWindow();

		void onEvent(Event& event);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		bool onWindowCloseEvent(WindowCloseEvent& event);
		bool onMouseMove(MouseMove& event);
		bool onMousePressed(MousePressed& event);
		bool onMouseReleased(MouseReleased& event);

		double getFPS();

		static Application& get() { return *s_instance; }
	private:
		static Application* s_instance;
		std::vector<SE::Window*> m_windows;
		unsigned int m_windowsNbr;
		std::string m_name;
		bool m_appRunning;
		double m_frameRate;

		LayerStack m_layerStack;
		ImGuiLayer* m_imGuiLayer;
	};
};