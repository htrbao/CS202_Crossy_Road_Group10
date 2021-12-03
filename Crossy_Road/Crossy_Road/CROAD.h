
#pragma once
#include "Constants.h"
#include "CASSET.h"



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
    void draw(sf::RenderWindow& window);
    void shiftObject(char UorD);
    bool checkOutWindow(sf::RenderWindow& window);
    sf::Vector2f getPosition();
    //virtual
    virtual bool is_road() = 0;
    
    //get total lane
    static double getNumRoads();
};

