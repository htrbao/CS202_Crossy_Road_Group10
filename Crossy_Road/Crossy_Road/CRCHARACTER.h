#ifndef _CRCHARACTER_H_

#define _CRCHARACTER_H_

#include "CASSET.h"
#include "CLANE.h"
#include "CROBJECT.h"

class CRCHARACTER {
private:
    friend class CGAME;
    friend class CLANE;
    friend class CROBJECT;

    float mX, mY;
    int side;

    sf::SoundBuffer* buffer;
    sf::Sound sound;

    sf::Texture* textureSheet;
    sf::Texture* dieTexture;

    sf::Sprite sprite;
    sf::RenderWindow* window;
    void initTexture();
    void initSound();
public:
    static int UP, RIGHT, DOWN, LEFT;
    static int WIDTH, HEIGHT;
    static float SCALE;
    CRCHARACTER(sf::RenderWindow* window, int side, int x, int y);

    void setSide(int side);

    bool canMoveDown();
    bool canMoveUp();
    bool canMoveRight();
    bool canMoveLeft();

    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();

    void update();
    void render();

    bool isBehindRoad(CROAD& road);
    bool isNearRoand(CROAD& road);
};

#endif // !_CRCHARACTER_H_
