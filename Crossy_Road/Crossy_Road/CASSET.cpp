#include "CASSET.h"

void CASSET::initSound(string soundFileName) {
	if (!soundMap[soundFileName].loadFromFile("assets/sound/" + soundFileName + ".wav")) {
		cout << "Cannot load assets/sound/" << soundFileName << ".wav\n";
		return;
	}
	cout << soundFileName << "loaded successfully\n";
}

void CASSET::initTexture(string textureFileName, bool isPlayer) {
	string filepath = isPlayer ? "assets/player/" + textureFileName + ".png" : "assets/graphics/" + textureFileName + ".png";
	if (!textureMap[textureFileName].loadFromFile(filepath)) {
		cout << "Cannot load " << filepath << endl;
		return;
	}
	textureMap[textureFileName].setSmooth(true);
	cout << textureFileName << " loaded successfully" << endl;
}

CASSET::CASSET() {
	//load player
	initTexture("CAT_1_NE", 1);
	initTexture("CAT_1_NW", 1);
	initTexture("CAT_1_SE", 1);
	initTexture("CAT_1_SW", 1);
	//load obstacle
	initTexture("ambulance_NW");
	initTexture("ambulance_SE");
	initTexture("car_1_NW");
	initTexture("car_1_SE");
	initTexture("car_2_NW");
	initTexture("car_2_SE");
	initTexture("delivery_NW");
	initTexture("delivery_SE");
	initTexture("deliveryFlat_NW");
	initTexture("deliveryFlat_SE");
	initTexture("firetruck_NW");
	initTexture("firetruck_SE");
	initTexture("garbageTruck_NW");
	initTexture("garbageTruck_SE");
	initTexture("police_NW");
	initTexture("police_SE");
	initTexture("race_NW");
	initTexture("race_SE");
	initTexture("raceFuture_NW");
	initTexture("raceFuture_SE");
}