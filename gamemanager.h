#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <cstdlib> // was giving error C2381: 'exit' : redefinition; __declspec(noreturn) differs

#include <vector>

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <SOIL/SOIL.h>

namespace Micromachines
{
    static const double PI = 3.14159265;
    static const double HALF_PI = 1.5707963;

	class Camera;
    class GameObject;
    class DynamicObject;
    class Car;
	class Roadside;
	class Cheerio;
	class Butter;
	class Orange;
    class LightSource;
    class LightPoint;

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
		void setLightswitch(int state);
		int getLightswitch() const;
		void toggleLightswitch();
		void setLightingCalculation(int state);
		int getLightingCalculation() const;
		void toggleLightingCalculation();

	private:
		std::vector<Camera*> _cameras;
		Camera* _activeCamera;
        Car *_car;
		Roadside *_roadside;
		Cheerio *_cheerio[210];
		Butter *_butter[5];
		Orange *_orange[3];
        std::vector<GameObject *> _objectList;
        std::vector<LightPoint *> _lightpointList;

        long long _lastTime;
        double _dt;
        bool _paused;

		int _lightswitch = 0;
		int _lightingCalculation = 0;

        void collided(Car *dObj);
	};
	
} // namespace Micromachines

#endif // GAMEMANAGER_H
