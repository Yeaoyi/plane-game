#include "Enemy.h"

Enemy::Enemy(int startX, int startY, int speed) : x(startX), y(startY), speed(speed) {}

void Enemy::move() {
    y += speed;
}

void Enemy::render() const {
    zeroXy(x, y);
    std::cout << "V";
}

int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}
