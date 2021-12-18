#ifndef CROAD_

#define CROAD_

#include "Constants.h"
#include "CASSET.h"
#include "CRCARFACTORY.h"
#include "CRBLOCKFACTORY.h"

class CROAD
{
protected:
    float m_originX;
    float m_originY;

    float objScale;

    float disOrigin;
    float dis;
    bool playing;
    sf::Texture* texture;
    sf::Sprite sprite;
    CRCARFACTORY carFac;
    CRCARFACTORY carFac1;
    CRBLOCKFACTORY blcFac;
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
    sf::Vector2f getPosition();
    float getDis();
    //virtual
    virtual bool is_road() = 0;
    virtual void drawSubObj(sf::RenderWindow& window) = 0;
    virtual void shiftSubObj(char UorD) = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    virtual int typeSound() = 0;
    void setPlaying();

    //get total lane
    static double getNumRoads();
};


#endif // !CROAD_
