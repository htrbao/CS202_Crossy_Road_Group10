#ifndef CROAD_

#define CROAD_

#include "Constants.h"
#include "CASSET.h"
#include "CRCARFACTORY.h"
#include "CRBLOCKFACTORY.h"
#include <fstream>

class CROAD {
protected:
    friend class CGAME;

    float m_originX;
    float m_originY;

    float objScale;
    float dis;

    bool playing;
    bool playing2;

    sf::Texture* texture;
    sf::Sprite sprite;
private:
    static double numOfRoad;
public:
    //constructor | destructor
    CROAD(float x, float y, bool half_scale = false);
    CROAD(bool half_scale = false);
    virtual ~CROAD();
    //other function
    bool checkOutWindow(sf::RenderWindow& window);
    bool checkOutWindow2(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void shiftObject(char UorD);
    sf::Vector2f getPosition();
    float getDis();
    void save(ofstream& of);
    //virtual
    virtual bool is_road() = 0;
    virtual void drawSubObj(sf::RenderWindow& window) = 0;
    virtual void shiftSubObj(char UorD) = 0;
    virtual void update(sf::RenderWindow& window, float frac) = 0;
    virtual int typeSound() = 0;
    virtual int typeSound2() = 0;
    virtual bool isHighway() = 0;
    virtual deque<CROBJECT*>* getObjFac() = 0;
    virtual deque<CROBJECT*>* getObjFac2() = 0;
    virtual void saveDerivedRoad(ofstream& of) = 0;
    void setPlaying();
    void setPlaying2();

    //get total lane
    static double getNumRoads();
};


#endif // !CROAD_
