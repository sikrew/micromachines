#include "lightpoint.h"

using namespace Micromachines;
#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif


LightPoint::LightPoint(int id, Vector3& ambient, Vector3& diffuse, Vector3& specular)
    : LightSource(id, ambient, diffuse, specular)
{

}

LightPoint::LightPoint(int id)
    : LightSource(id)
{
    setAmbient(0.0, 0.0, 0.0, 1.0);
    setDiffuse(1.0, 1.0, 1.0, 1.0);
    setSpecular(0.4, 0.4, 0.4, 1.0);

    glLightfv(_id, GL_AMBIENT, _ambient);
    glLightfv(_id, GL_DIFFUSE, _diffuse);
    glLightfv(_id, GL_SPECULAR, _specular);
    glLightf(_id, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(_id, GL_LINEAR_ATTENUATION, 5.0);
    glLightf(_id, GL_QUADRATIC_ATTENUATION, 10.0);
}

LightPoint::~LightPoint()
{

}

