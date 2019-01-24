//
//  cube.h
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#ifndef cube_h
#define cube_h

#include "build.h"

namespace wiw { namespace build{
    class Cube{
    private:
        VECTOR3D m_Center;
        GLfloat m_Length;
        GLfloat m_Width;
        GLfloat m_Height;
        VECTOR4D m_Color;
    public:
        Cube();
        Cube(VECTOR3D center, GLfloat length, GLfloat width, GLfloat height, VECTOR4D color = VECTOR4D(1, 1, 1, 1));
        ~Cube();
        
		void DrawCube() const;

        void draw() const;
        void onTexture(GLuint texture);
        void offTexture();
        void translate(VECTOR3D trans);
        void scale(VECTOR3D scale);
        void rotate(VECTOR4D rotate);
    };
}}

#endif /* cube_h */
