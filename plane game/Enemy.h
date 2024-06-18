#pragma once
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int startX, int startY);
    void move();
    void render() const;

private:
    int x, y;
    int speed;
};

#endif
