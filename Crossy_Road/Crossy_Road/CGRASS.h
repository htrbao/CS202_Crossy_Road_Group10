#ifndef CRGASS_

#define CRGASS_

#include "CROAD.h"
class CGRASS :
    public CROAD
{
private:
    const string asset_name_grass = "GRASS2";
    const string asset_name_grass_above = "GRASS";
    const float half_scale = 0.5;
public:
    //constructor | destructor
    CGRASS(sf::Vector2f pos, bool above = false);
    CGRASS(float index = 1, bool above = false);
    ~CGRASS();

    //other function
    bool is_road();
    void drawSubObj(sf::RenderWindow& window);
    void shiftSubObj(char UorD);
    void update(sf::RenderWindow& window);
};

#endif // !CRGASS_


