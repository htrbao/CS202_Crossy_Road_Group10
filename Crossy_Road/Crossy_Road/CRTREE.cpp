#include "CRTREE.h"

CRTREE::CRTREE(string textureFileName, double x, double y, double scale) : CROBJECT(x, y, scale) {
	texture = &CASSET::GetInstance().textureMap[textureFileName];

	setUpTexture();
}

void CRTREE::move(double x, double y) {

}
