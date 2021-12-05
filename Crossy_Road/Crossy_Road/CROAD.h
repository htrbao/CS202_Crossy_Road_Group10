#ifndef CROAD_

#define CROAD_

#include "Constants.h"
#include "CASSET.h"
#include "CRCARFACTORY.h"

class CROAD
{
protected:
    float m_originX;
    float m_originY;

    float objScale;

    sf::Texture* texture;
    sf::Sprite sprite;
private:
    static double numOfRoad;
public:
    //constructor | destructor
    CROAD(bool half_scale = false);
    ~CROAD();
    //other function
    bool checkOutWindow(sf::RenderWindow& window);
    bool checkOutWindow2(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void shiftObject(char UorD);
    virtual void drawSubObj(sf::RenderWindow& window) = 0;
    virtual void shiftSubObj(char UorD) = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    sf::Vector2f getPosition();
    //virtual
    virtual bool is_road() = 0;

    //get total lane
    static double getNumRoads();
};


#endif // !CROAD_
