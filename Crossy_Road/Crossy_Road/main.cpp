#include "CGAME.h"

int main() {
	sf::Sound allGame = sf::Sound(CASSET::GetInstance().soundMap["CROSSY"]);
	allGame.setLoop(true);
	allGame.play();

	CGAME game;
	game.run();
	cout << "OK to out!";
	return 0;
}