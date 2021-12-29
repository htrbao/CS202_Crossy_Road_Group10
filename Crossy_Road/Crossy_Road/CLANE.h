#ifndef CLANE_

#define CLANE_

#include "CROAD.h"
#include "CASSET.h"
#include "CTRAFFIC.h"
#include "Constants.h"

class CLANE :
    public CROAD
{
private:
    CTRAFFIC traffic;
    const string asset_name_road_twoway = "LANE_N";
    const string asset_name_road_oneway = "LANE2_N";
    const float scale = 1;
    const float half_scale = 0.5;
    bool is_oneway;
    CRCARFACTORY carFac;
    CRCARFACTORY carFac1;
public:
    //constructor | destructor
    CLANE(sf::Vector2f pos, bool one_way = false);
    CLANE(float index = 1, bool one_way = false);
    CLANE(float x, float y, bool one_way, bool hasTraffic);
    ~CLANE();

    //other function
    bool is_road();
    void drawSubObj(sf::RenderWindow& window);
    void shiftSubObj(char UorD);
    void update(sf::RenderWindow& window);
    int typeSound();
    int typeSound2();
    bool isHighway();
    deque<CROBJECT*>* getObjFac();
    deque<CROBJECT*>* getObjFac2();
    void saveDerivedRoad(ofstream& of);
};

#endif // !CLANE_
