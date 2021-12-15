#ifndef _CRTREE_H_

#define _CRTREE_H_

#include "CROBJECT.h"
#include "CASSET.h"
#include "Constants.h"

class CRTREE : public CROBJECT {
private:
public:
	CRTREE(string textureFileName, double x, double y, double scale);
	int type();
	void move(double x, double y);
};

#endif // !_CRTREE_H_
