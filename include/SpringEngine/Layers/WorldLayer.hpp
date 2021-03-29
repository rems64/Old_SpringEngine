#pragma once

#include <SpringEngine/Core/Layer.hpp>
#include <SpringEngine/Misc/Logger.hpp>
#include <SpringEngine/Core/SceneElement.hpp>

namespace SE
{
	class WorldLayer : public Layer
	{
	public:
		WorldLayer();
		~WorldLayer() = default;

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onEvent(Event & event) override;

		virtual void onUpdate(double deltaTime) override;

		virtual void onImGuiRender() override;

	private:
		SceneElement m_element;
	};
}