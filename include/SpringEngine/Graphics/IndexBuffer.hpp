#pragma once

#include <GL/glew.h>
#include <SpringEngine/Misc/Macros.hpp>

namespace SE
{
	class IndexBuffer
	{
	public:
		IndexBuffer();
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		void setBuffer(const unsigned int* data, unsigned int count);
		void setBuffer(const unsigned long* data, unsigned int count);

		void bind() const;
		void unbind() const;

		void debugPrint() const;

		inline unsigned int getCount() const { return m_count; };

	private:
		unsigned int m_id;
		unsigned int m_count;
	};
}