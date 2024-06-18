#ifndef PLAYER_H
#define PLAYER_H

#include "Bullet.h"
#include "Constants.h"
#include <vector>


class Player {
public:
    Player(int startX, int startY, int speed = 2, int lives = 3);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void shoot(std::vector<Bullet>& bullets);
    void render() const;
    int getX() const;
    int getY() const;
    int getLives() const;
    void loseLife();

private:
    int x, y;
    int width;  // 增加宽度和高度成员变量
    int height;
    int speed;
    int lives;
};

#endif
