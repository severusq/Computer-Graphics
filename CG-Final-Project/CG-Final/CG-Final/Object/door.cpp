//
//  door.cpp
//  GLUT_test
//
//  Created by weaveinwind on 2019/1/2.
//  Copyright © 2019 weaveinwind. All rights reserved.
//

#include "door.h"

namespace wiw { namespace obj {
    GLfloat Door::Door::m_Angle = 0.0f;
    
    Door::Door(){

    }
    
    Door::~Door(){
        
    }
    
    void Door::draw(VECTOR3D pos, GLuint door, GLuint wall){
		m_Door = build::Cube(VECTOR3D(0, 0, 0), 2, 2, 0.6);
		m_Door.translate(VECTOR3D(1, 1, 0));
		m_Door.rotate(VECTOR4D(m_Angle, 0, 1, 0));
		m_Door.translate(VECTOR3D(-1, -1, 0));
		m_Door.translate(VECTOR3D(pos.x, pos.y, pos.z));
        m_Door.onTexture(door);
        m_Door.draw();
        m_Door.offTexture();
    }
    
    void Door::open(){
        if(m_Angle < 90.0f)
            m_Angle += 0.5f;
    }
    
    void Door::close(){
        if(m_Angle > 0.0f)
            m_Angle -= 0.5f;
    }
}}
