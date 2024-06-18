#ifndef BULLET_H
#define BULLET_H

#include "Utilities.h"

class Bullet {
public:
    Bullet(int startX, int startY, int speed = 1);
    void move();
    void render() const;
    int getX() const;
    int getY() const;
    bool isDestroyed() const;

private:
    int x, y;
    int speed;
    bool destroyed;
};

#endif
