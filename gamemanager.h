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
    display();
    reshape();
    keyPressed();
    onTimer();
    idle();
    update();
    init();
};
} //namespace Arkanoid
#endif // GAMEMANAGER_H
