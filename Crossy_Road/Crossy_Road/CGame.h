#ifndef CGAME_

#define CGAME_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Constants.h"
#include "CRCAR.h"
#include "CROADFACTORY.h"
#include "CRBLOCK.h"
#include "CRTREE.h"
#include "CRCOIN.h"
#include "CRCHARACTER.h"

class CGAME
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Game sound
	sf::SoundBuffer* gameBuffer;
	sf::Sound gameSound;

	//Game obj
	CROADFACTORY* roadFac;
	CRCHARACTER* player;

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
	void run();
};



#endif // !1

