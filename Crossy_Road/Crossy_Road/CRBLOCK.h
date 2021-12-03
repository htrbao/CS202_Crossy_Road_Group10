#ifndef _CRBLOCK_H_

#define _CR_BLOCK_H_

#include "CASSET.h"
#include "CROBJECT.h"

using namespace std;

class CRBLOCK : public CROBJECT {
private:
public:
	CRBLOCK(string textureFileName, double x, double y);
	void move(double x, double y);
};
#endif // !_CRBLOCK_H_
