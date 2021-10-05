#include "MYGLFunction.h"

#include ".\include\GL\freeglut.h"
#include <Math.h>
#define PI 3.141592

void DrawFan(float x, float y, float z, float radius, float degree, int triCount)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, y, z);
	for (int i = 0; i <= triCount; i++)
	{
		glVertex3f(x + radius * cos(2.0f * PI / triCount * i),
			y + radius * sin(2.0f * PI / triCount * i),
			0);

		//
		if ((2.0f * PI / triCount * i) >= (degree * (PI / 180)))
			break;
	}
	glEnd();
}

void DrawTriangle(float x, float y, float z, float sideLength)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(x, y + sideLength * sqrt(3) * 0.5f * 2 / 3, z);
	glVertex3f(x - sideLength * 0.5f, y - sideLength * sqrt(3) * 0.5f * 1 / 3, z);
	glVertex3f(x + sideLength * 0.5f, y - sideLength * sqrt(3) * 0.5f * 1 / 3, z);
	glEnd();
}

void DrawCube(float x, float y, float z, float width, float depth, float height)
{
	glBegin(GL_POLYGON);
	glVertex3f(x - width * 0.5f, y - depth * 0.5f, z);
	glVertex3f(x + width * 0.5f, y - depth * 0.5f, z);
	glVertex3f(x + width * 0.5f, y + depth * 0.5f, z);
	glVertex3f(x - width * 0.5f, y + depth * 0.5f, z);
	glEnd();
}