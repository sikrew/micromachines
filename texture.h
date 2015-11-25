#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
namespace Micromachines {

class Texture
{
public:
    Texture(const std::string& filename, int type);
    ~Texture();

    void bind();
    void setTexParameteri(GLuint param, GLuint arg);
    void setTexEnvf(GLuint target, GLuint param, GLuint arg);

    GLuint getId() const;
    int getType() const;
    int getWidth() const;
    int getHeight() const;
    std::string getFileName() const;

private:
    std::string _filename;
    GLuint _id;
    int _type;
    int _width;
    int _height;

    bool loadTexture();
};

}// namespace Micromachines


#endif // TEXTURE_H
