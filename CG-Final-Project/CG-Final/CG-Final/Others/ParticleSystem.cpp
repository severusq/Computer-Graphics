#include <iostream>
#include <time.h>
#include "ParticleSystem.h"

float pShininess = 16;
float pemit[3][4] = { { 1, 0.62, 0.114, 1 }, { 1, 0.843, 0.114, 1 }, { 1, 0.137, 0.114, 1 } };

void ParticleSystem::init()
{
	int i;
	srand(unsigned(time(0)));
	for (i = 0; i < ptlCount; i++)
	{
		int cidx = rand() % 3;
		Particle tmp = {
			VECTOR3D(0, 0, 0),	//Position
			VECTOR3D(((rand() % 200) - 50.0f) / 100.0f, ((rand() % 200)) / 100.0f, ((rand() % 200 - 50.0f)) / 100.0f),	//velocity
			VECTOR3D(0, 0, 0),	//Acceleration
			pemit[cidx][0], pemit[cidx][1], pemit[cidx][2],	//Emitted Color
			0.0f,	//age
			3.0f + 0.1*(rand() % 10),	//Life
			0.1f,	//Size
			false,
		};
		particles.push_back(tmp);
	}
	sphere = gluNewQuadric();
}

//Simulate the state of all particles
void ParticleSystem::simulate(float dt)
{
	aging(dt);
	applyGravity();
	kinematics(dt);
}


//a loop to counting the age of the particles
void ParticleSystem::aging(float dt)
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].age += dt;
		//Age out then die
		if (particles[i].age > particles[i].life)
			particles[i].died = true;
	}

	bool re = true;
	for (int i = 0; i < particles.size(); ++i)
		if (!particles[i].died)
			re = false;

	if (re)
		for (int i = 0; i < particles.size(); ++i)
		{
			particles[i].died = false;
			particles[i].age = 0;
			particles[i].position = VECTOR3D(0, 0, 0);
			particles[i].veclocity = VECTOR3D(((rand() % 20) - 5.0f) / 10.0f, ((rand() % 20)) / 10.0f, ((rand() % 20 - 5.0f)) / 10.0f); 	//velocity
		}
}

//applying gravity system to the scene
void ParticleSystem::applyGravity()
{
	for (int i = 0; i < particles.size(); i++)
		particles[i].acceleration = VECTOR3D(0, gravity, 0);
}


void ParticleSystem::kinematics(float dt)
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].position.x += particles[i].veclocity.x * dt;
		particles[i].position.y += particles[i].veclocity.y * dt;
		particles[i].position.z += particles[i].veclocity.z * dt;
		particles[i].veclocity.x += particles[i].acceleration.x * dt;
		particles[i].veclocity.y += particles[i].acceleration.y * dt;
		particles[i].veclocity.z += particles[i].acceleration.z * dt;
	}
}

//the render function
void ParticleSystem::render()
{
	for (int i = 0; i < particles.size(); i++)
	{
		if (!particles[i].died)
		{
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ONE_MINUS_SRC_ALPHA);
			Particle &p = particles[i];
			glPushMatrix();
			glTranslatef(p.position.x, p.position.y, p.position.z);
			gluSphere(sphere, p.size, 32, 32);
			glPopMatrix();
		}
	}

	//Reset Color for world
	glColor4f(1, 1, 1, 1);
}