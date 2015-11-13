#include "roadside.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "staticobject.h"

using namespace Micromachines;

Roadside::Roadside()
{

}

Roadside::~Roadside()
{

}

void Roadside::draw() const
{
	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat greenblue[] = { 0.0, 1.0, 1.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, greenblue);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, greenblue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

    if(glIsEnabled(GL_LIGHTING)) {
        glPushMatrix();
        glBegin(GL_QUADS);
            glNormal3f(0.0, 0.0, 1.0);
            GLfloat delta = 0.1;
            for (int i = -40; i < 40; i++){
                for (int j = -40; j < 40; j++){
                    glVertex3f(j*delta, i*delta, -0.2);
                    glVertex3f((j + 1)*delta, i*delta, -0.2);
                    glVertex3f((j + 1)*delta, (i + 1)*delta, -0.2);
                    glVertex3f(j*delta, (i + 1)*delta, -0.2);
                }
            }
        glEnd();
        glPopMatrix();
    }
    else {
        glColor3f(0.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -1.0f);
        glScalef(8.0f, 8.0f, 1.0f);
        glutSolidCube(1);
        glPopMatrix();
    }
}

void Roadside::update(double delta_t) {

}

