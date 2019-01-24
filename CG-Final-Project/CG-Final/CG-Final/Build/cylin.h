//
//  cylin.h
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#ifndef cylin_h
#define cylin_h

#include "build.h"

namespace wiw { namespace build {
    class Cylin{
    private:
        VECTOR3D m_Center;
        GLfloat m_Height;
        GLfloat m_R;
        VECTOR4D m_Color;
    public:
        Cylin(VECTOR3D center, GLfloat h, GLfloat r, VECTOR4D color = VECTOR4D(1, 1, 1, 1));
        ~Cylin();
        
        void draw() const;
        void onTexture(GLuint texture);
        void offTexture();
        void translate(VECTOR3D trans);
        void scale(VECTOR3D scale);
        void rotate(VECTOR4D rotate);
    };
}}

#endif /* cylin_h */
