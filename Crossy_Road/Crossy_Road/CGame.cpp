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
	loadHighPoint();
}

void CGAME::initGame()
{
	delete point;
	delete roadFac;
	delete player;
	player = new CRCHARACTER(this->window, 0, 520, 350, SFX);
	point = new CPOINTHUD(Constants::pointFont, 100, Constants::SCREEN_WIDTH - 350, -30, -11);
	roadFac = new CROADFACTORY(player, point, SFX);
	roadFac->initRoadGame();
	game_state = PLAYING;
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

	allGame = sf::Sound(CASSET::GetInstance().soundMap["CROSSY"]);
	allGame.setLoop(true);
	allGame.setVolume(10);
	allGame.play();

	SFX = true;

	gui = new CRGUI(0, 0);
	gui->drawMenu();
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
			deque<CROBJECT*>* curRoad[2] = { road->getObjFac(), road->getObjFac2() };
			for (long j = 0; j < 2; j++) {
				if (curRoad[j])
				{
					for (long i = 0; i < curRoad[j]->size(); i++) {
						int collisionType = player->checkCollision(curRoad[j]->at(i));
						if (collisionType % 3) {
							if (collisionType == 2) {
								game_state = GAMEOVER;
								updateHighPoint();
								gui->drawGameOver(point->getPoint(), highestPoint);
							}
							return false;
						}
						if (collisionType == 3)
						{
							point->increaseP(5);
						}
					}
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
				if (game_state == MENU)
					choiceMenu(gui->getChoice());
				else if (game_state == GAMEOVER)
					choiceGameOver(gui->getChoice());
				else if (game_state == PAUSE)
					choicePause(gui->getChoice());
				else if (game_state == SETTING)
					choiceSetting(gui->getChoice());
					
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		game_state = PAUSE;
		gui->drawPause();
	}
	else 
		player->idle(this->ev.type);
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
	if (roadFac)
	{
		if (game_state == PLAYING) {
			checkMove();
			roadFac->update(*this->window, 1 + (point->getPoint() % 15) / 10);
		}
	}
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
		this->window->draw(snow);
		this->window->draw(snowNext);
		gui->draw(*this->window);
		break;
	case PAUSE:
		roadFac->draw(*this->window);
		this->window->draw(snow);
		this->window->draw(snowNext);
		gui->draw(*this->window);
		break;
	case SETTING:
		this->window->draw(snow);
		this->window->draw(snowNext);
		gui->draw(*this->window);
		break;
	}
	this->window->display();
}

void CGAME::save()
{
	ofstream file;
	file.open(Constants::gameFile, ios::binary);
	point->save(file);
	player->save(file);
	roadFac->save(file);
	file.close();
	cout << "save successfully\n";
}

void CGAME::load()
{
	delete point;
	delete roadFac;
	delete player;
	player = new CRCHARACTER(this->window, 0, 520, 350, SFX);
	point = new CPOINTHUD(Constants::pointFont, 100, Constants::SCREEN_WIDTH - 350, -30, -11);
	roadFac = new CROADFACTORY(player, point, SFX);
	ifstream file;
	file.open(Constants::gameFile, ios::binary);
	if (file.fail()) {
		initGame();
		file.close();
		return;
	}
	point->load(file);
	player->load(file);
	roadFac->load(file);
	file.close();
	cout << "load successfully\n";
	game_state = PLAYING;
}

void CGAME::choicePause(int c)
{
	if (c == 0)
	{
		gui->drawMenu();
		game_state = MENU;
	}
	else if (c == 1)
	{
		game_state = PLAYING;
	}
	else if (c == 2) {
		game_state = SETTING;
		gui->drawSetting(&allGame, SFX);
		prevGame_state = PAUSE;
	}
	else {
		save();
		this->window->close();
	}
}

void CGAME::choiceMenu(int c)
{
	if (c == 0)
		initGame();
	else if (c == 1)
		load();
	else if (c == 2) {
		game_state = SETTING;
		gui->drawSetting(&allGame, SFX);
		prevGame_state = MENU;
	}
	else if (c == 3)
		this->window->close();
}

void CGAME::choiceGameOver(int c)
{
	if (c == 0)
	{
		initGame();
	}
	else if (c == 1)
	{
		game_state = MENU;
		gui->drawMenu();
	}
	else if (c == 2) {
		game_state = SETTING;
		gui->drawSetting(&allGame, SFX);
		prevGame_state = GAMEOVER;
	}
	else if (c == 3)
	{
		this->window->close();
	}
}

void CGAME::choiceSetting(int c) {
	if (c == 0)
	{
		if (roadFac)
			roadFac->SFXManage();
		if (player)
			player->SFXManage();
		SFX = !SFX;
		gui->drawSetting(&allGame, SFX);
	}
	else if (c == 1)
	{
		if (allGame.getVolume() == 0.0f) {
			allGame.setVolume(10);
		}
		else allGame.setVolume(0.0f);

		gui->drawSetting(&allGame, SFX);
	}
	else if (c == 2) {
		if (allGame.getVolume() == 0.0f) {
			allGame.setVolume(10);
		}
		if (roadFac)
			roadFac->SFXReset();
		if (player)
			player->SFXReset();
		SFX = true;
		gui->drawSetting(&allGame, SFX);
	}
	else if (c == 3)
	{
		game_state = prevGame_state;
		if (game_state == MENU) {
			gui->drawMenu();
		}
		else if (game_state == PAUSE) {
			gui->drawPause();
		}
		else if (game_state == GAMEOVER) {
			gui->drawGameOver(point->getPoint(), highestPoint);
		}
	}
}

void CGAME::loadHighPoint()
{
	ifstream file;
	file.open(Constants::pointFile, ios::binary);
	if (file.fail())
		highestPoint = 0;
	else
		file.read((char*)&highestPoint, sizeof(highestPoint));
	file.close();
}

void CGAME::updateHighPoint()
{
	if (point->getPoint() > highestPoint)
	{
		highestPoint = point->getPoint();
		ofstream file;
		file.open(Constants::pointFile, ios::binary);
		file.write((char*)&highestPoint, sizeof(highestPoint));
		file.close();
	}
	
}
