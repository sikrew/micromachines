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
	class Camera;

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
		void drawFloor();

	private:
		std::vector<Camera*> _cameras;
		Camera* _activeCamera;
	};
	
} // namespace Micromachines

#endif // GAMEMANAGER_H
