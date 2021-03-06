#pragma once

#include <vector>
#include <SpringEngine/Misc/Macros.hpp>
#include <SpringEngine/Misc/Logger.hpp>
#include <GL/glew.h>

namespace SE
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT: return sizeof(GLfloat);
			case GL_UNSIGNED_INT: return sizeof(GLuint);
			case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
			}
			ASSERT(false);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout();
		~VertexBufferLayout();
		VertexBufferLayout(const VertexBufferLayout& src);
		VertexBufferLayout& operator=(const VertexBufferLayout& rhs);

		template <typename T>
		void Push(unsigned int count)
		{
			static_assert(false);
		}
		template <>
		void Push<float>(unsigned int count)
		{
			m_elements.push_back({ GL_FLOAT, count, GL_FALSE });
			m_stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
			m_countStride += count;
		}

		inline const std::vector<VertexBufferElement> getElements() const { return m_elements; };
		inline unsigned int getStride() const { return m_stride; };
		inline unsigned int getCountStride() const { return m_countStride; };
	private:
		std::vector<VertexBufferElement> m_elements;
		unsigned int m_stride;
		unsigned int m_countStride;
	};
}