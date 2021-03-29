#include <SpringEngine/SpringEngine.h>
#include <spdlog/spdlog.h>

#include <SpringEngine/Core/AudioCore.hpp>

int main()
{
	SE::Application app("Spring test");
	SE_CORE_LOG_LEVEL(SE::LOG_LVL::SE_LOGLVL_INFO);
	app.getMainWindow().setVSync(true);

	SE::DebugUILayer* uiDebugLayer = new SE::DebugUILayer("UI Debug");
	app.pushOverlay(uiDebugLayer);

	app.mainLoop();

	return 0x0;
}