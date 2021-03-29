#pragma once

#include <SpringEngine/Core/Vector3.hpp>
#include <SpringEngine/Core/SpringObject.hpp>

#include <SpringEngine/Graphics/Shader.hpp>
#include <SpringEngine/Graphics/VertexArray.hpp>
#include <SpringEngine/Graphics/VertexBuffer.hpp>
#include <SpringEngine/Graphics/IndexBuffer.hpp>
#include <SpringEngine/Graphics/VertexBufferLayout.hpp>

namespace SE
{
	class SceneElement : public SpringObject
	{
	public:
		SceneElement();
		SceneElement(Vector3<float> position);
		~SceneElement();

		VertexArray* getVertexArray();
		IndexBuffer* getIndexBuffer();
		Shader* getShader();

	private:
		Vector3<float> m_position;
		Vector3<float> m_scale;
		Vector3<float> m_rotation;

		Shader* m_shader;
		VertexArray* m_va;
		VertexBuffer* m_vb;
		IndexBuffer* m_ib;
		VertexBufferLayout* m_vbl;
	};
}