#include "CRBLOCK.h"

CRBLOCK::CRBLOCK(string textureFileName, double x, double y, float scale) : CROBJECT(x, y, scale) {
	texture = &CASSET::GetInstance().textureMap[textureFileName];
	setUpTexture();
}

int CRBLOCK::type()
{
	return Constants::BLOCK;
}

void CRBLOCK::move(double x, double y) {

}

bool CRBLOCK::isCar()
{
	return false;
}
