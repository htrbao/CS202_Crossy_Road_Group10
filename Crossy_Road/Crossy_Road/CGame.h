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
#include "CRGUI.h"
#include <fstream>

class CGAME
{
private:
	//Variables
	
	sf::Texture* snowTexture;
	sf::Sprite snow;
	sf::Sprite snowNext;

	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//Game sound
	sf::SoundBuffer* gameBuffer;
	sf::Sound gameSound;

	//Game obj
	CRGUI *menu;
	CROADFACTORY* roadFac;
	CRCHARACTER* player;

	//Private function
	void initializeVariable();
	void initWindow();
	void initMenu();

public:
	//Constructor | Destructor
	CGAME();
	~CGAME();

	//Accessors
	const bool running() const;

	//Other function
	bool checkMove();
	void pollEvent();
	void update();
	void render();
	void run();
	void save();
	void load();
};



#endif // !1

