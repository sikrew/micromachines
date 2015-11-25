#include "texture.h"

#ifdef linux
    #include <IL/il.h>
#endif

using namespace Micromachines;


bool Texture::loadTexture()
{

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &_id);
    glBindTexture(_type, _id);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Filtering
    glTexParameteri(_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Linear Filtering


    unsigned char* image;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,_width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    return true;
}

Texture::Texture(const std::string &filename, int type)
{
    _filename = filename;
    _type = type;

    //loadTexture();
}

Texture::~Texture()
{

}

void Texture::bind()
{
    glBindTexture(_type,_id);
}

void Texture::setTexParameteri(GLuint param, GLuint arg)
{
    glBindTexture(_type, _id);
    glTexParameteri(_type, param, arg);
}

void Texture::setTexEnvf(GLuint target, GLuint param, GLuint arg)
{
    glBindTexture(_type, _id);
    glTexEnvf(target, param, arg);
}

GLuint Texture::getId() const
{
    return _id;
}

int Texture::getType() const
{
    return _type;
}

int Texture::getWidth() const
{
    return _width;
}

int Texture::getHeight() const
{
    return _height;
}

std::string Texture::getFileName() const
{
    return _filename;
}
