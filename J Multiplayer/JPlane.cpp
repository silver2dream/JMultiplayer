#include "JPlane.h"
#include <GL/freeglut.h>

void JPlane::Render()
{
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-Scale, 0.0f, -Scale);
	glVertex3f(-Scale, 0.0f, Scale);
	glVertex3f(Scale, 0.0f, Scale);
	glVertex3f(Scale, 0.0f, -Scale);
	glEnd();
}

