#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <cstdlib> // was giving error C2381: 'exit' : redefinition; __declspec(noreturn) differs

#include <vector>

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

namespace Micromachines
{
    static const double PI = 3.14159265;
    static const double HALF_PI = 1.5707963;

	class Camera;
    class Car;

	class GameManager
	{
	public:
		GameManager();
		~GameManager();
		void display();
		void reshape(GLsizei w, GLsizei h);
        void keyPressed(unsigned char key, int x, int y);
        void keyReleased(unsigned char key, int x, int y);
        void specialKeyPressed(int key, int x, int y);
        void specialKeyReleased(int key, int x, int y);
		void onTimer();
		void idle();
		void update();
		void init();
		void drawFloor();

	private:
		std::vector<Camera*> _cameras;
		Camera* _activeCamera;

        Car *_car;

        long long _lastTime;
        double _dt;
	};
	
} // namespace Micromachines

#endif // GAMEMANAGER_H
