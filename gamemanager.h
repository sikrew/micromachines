#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

namespace Micromachines {
class GameManager
{
public:
    GameManager();
    ~GameManager();
    void display();
    void reshape(GLsizei w, GLsizei h);
    void keyPressed();
    void onTimer();
    void idle();
    void update();
    void init();
};
} //namespace Arkanoid
#endif // GAMEMANAGER_H
