#include "roadside.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "staticobject.h"
#include <SOIL/SOIL.h>

using namespace Micromachines;

GLuint	texture[1];

int Roadside::loadGLtextures() const{
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
		(
		"C:/Users/gil/Documents/micromachines/textures/plank.jpg", //trocar este caminho para o vosso absolute path
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texture[0] == 0)
		return false;


	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	return true;                                        // Return Success
}

Roadside::Roadside()
{

}

Roadside::~Roadside()
{

}

void Roadside::draw() const
{
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);



    if(glIsEnabled(GL_LIGHTING)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glBegin(GL_QUADS);
            glNormal3f(0.0, 0.0, 1.0);
            GLfloat delta = 0.1;
            for (int i = -40; i < 40; i++){
                for (int j = -40; j < 40; j++){
					glTexCoord2f(j*delta, i*delta);
					glVertex3f(j*delta, i*delta, -0.2);

					glTexCoord2f((j + 1)*delta, i*delta);
					glVertex3f((j + 1)*delta, i*delta, -0.2);

					glTexCoord2f((j + 1)*delta, (i + 1)*delta);
					glVertex3f((j + 1)*delta, (i + 1)*delta, -0.2);

					glTexCoord2f(j*delta, (i + 1)*delta);
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

