cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")


project ("SpringEngine")

include_directories("include" "third-party/spdlog/include" "lib/ImGui" "lib/GLFW/include" "lib/GLEW/include")


set(SRCS
	"SpringEngine.cpp"
    "src/Core/Window.cpp"
	"src/Core/Application.cpp"
	"src/Misc/Logger.cpp"
	"src/Core/Layer.cpp"
	"src/Core/LayerStack.cpp"
	"src/Layers/TestLayer.cpp"
	"src/Layers/ImGuiLayer.cpp"
 "src/Layers/DebugUILayer.cpp")

set(IMGUI_SRCS
	"lib/ImGui/imgui.cpp"
	"lib/ImGui/imgui_demo.cpp"
	"lib/ImGui/imgui_tables.cpp"
	"lib/ImGui/imgui_widgets.cpp"
	"lib/ImGui/imgui_draw.cpp"
	"lib/ImGui/imgui_impl_opengl3.cpp"
	"lib/ImGui/imgui_impl_glfw.cpp"
)

find_package(OpengL REQUIRED COMPONENTS OpenGL)

add_subdirectory("third-party/spdlog")

add_executable (SpringEngine ${IMGUI_SRCS} ${SRCS})

target_link_libraries(SpringEngine ./libs/GLFW/glfw3)
target_link_libraries(SpringEngine ./libs/GLEW/glew32)
target_link_libraries(SpringEngine ./libs/freetype/freetype)
target_link_libraries(SpringEngine OpenGL::GL)

file(COPY "lib/GLFW/lib-vc2019/glfw3.lib" DESTINATION ${CMAKE_BINARY_DIR}/libs/GLFW/)
file(COPY "lib/GLFW/lib-vc2019/glfw3.dll" DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY "lib/GLEW/lib/glew32.lib" DESTINATION ${CMAKE_BINARY_DIR}/libs/GLEW/)
file(COPY "lib/GLEW/bin/Release/x64/glew32.dll" DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY "lib/freetype/freetype.lib" DESTINATION ${CMAKE_BINARY_DIR}/libs/freetype/)
file(COPY "lib/freetype/freetype.dll" DESTINATION ${CMAKE_BINARY_DIR}/)