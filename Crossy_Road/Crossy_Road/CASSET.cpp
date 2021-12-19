#include "CASSET.h"

void CASSET::initSound(string soundFileName) {
	if (!soundMap[soundFileName].loadFromFile("assets/sounds/" + soundFileName + ".wav")) {
		cout << "Cannot load assets/sound/" << soundFileName << ".wav\n";
		return;
	}
	cout << soundFileName << "loaded successfully\n";
}
//assets / graphics / firetruck_SE.png
void CASSET::initTexture(string textureFileName, bool isPlayer) {
	string filepath = isPlayer ? "assets/player/" + textureFileName + ".png" : "assets/graphics/" + textureFileName + ".png";
	if (!textureMap[textureFileName].loadFromFile(filepath)) {
		cout << "Cannot load " << filepath << endl;
		return;
	}
	textureMap[textureFileName].setSmooth(true);
	cout << filepath << " loaded successfully" << endl;
}

CASSET::CASSET() {
	//load player
	initTexture("CAT", 1);
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
	//road
	initTexture("LANE_N");
	initTexture("LANE2_N");
	initTexture("GRASS");
	initTexture("GRASS2");
	//block
	initTexture("BLOCK_1");
	initTexture("BLOCK_2");
	initTexture("BLOCK_3");
	initTexture("BLOCK_4");
	initTexture("BLOCK_5");


	initTexture("BLOCK_SNOW_1");
	initTexture("BLOCK_SNOW_2");
	initTexture("BLOCK_SNOW_3");
	initTexture("BLOCK_SNOW_4");
	initTexture("BLOCK_SNOW_5");
	//coin
	initTexture("COIN_1");
	initTexture("COIN_2");
	//tree
	initTexture("TREE");
	initTexture("TREESNOW");
	initTexture("TREELARGE");
	initTexture("TREEPINE");
	//menu
	initTexture("MENU");
	initTexture("SCORE");
	initTexture("PAUSE1");
	//sound
	initSound("CROSSY");
	initSound("CAR_LARGE");
	initSound("CAR_SMALL");
	initSound("POLICE");
	initSound("GAME_SOUND");
	initSound("JUMP");
	initSound("BIRDS");
	initSound("COIN");
}