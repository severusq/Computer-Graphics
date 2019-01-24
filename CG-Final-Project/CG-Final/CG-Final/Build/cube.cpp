//
//  cube.cpp
//  GLUT_test
//
//  Created by weaveinwind on 2018/12/31.
//  Copyright © 2018 weaveinwind. All rights reserved.
//

#include "cube.h"

namespace wiw { namespace build {
    Cube::Cube(){
        
    }
    
    Cube::Cube(VECTOR3D center, GLfloat length, GLfloat width, GLfloat height, VECTOR4D color)
    :m_Center(center), m_Length(length), m_Width(width), m_Height(height), m_Color(color){
        glPushMatrix();
    }
    
    Cube::~Cube(){
        
    }

	void Cube::DrawCube() const
	{
		float cx = m_Length / 2.0f;
		float cy = m_Width / 2.0f;
		float cz = m_Height / 2.0f;

		glBegin(GL_QUADS);
		// 左面
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, -cz);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(-cx, cy, -cz);
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(-cx, cy, cz);
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(-cx, -cy, cz);
		// 右面
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(cx, -cy, -cz);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(cx, cy, -cz);
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(cx, cy, cz);
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(cx, -cy, cz);
		// 上面
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, cy, -cz);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(cx, cy, -cz);
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(cx, cy, cz);
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(-cx, cy, cz);
		// 下面
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, -cz);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(cx, -cy, -cz);
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(cx, -cy, cz);
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(-cx, -cy, cz);
		// 前面
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, -cz);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(cx, -cy, -cz);
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(cx, cy, -cz);
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(-cx, cy, -cz);
		// 后面
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, cz);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(cx, -cy, cz);
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(cx, cy, cz);
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(-cx, cy, cz);
		glEnd();
	}
    
    void Cube::draw() const{
		glColor4f(m_Color.x, m_Color.y, m_Color.z, m_Color.w);
		glTranslatef(m_Center.x, m_Center.y, m_Center.z);
		glScalef(m_Length, m_Width, m_Height);
		glutSolidCube(1.0f);
        glPopMatrix();
    }
    
    void Cube::onTexture(GLuint texture){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    
    void Cube::offTexture(){
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
    }
    
    void Cube::translate(VECTOR3D trans){
		MATRIX4X4 m;
		m.SetTranslation(trans);
		VECTOR3D r = m * m_Center;
		m_Center.x = r.x;
		m_Center.y = r.y;
		m_Center.z = r.z;
    }
    
    void Cube::scale(VECTOR3D scale){
        glScalef(scale.x, scale.y, scale.z);
    }
    
    void Cube::rotate(VECTOR4D rotate){
        glRotatef(rotate.x, rotate.y, rotate.z, rotate.w);
    }
}}
