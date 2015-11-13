#include "lightsource.h"

using namespace Micromachines;

LightSource::LightSource(int id, Vector3& ambient, Vector3& diffuse, Vector3& specular) :
    _id(id), _emitting(false)
{

    setAmbient(ambient.getX(), ambient.getY(), ambient.getZ(), 1.0);
    setDiffuse(diffuse.getX(), diffuse.getY(), diffuse.getZ(), 1.0);
    setSpecular(specular.getX(), specular.getY(), specular.getZ(), 1.0);

    glLightfv(_id, GL_AMBIENT, _ambient);
    glLightfv(_id, GL_DIFFUSE, _diffuse);
    glLightfv(_id, GL_SPECULAR, _specular);
}

LightSource::LightSource(int id) : _id(id), _emitting(false)
{
}

bool LightSource::isEmitting() const
{
    return _emitting;
}

void LightSource::setState(const bool emitting)
{
    _emitting = emitting;
}

void LightSource::display()
{
    GLfloat pos[4] = {(GLfloat)getPosition().getX(), (GLfloat)getPosition().getY(), (GLfloat)getPosition().getZ(), 1.0};

    glLightfv(_id, GL_POSITION, pos);

    if(_emitting && !glIsEnabled(_id)) {
        glEnable(_id);
    }
    else if (glIsEnabled(_id) && _emitting == false){
        glDisable(_id);
    }
}

void LightSource::setAmbient(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
    _ambient[0] = x;
    _ambient[1] = y;
    _ambient[2] = z;
    _ambient[3] = a;
}

void LightSource::setDiffuse(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
    _diffuse[0] = x;
    _diffuse[1] = y;
    _diffuse[2] = z;
    _diffuse[3] = a;
}

void LightSource::setSpecular(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
    _specular[0] = x;
    _specular[1] = y;
    _specular[2] = z;
    _specular[3] = a;
}
