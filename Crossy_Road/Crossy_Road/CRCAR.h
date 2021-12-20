#ifndef _CRCAR_H_

#define _CRCAR_H_

#include "CROBJECT.h"

class CRCAR : public CROBJECT {
private:
public:
	CRCAR(string textureFileName, float x, float y, double speed, int direction);
	int type();
	void move(float x, float y, float frac = 1);
};

#endif // !_CRCAR_H_
