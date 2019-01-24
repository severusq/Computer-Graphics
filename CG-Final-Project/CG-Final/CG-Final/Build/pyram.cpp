//
//  pyram.cpp
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#include "pyram.h"

namespace wiw { namespace build {
    Pyram::Pyram(VECTOR3D bottom_center, GLfloat h, GLfloat r, VECTOR4D color)
    :m_Bottom_center(bottom_center), m_Height(h), m_R(r), m_Color(color){
        glPushMatrix();
    }
    
    Pyram::~Pyram(){
        
    }
    
    void Pyram::draw() const{
        glColor4f(m_Color.x, m_Color.y, m_Color.z, m_Color.w);
        glTranslatef(m_Bottom_center.x, m_Bottom_center.y, m_Bottom_center.z);
        glScalef(m_R, m_R, m_Height);
        drawCycle(VECTOR3D(0, 0, 0));
        glutSolidCone(1, 1, 30, 30);
        glPopMatrix();
    }
    
    void Pyram::onTexture(GLuint texture){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    
    void Pyram::offTexture(){
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
    }
    
    void Pyram::translate(VECTOR3D trans){
		MATRIX4X4 m;
		m.SetTranslation(trans);
		VECTOR3D r = m * m_Bottom_center;
		m_Bottom_center.x = r.x;
		m_Bottom_center.y = r.y;
		m_Bottom_center.z = r.z;
    }
    
    void Pyram::scale(VECTOR3D scale){
        glScalef(scale.x, scale.y, scale.z);
    }
    
    void Pyram::rotate(VECTOR4D rotate){
        glRotatef(rotate.x, rotate.y, rotate.z, rotate.w);
    }
}}
