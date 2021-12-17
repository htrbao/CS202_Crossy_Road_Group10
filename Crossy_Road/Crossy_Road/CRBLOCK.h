#ifndef _CRBLOCK_H_

#define _CRBLOCK_H_

#include "CASSET.h"
#include "CROBJECT.h"

using namespace std;

class CRBLOCK : public CROBJECT {
private:
public:
	CRBLOCK(string textureFileName, double x, double y);
	int type();
	void move(double x, double y);
	bool isCar();
};
#endif // !_CRBLOCK_H_
