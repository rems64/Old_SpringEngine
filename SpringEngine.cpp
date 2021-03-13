#include <SpringEngine/SpringEngine.h>
#include <spdlog/spdlog.h>

int main()
{
	SE::Application app("Spring test");
	SE_CORE_LOG_LEVEL(SE::LOG_LVL::SE_LOGLVL_INFO);
	app.getMainWindow().setVSync(false);

	SE::DebugUILayer* testLayer = new SE::DebugUILayer("UI Debug");
	app.pushOverlay(testLayer);

	SE::Vector3f vec1(1.0, 0.0, 0.0);
	SE::Vector3f vec2(0.0, 1.0, 0.0);
	SE::Vector3f vec3(0.0, 0.0, 1.0);

	SE::Vector2f vec4(1.1, 0.24);
	SE::Vector2f vec5(0.98, 0.5);

	SE_INFO("Sum : x={} y={} z={}", (vec1 + vec2).x(), (vec1 + vec2).y(), (vec1 + vec2).z());
	SE_INFO("Sum 2 : x={} y={}", (vec4 + vec5).x(), (vec4 + vec5).y());
	bool reason = app.mainLoop();

	if (reason == 0x0)
	{
		SE_WARN("Eveything went fine with closing");
	}
	return 0;
}