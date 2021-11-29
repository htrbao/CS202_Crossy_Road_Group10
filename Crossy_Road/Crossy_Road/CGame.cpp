#include "CGAME.h"

//Private function
void CGAME::initializeVariable()
{
	this->window = nullptr;
}

void CGAME::initWindow()
{
	this->videoMode.height = SCREEN_HEIGHT;
	this->videoMode.width = SCREEN_WIDTH;
	this->window = new sf::RenderWindow(this->videoMode, "CROSSY ROAD", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor | Destructor
CGAME::CGAME()
{
	this->initializeVariable();
	this->initWindow();
}

CGAME::~CGAME()
{
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
}

//Other function
void CGAME::update()
{
	pollEvent();
}
void CGAME::render()
{
	this->window->clear();

	//draw obj
	this->window->display();
}