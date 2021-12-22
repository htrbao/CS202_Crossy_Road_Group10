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
	player = new CRCHARACTER(this->window, 0, 512, 350);
	roadFac = new CROADFACTORY(player);
	roadFac->initRoadGame();
	//load();
}

void CGAME::initMenu()
{
	this->menu = new CRGUI(300, 50);
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

bool CGAME::checkMove() {
	for (auto road : roadFac->roadQueue) {
		if (player->isNearRoad(*road)) {
			deque<CROBJECT*>* curRoad = (road->getObjFac() != nullptr ? road->getObjFac() : road->getObjFac2());
			for (long i = 0; i < curRoad->size(); i++) {
				int collisionType = player->checkCollision(curRoad->at(i));
				if (collisionType % 3) {
					return false;
				}
			}
		}
	}
	return true;
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
				//this->window->close();
			break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->moveUp();
		roadFac->shiftObject('U');
		if (!checkMove()) {
			roadFac->shiftObject('D');
		}
		if (player->side != CRCHARACTER::UP) player->setSide(CRCHARACTER::UP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->moveRight();
		if (!checkMove()) {
			player->moveLeft();
		}
		if (player->side != CRCHARACTER::RIGHT) player->setSide(CRCHARACTER::RIGHT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player->moveDown();
		roadFac->shiftObject('D');
		if (!checkMove()) {
			roadFac->shiftObject('U');
		}
		if (player->side != CRCHARACTER::DOWN) player->setSide(CRCHARACTER::DOWN);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player->moveLeft();
		if (!checkMove()) {
			player->moveRight();
		}
		if (player->side != CRCHARACTER::LEFT) player->setSide(CRCHARACTER::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		save();
		this->window->close();
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

void CGAME::save()
{
	ofstream file;
	file.open("game.dat", ios::binary);
	player->save(file);
	roadFac->save(file);
	file.close();
	cout << "save successfully\n";
}

void CGAME::load()
{
	ifstream file;
	file.open("game.dat", ios::binary);
	player->load(file);
	roadFac->load(file);
	file.close();
	cout << "load successfully\n";

}
