#include "CRBLOCK.h"

CRBLOCK::CRBLOCK(string textureFileName, double x, double y) : CROBJECT(x, y, 1) {
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
