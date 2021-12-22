#ifndef _CRCHARACTER_H_

#define _CRCHARACTER_H_

#include "CASSET.h"
#include "CLANE.h"

class CRCHARACTER {
private:
    friend class CGAME;
    friend class CLANE;

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

    int checkCollision(CROBJECT*& obj);

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
    void save(ofstream& of);
    void load(ifstream& inf);

    bool isBehindRoad(CROAD& road);
    bool isNearRoad(CROAD& road);
};

#endif // !_CRCHARACTER_H_
