//
//  ball.cpp
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#include "ball.h"

namespace wiw { namespace build {
    Ball::Ball(VECTOR3D center, GLfloat r, VECTOR4D color)
    :m_Center(center), m_R(r), m_Color(color){
        glPushMatrix();
    }
    
    Ball::~Ball(){
        
    }
    
    void Ball::draw() const{
        glColor4f(m_Color.x, m_Color.y, m_Color.z, m_Color.w);
        glTranslatef(m_Center.x, m_Center.y, m_Center.z);
        glutSolidSphere(m_R, 30, 30);
        glPopMatrix();
    }
    
    void Ball::onTexture(GLuint texture){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    
    void Ball::offTexture(){
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
    }
    
    void Ball::translate(VECTOR3D trans){
		MATRIX4X4 m;
		m.SetTranslation(trans);
		VECTOR3D r = m * m_Center;
		m_Center.x = r.x;
		m_Center.y = r.y;
		m_Center.z = r.z;
    }
    
    void Ball::scale(VECTOR3D scale){
        glScalef(scale.x, scale.y, scale.z);
    }
    
    void Ball::rotate(VECTOR4D rotate){
        glRotatef(rotate.x, rotate.y, rotate.z, rotate.w);
    }
}}
