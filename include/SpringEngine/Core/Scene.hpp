#pragma once

#include <vector>
#include <SpringEngine/Core/SceneElement.hpp>
#include <SpringEngine/Components/CameraComponent.hpp>

namespace SE
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		inline CameraComponent* getViewCamera() { return m_viewCamera; };
		void setViewCamera(CameraComponent* newCamera) { m_viewCamera = newCamera; };

	private:
		std::vector<SceneElement> m_elements;
		CameraComponent* m_viewCamera;
	};
}