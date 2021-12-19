#include "CGAME.h"

//Private function
double CROAD::numOfRoad = 0;
void CGAME::initializeVariable()
{
	srand((unsigned)time(0));
	this->window = nullptr;
}

void CGAME::initWindow()
{
	this->videoMode.height = Constants::SCREEN_HEIGHT;
	this->videoMode.width = Constants::SCREEN_WIDTH;
	this->window = new sf::RenderWindow(this->videoMode, "CROSSY ROAD", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);
	roadFac = new CROADFACTORY;
	player = new CRCHARACTER(this->window, 0, 512, 350);
	roadFac->initRoadGame(player);


}

void CGAME::initMenu()
{
	this->menu = new CRGUI(300,50);
}

//Constructor | Destructor
CGAME::CGAME()
{
	this->initializeVariable();
	this->initWindow();
	this->initMenu();
}

CGAME::~CGAME()
{
	delete roadFac;
	delete player;
	delete this->window;
}

//Accessors
const bool CGAME::running() const
{
	return this->window->isOpen();
}

//Other function
void CGAME::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->moveUp();
		roadFac->shiftObject('U');
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->moveRight();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player->moveDown();
		roadFac->shiftObject('D');
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player->moveLeft();
	}
}

void CGAME::run()
{
	while (running())
	{
		update();
		render();
	}
}

//Other function
void CGAME::update()
{
	this->menu->eventListener(this->window);
	if (this->menu->isClickEnter() == true)
	{
		pollEvent();
		roadFac->update(*this->window);
	}
	
}
void CGAME::render()
{
	this->window->clear();
	//draw obj
	roadFac->draw(*this->window);
	this->menu->draw(this->window);
	this->window->display();
}