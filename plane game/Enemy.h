#ifndef ENEMY_H
#define ENEMY_H

#include "Utilities.h"

class Enemy {
public:
    Enemy(int startX, int startY, int speed = 1);
    void move();
    void render() const;
    int getX() const;
    int getY() const;

private:
    int x, y;
    int speed;
};

#endif
