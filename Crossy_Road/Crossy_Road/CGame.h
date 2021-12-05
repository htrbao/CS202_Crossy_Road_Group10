#ifndef CGAME_

#define CGAME_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>


#define SCREEN_WIDTH 473
#define SCREEN_HEIGHT 957

class CGAME
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Game obj

	//Private function
	void initializeVariable();
	void initWindow();

public:
	//Constructor | Destructor
	CGAME();
	~CGAME();

	//Accessors
	const bool running() const;

	//Other function
	void pollEvent();
	void update();
	void render();
};



#endif // !1

