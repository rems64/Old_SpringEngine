#pragma once

#include <GL/glew.h>
#include <SpringEngine/Misc/Macros.hpp>
#include <SpringEngine/Misc/Logger.hpp>

namespace SE
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		VertexBuffer(const void*, unsigned int);
		VertexBuffer(const VertexBuffer& src);
		~VertexBuffer();

		void setBuffer(const void*, unsigned int);

		void bind() const;
		void unbind() const;

	private:
		unsigned int m_id;
	};
}