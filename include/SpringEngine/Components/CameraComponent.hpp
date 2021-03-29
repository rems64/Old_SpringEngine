#pragma once

#include <SpringEngine/Core/Component.hpp>

#include <glm/common.hpp>
#include <glm/mat4x4.hpp>
#include <SpringEngine/Core/Vector3.hpp>

namespace SE
{
	class CameraComponent : public Component
	{
	public:
		CameraComponent();
		~CameraComponent();

	private:
		glm::mat4 m_projection;
	};
}