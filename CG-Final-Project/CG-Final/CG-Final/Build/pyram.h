//
//  pyram.h
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#ifndef pyram_h
#define pyram_h

#include "build.h"

namespace wiw { namespace build {
    class Pyram{
    private:
        VECTOR3D m_Bottom_center;
        GLfloat m_Height;
        GLfloat m_R;
        VECTOR4D m_Color;
    public:
        Pyram(VECTOR3D bottom_center, GLfloat h, GLfloat r, VECTOR4D color = VECTOR4D(1, 1, 1, 1));
        ~Pyram();
        
        void draw() const;
        void onTexture(GLuint texture);
        void offTexture();
        void translate(VECTOR3D trans);
        void scale(VECTOR3D scale);
        void rotate(VECTOR4D rotate);
    };
}}

#endif /* pyram_h */
