#pragma once

#include "obj.h"

namespace wiw
{
	namespace obj
	{
		class Door
		{
		private:
			build::Cube m_Door;
			build::Cube m_Wall;
			static GLfloat m_Angle;
		public:
			Door();
			~Door();

			void draw(VECTOR3D pos, GLuint door, GLuint wall);
			void open();
			void close();
		};
	}
}