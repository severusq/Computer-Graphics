#pragma once

#include <cstdio>
#include <cmath>
#include "GL/glut.h"
#include "../Math/Maths.h"
#include "cube.h"
#include "ball.h"
#include "cylin.h"
#include "pyram.h"
#include "material.h"
#include "texture.h"

namespace wiw
{
	namespace build
	{
		inline VECTOR3D getBallPoint(GLfloat u, GLfloat v) //u is the angle with +x, v is the angle with +z
		{
			GLfloat x = sin(M_PI*v) * cos(2 * M_PI*u);
			GLfloat y = sin(M_PI*v) * sin(2 * M_PI*u);
			GLfloat z = cos(M_PI*v);
			return VECTOR3D(x, y, z);
		}

		inline VECTOR2D getCylinPoint(GLfloat s) //u is the angle with +x, v is the angle with +z
		{
			GLfloat x = cos(2 * M_PI*s);
			GLfloat y = sin(2 * M_PI*s);
			return VECTOR2D(x, y);
		}

		inline void drawCycle(VECTOR3D pos)
		{
			GLuint num = 30;
			GLfloat step = 1 / (GLfloat)num;
			GLfloat s = 0;
			for (int i = 0; i < num; i++)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(pos.x, pos.y, pos.z);
				VECTOR2D p1 = getCylinPoint(s);
				glVertex3f(pos.x + p1.x, pos.y + p1.y, pos.z);
				VECTOR2D p2 = getCylinPoint(s - step);
				glVertex3f(pos.x + p2.x, pos.y + p2.y, pos.z);
				s -= step;
				glEnd();
			}
		}
	}
}