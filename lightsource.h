#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "entity.h"

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif


namespace Micromachines
{
class LightSource : public Entity
{
public:
    LightSource(int id, Vector3 &ambient, Vector3 &diffuse, Vector3 &specular);
    LightSource(int id);
    bool isEmitting() const;
    void setState(const bool emitting);

    virtual void display();
    void setAmbient(GLfloat x, GLfloat y, GLfloat z, GLfloat a);
    void setDiffuse(GLfloat x, GLfloat y, GLfloat z, GLfloat a);
    void setSpecular(GLfloat x, GLfloat y, GLfloat z, GLfloat a);

protected:
    int _id;
    GLfloat _ambient[4];
    GLfloat _diffuse[4];
    GLfloat _specular[4];
    bool _emitting;
};
} // Namespace Micromachines
#endif // LIGHTSOURCE_H
