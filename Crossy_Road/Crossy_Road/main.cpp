#include "CGAME.h"

int main() {
	CGAME game;
	sf::SoundBuffer* buffer = &CASSET::GetInstance().soundMap["CROSSY"];
	sf::Sound sound;
	sound.setBuffer(*buffer);
	sound.setLoop(true);
	sound.play();
	game.run();
	return 0;
}