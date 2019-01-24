//
//  cylin.cpp
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#include "cylin.h"

namespace wiw { namespace build {
    Cylin::Cylin(VECTOR3D center, GLfloat h, GLfloat r, VECTOR4D color)
    :m_Center(center), m_Height(h), m_R(r), m_Color(color){
        glPushMatrix();
    }
    
    Cylin::~Cylin(){
        
    }

    void Cylin::draw() const{
        glColor4f(m_Color.x, m_Color.y, m_Color.z, m_Color.w);
        GLUquadricObj *objCylinder = gluNewQuadric();
        glTranslatef(m_Center.x, m_Center.y, m_Center.z);
        glScalef(m_R, m_R, m_Height);
        drawCycle(VECTOR3D(0, 0, 1));
        drawCycle(VECTOR3D(0, 0, 0));
        gluCylinder(objCylinder, 1, 1, 1, 30, 30);
        glPopMatrix();
    }
    
    void Cylin::onTexture(GLuint texture){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    
    void Cylin::offTexture(){
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
    }
    
    void Cylin::translate(VECTOR3D trans){
		MATRIX4X4 m;
		m.SetTranslation(trans);
		VECTOR3D r = m * m_Center;
		m_Center.x = r.x;
		m_Center.y = r.y;
		m_Center.z = r.z;
    }
    
    void Cylin::scale(VECTOR3D scale){
        glScalef(scale.x, scale.y, scale.z);
    }
    
    void Cylin::rotate(VECTOR4D rotate){
        glRotatef(rotate.x, rotate.y, rotate.z, rotate.w);
    }
}}
