#include "texture.h"

#include <iostream>
#include "SOIL\SOIL.h"

using namespace Micromachines;


bool Texture::loadTexture()
{
	_id = SOIL_load_OGL_texture(_filename.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	if (_id == 0) {
		std::cout << "SOIL Error " << SOIL_last_result()  << " loading " << _filename << std::endl;
		return false;
	}

	glBindTexture(_type, _id);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Filtering
	glTexParameteri(_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Linear Filtering

	return true;
}

Texture::Texture(const std::string &filename)
{
    _filename = filename;
    _type = GL_TEXTURE_2D;

    loadTexture();
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
