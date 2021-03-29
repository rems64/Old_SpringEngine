cmake_minimum_required(VERSION 3.9)

project(SpringEngine VERSION 1.0.0 DESCRIPTION "Game engine")


include_directories("include" "third-party/spdlog/include" "lib/ImGui" "lib/ImGui/backends" "lib/GLFW/include" "lib/GLEW/include" "include/external")


set(SRCS
	"SpringEngine.cpp"
    "src/Core/Window.cpp"
	"src/Core/Application.cpp"
	"src/Misc/Logger.cpp"
	"src/Core/Layer.cpp"
	"src/Core/LayerStack.cpp"
	"src/Layers/TestLayer.cpp"
	"src/Layers/ImGuiLayer.cpp"
	"src/Layers/DebugUILayer.cpp"
	"src/Graphics/IndexBuffer.cpp"
	"src/Misc/Macros.cpp"
	"src/Graphics/Shader.cpp"
	"src/Graphics/Texture.cpp"
	"src/Graphics/VertexArray.cpp"
	"src/Graphics/VertexBuffer.cpp"
	"src/Graphics/VertexBufferLayout.cpp"
	"src/Core/SpringObject.cpp"
	"src/Core/SceneElement.cpp"
	"src/Graphics/Renderer.cpp"
	"src/Layers/WorldLayer.cpp"
	"src/Core/Scene.cpp"
	"src/Components/CameraComponent.cpp"
	"src/Core/Component.cpp"
	"src/Core/DataManager.cpp"
)

set(IMGUI_SRCS
	"lib/ImGui/imgui.cpp"
	"lib/ImGui/imgui_demo.cpp"
	"lib/ImGui/imgui_tables.cpp"
	"lib/ImGui/imgui_widgets.cpp"
	"lib/ImGui/imgui_draw.cpp"
	"lib/ImGui/backends/imgui_impl_opengl3.cpp"
	"lib/ImGui/backends/imgui_impl_glfw.cpp"
)


add_library(SpringEngine SHARED ${SRCS} ${IMGUI_SRCS})

set_target_properties(SpringEngine PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(SpringEngine PROPERTIES LINKER_LANGUAGE CPP)


target_include_directories(SpringEngine PRIVATE include/)

find_package(OpengL REQUIRED COMPONENTS OpenGL)

add_subdirectory("third-party/spdlog")


target_link_libraries(SpringEngine ./lib/GLFW/glfw3)
target_link_libraries(SpringEngine ./lib/GLEW/glew32)
target_link_libraries(SpringEngine ./lib/freetype/freetype)
target_link_libraries(SpringEngine ./lib/FMOD/fmod_vc)
target_link_libraries(SpringEngine ./lib/FMOD/fmodstudio_vc)
target_link_libraries(SpringEngine OpenGL::GL)

file(COPY "lib/GLFW/lib-vc2019/glfw3.lib" DESTINATION ${CMAKE_BINARY_DIR}/lib/GLFW/)
file(COPY "lib/GLFW/lib-vc2019/glfw3.dll" DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY "lib/GLEW/lib/glew32.lib" DESTINATION ${CMAKE_BINARY_DIR}/lib/GLEW/)
file(COPY "lib/GLEW/bin/Release/x64/glew32.dll" DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY "lib/freetype/freetype.lib" DESTINATION ${CMAKE_BINARY_DIR}/lib/freetype/)
file(COPY "lib/freetype/freetype.dll" DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY "lib/FMOD/fmod_vc.lib" DESTINATION ${CMAKE_BINARY_DIR}/lib/FMOD/)
file(COPY "lib/FMOD/fmod.dll" DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY "lib/FMOD/fmodstudio_vc.lib" DESTINATION ${CMAKE_BINARY_DIR}/lib/FMOD/)
file(COPY "lib/FMOD/fmodstudio.dll" DESTINATION ${CMAKE_BINARY_DIR}/)