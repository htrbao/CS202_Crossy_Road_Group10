#ifndef _CRTREE_H_

#define _CRTREE_H_

#include "CROBJECT.h"
#include "CASSET.h"

class CRTREE : public CROBJECT {
private:
public:
	CRTREE(string textureFileName, double x, double y, double scale);
	void move(double x, double y);
};

#endif // !_CRTREE_H_
