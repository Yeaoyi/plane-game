#pragma once
#ifndef BULLET_H
#define BULLET_H

class Bullet {
public:
    Bullet(int startX, int startY, int direction);
    void move();
    void render() const;

private:
    int x, y;
    int speed;
    int direction;
};

#endif
