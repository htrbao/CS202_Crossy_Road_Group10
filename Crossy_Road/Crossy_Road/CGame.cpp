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
	//this->window->setKeyRepeatEnabled(false);
	player = new CRCHARACTER(this->window, 0, 512, 350);
	initGame();
}

void CGAME::initGame()
{
	delete point;
	delete roadFac;
	point = new CPOINTHUD(Constants::pointFont, 100, Constants::SCREEN_WIDTH - 350, -30, -11);
	roadFac = new CROADFACTORY(player, point);
	roadFac->initRoadGame();
}

//Constructor | Destructor
CGAME::CGAME()
{
	//SNOW section
	snowTexture = &CASSET::GetInstance().textureMap["SNOW"];
	snow.setTexture(*snowTexture);
	snow.scale(1.5, 1.5);
	snowNext.setTexture(*snowTexture);
	snowNext.scale(1.5, 1.5);
	snowNext.setPosition(0, 0);
	long setUpY = snowTexture->getSize().y;
	snow.setPosition(0, -setUpY);
	//end SNOW section

	gui = new CRGUI(0, 0);
	gui->drawTest();

	game_state = MENU;

	this->initializeVariable();
	this->initWindow();
}

CGAME::~CGAME()
{
	delete roadFac;
	delete player;
	delete point;
	delete gui;
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
				if (collisionType == 3)
				{
					point->increaseP(5);
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
		if (game_state == PLAYING) continue;
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyReleased:
			//if (ev.key.code == sf::Keyboard::Escape)
				//this->window->close();
			switch (ev.key.code) {
			case sf::Keyboard::Up:
				gui->prevChoice();
				break;
			case sf::Keyboard::Right:
				break;
			case sf::Keyboard::Down:
				gui->nextChoice();
				break;
			case sf::Keyboard::Left:
				break;
			case sf::Keyboard::Enter:
				game_state = PLAYING;
				break;
			case sf::Keyboard::Escape:
				this->window->close();
				break;
			}
			break;
		}
	}
	if (game_state != PLAYING) return;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {/*
		snow.move(-Constants::shiftVelocityX, Constants::shiftVelocityX * tan(Constants::Beta));
		snowNext.move(-Constants::shiftVelocityX, Constants::shiftVelocityX * tan(Constants::Beta));*/
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {/*
		snow.move(Constants::shiftVelocityX, -Constants::shiftVelocityX * tan(Constants::Beta));
		snowNext.move(Constants::shiftVelocityX, -Constants::shiftVelocityX * tan(Constants::Beta));*/
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
	snowNext.move(0, 1);
	snow.move(0, 1);
	if (snow.getPosition().y == 0) {
		snowNext.setPosition(0, 0);
		long setUpY = snowTexture->getSize().y;
		snow.setPosition(0, -setUpY);
	}

	pollEvent();
	roadFac->update(*this->window);	
}
void CGAME::render()
{
	this->window->clear();
	//draw obj
	switch (game_state){
	case MENU:
		this->window->draw(snow);
		this->window->draw(snowNext);
		gui->draw(*this->window);
		break;
	case PLAYING:
		roadFac->draw(*this->window);
		this->window->draw(snow);
		this->window->draw(snowNext);
		break;
	case GAMEOVER:
		break;
	case PAUSE:
		break;
	}
	this->window->display();
}

void CGAME::save()
{
	ofstream file;
	file.open("game.dat", ios::binary);
	point->save(file);
	player->save(file);
	roadFac->save(file);
	file.close();
	cout << "save successfully\n";
}

void CGAME::load()
{
	ifstream file;
	file.open("game.dat", ios::binary);
	point->load(file);
	player->load(file);
	roadFac->load(file);
	file.close();
	cout << "load successfully\n";

}
