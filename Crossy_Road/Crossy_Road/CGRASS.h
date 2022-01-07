#ifndef CRGASS_

#define CRGASS_

#include "CROAD.h"


class CGRASS :
    public CROAD
{
private:
    bool is_above;
    const string asset_name_grass = "GRASS2";
    const string asset_name_grass_above = "GRASS";
    const float half_scale = 0.5;
    CRBLOCKFACTORY blcFac;
public:
    //constructor | destructor
    CGRASS(sf::Vector2f pos, bool above = false);
    CGRASS(float index = 1, bool above = false);
    CGRASS(float x, float y, bool above);
    ~CGRASS();

    //other function
    bool is_road();
    void drawSubObj(sf::RenderWindow& window);
    void shiftSubObj(char UorD);
    void update(sf::RenderWindow& window, float frac);
    int typeSound();
    int typeSound2();
    bool isHighway();
    deque<CROBJECT*>* getObjFac();
    deque<CROBJECT*>* getObjFac2();
    void saveDerivedRoad(ofstream& of);
};

#endif // !CRGASS_


