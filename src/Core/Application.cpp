#include <SpringEngine/Core/Application.hpp>

#include <chrono>

SE::Application* SE::Application::s_instance = nullptr;

//SE::Application::Application() : m_windows(), m_appRunning(true), m_windowsNbr(0)
//{
//	if (!s_instance)
//		SE_CORE_ERROR("Application has already been created");
//	else
//		s_instance = this;
//	SE::Log::init();
//	SE_CORE_LOG_LEVEL(SE::LOG_LVL::SE_LOGLVL_TRACE);
//	SE_CORE_INFO("Application started");
//	init();
//}

SE::Application::Application(std::string name) : m_windows(), m_name(name), m_appRunning(true), m_windowsNbr(0), m_frameRate(60)
{
	SE::Log::init();
	SE_CORE_INFO("Application \"{0}\" started", name);
	if (s_instance!=nullptr)
		SE_CORE_ERROR("Application has already been created");
	s_instance = this;
	init();
	SE::Window* win = new SE::Window(name.c_str());
	win->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	//m_windows.emplace_back(name.c_str());
	m_windows.push_back(win);
	m_windowsNbr++;

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	win->makeContextCurrent();

	unsigned int glewInitResult = glewInit();
	if (glewInitResult)
	{
		SE_CORE_CRITICAL("An error occured while initilizing glew : {}", (GLenum)glewInitResult);
		abort;
	}

	m_imGuiLayer = new ImGuiLayer();
	s_instance->pushOverlay(m_imGuiLayer);
}

SE::Application::Application(const SE::Application& src) : m_windows(src.m_windows), m_appRunning(src.m_appRunning), m_windowsNbr(src.m_windowsNbr), m_imGuiLayer(src.m_imGuiLayer)
{
}

SE::Application::~Application()
{
	glfwTerminate();
}

void SE::Application::init()
{
	if (!glfwInit())
	{
		SE_CORE_CRITICAL("An error occured while initilizing GLFW");
	}

}

int SE::Application::mainLoop()
{
	std::vector<SE::Window*>::iterator windowIterator = m_windows.begin();
	std::chrono::high_resolution_clock::time_point loopStart = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point loopEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time_span = loopEnd - loopStart;
	while (m_appRunning)
	{
		loopStart = std::chrono::high_resolution_clock::now();
		(**windowIterator).makeContextCurrent();
		(**windowIterator).swapBuffers();
		glClear(GL_COLOR_BUFFER_BIT);

		m_imGuiLayer->begin();
		{
			for (Layer* layer : m_layerStack)
				layer->onImGuiRender();
		}
		m_imGuiLayer->end();

		// Events
		glfwPollEvents();

		loopEnd = std::chrono::high_resolution_clock::now();
		time_span = loopEnd - loopStart;
		m_frameRate = 1000 / (time_span.count());
	}
	return 0;
}

SE::Window& SE::Application::getMainWindow()
{
	return *m_windows[0];
}

void SE::Application::onEvent(Event& event)
{
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::onWindowCloseEvent, this, std::placeholders::_1));
	dispatcher.Dispatch<MouseMove>(std::bind(&Application::onMouseMove, this, std::placeholders::_1));
	dispatcher.Dispatch<MousePressed>(std::bind(&Application::onMousePressed, this, std::placeholders::_1));
	dispatcher.Dispatch<MouseReleased>(std::bind(&Application::onMouseReleased, this, std::placeholders::_1));

	for (auto it = m_layerStack.rbegin(); it != m_layerStack.rend(); ++it)
	{
		if (event.handled)
			break;
		(*it)->onEvent(event);
	}
}

void SE::Application::pushLayer(Layer* layer)
{
	m_layerStack.pushLayer(layer);
	layer->onAttach();
}

void SE::Application::pushOverlay(Layer* layer)
{
	m_layerStack.pushOverlay(layer);
	layer->onAttach();
}

bool SE::Application::onWindowCloseEvent(WindowCloseEvent& event)
{
	Window* win = event.getWindow();
	unsigned int concernedIndex=0;
	for (unsigned int i = 0; i < m_windows.size(); i++)
	{
		if (m_windows[i] == win)
		{
			concernedIndex = i;
			break;
		}
	}
	SE_CORE_INFO("Handling closing of the window with id {}", concernedIndex);
	m_windows[concernedIndex]->~Window();
	m_windows.erase(m_windows.begin() + concernedIndex);
	if (m_windows.empty())
	{
		m_appRunning = false;
	}
	return true;
}

bool SE::Application::onMouseMove(MouseMove& event)
{
	SE_CORE_TRACE("Mouse moved at ({0} {1})", event.getX(), event.getY());
	return true;
}

bool SE::Application::onMousePressed(MousePressed& event)
{
	SE_CORE_TRACE("Mouse clicked at ({0} {1})", event.getX(), event.getY());
	return false;
}


bool SE::Application::onMouseReleased(MouseReleased& event)
{
	SE_CORE_TRACE("Mouse released at ({0} {1})", event.getX(), event.getY());
	return false;
}

double SE::Application::getFPS()
{
	return m_frameRate;
}
