
#include "JCube.h"
#include <GL/freeglut.h>

void JCube::Render()
{
	glPushMatrix();
	glColor3f(Color.X, Color.Y, Color.Z);
	glTranslatef(Position.X, Position.Y, Position.Z);
	glutSolidCube(Scale);
	glPopMatrix();
}

