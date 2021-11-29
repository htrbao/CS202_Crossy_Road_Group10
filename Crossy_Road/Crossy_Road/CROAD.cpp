#include "CROAD.h"

CROAD::CROAD()
{
    numOfRoad++;
}

CROAD::~CROAD()
{
    numOfRoad--;
}

int CROAD::getNumRoads()
{
    return numOfRoad;
}
