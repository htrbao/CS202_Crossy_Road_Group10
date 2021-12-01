#ifndef _CASSET_H_

#define _CASSET_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <unordered_map>

using namespace std;

// load all assets to the game.

class CASSET {
private:
	CASSET();
	CASSET(const CASSET&) {};

	CASSET& operator=(const CASSET&) {};
	void initSound(string soundFileName);
	void initTexture(string textureFileName, bool isPlayer = false);
public:
	static CASSET& GetInstance() {
		static CASSET instance;
		return instance;
	}
	unordered_map<string, sf::SoundBuffer> soundMap;
	unordered_map<string, sf::Texture> textureMap;
};

#endif // !_CASSET_H_
