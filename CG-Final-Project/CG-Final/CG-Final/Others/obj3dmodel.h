#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "GL/glut.h"
#include "../Math/Maths.h"

using namespace std;

namespace wiw
{
	class Obj3dmodel
	{
	private:
		vector<vector<GLfloat>>vSets;
		vector<vector<GLint>>fSets;
	public:
		Obj3dmodel(string filename);
		void Draw(VECTOR3D position, VECTOR4D rotation, VECTOR3D scale, GLuint texture);
	};
}