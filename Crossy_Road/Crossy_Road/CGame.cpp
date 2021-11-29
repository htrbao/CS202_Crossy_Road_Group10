#include "CGame.h"

//Private function
void CGame::initializeVariable()
{
	this->window = nullptr;
}

void CGame::initWindow()
{
	this->videoMode.height = SCREEN_HEIGHT;
	this->videoMode.width = SCREEN_WIDTH;
	this->window = new sf::RenderWindow(this->videoMode, "CROSSY ROAD", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor | Destructor
CGame::CGame()
{
	this->initializeVariable();
	this->initWindow();
}

CGame::~CGame()
{
	delete this->window;
}

//Accessors
const bool CGame::running() const
{
	return this->window->isOpen();
}

//Other function
void CGame::pollEvent()
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
}

//Other function
void CGame::update()
{
	pollEvent();
}
void CGame::render()
{
	this->window->clear();

	//draw obj
	this->window->display();
}