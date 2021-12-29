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
#include "CPOINTHUD.h"
#include <fstream>

enum GAME_STATUS {MENU, PLAYING, GAMEOVER, PAUSE};

class CGAME
{
private:
	//Variables
	
	int highestPoint;
	GAME_STATUS game_state;

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
	CRGUI* gui;
	CROADFACTORY* roadFac;
	CRCHARACTER* player;
	CPOINTHUD* point;

	//Private function
	void initializeVariable();
	void initWindow();
	void initGame();

public:
	//Constructor | Destructor
	CGAME();
	~CGAME();

	//Accessors
	const bool running() const;

	//Other function
	bool checkMove();
	void choiceMenu(int c);
	void choicePause(int c);
	void choiceGameOver(int c);
	void pollEvent();
	void update();
	void render();
	void run();
	void save();
	void load();
	void loadHighPoint();
	void updateHighPoint();
};



#endif // !1

