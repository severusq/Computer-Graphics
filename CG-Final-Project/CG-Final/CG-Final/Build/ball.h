//
//  ball.h
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#ifndef ball_h
#define ball_h

#include "build.h"

namespace wiw { namespace build {
    class Ball{
    private:
        VECTOR3D m_Center;
        GLfloat m_R;
        VECTOR4D m_Color;
    public:
        Ball(VECTOR3D center, GLfloat r, VECTOR4D color = VECTOR4D(1, 1, 1, 1));
        ~Ball();
        
        void draw() const;
        void onTexture(GLuint texture);
        void offTexture();
        void translate(VECTOR3D trans);
        void scale(VECTOR3D scale);
        void rotate(VECTOR4D rotate);
    };
}}

#endif /* ball_h */
