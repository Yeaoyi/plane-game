#include "Bullet.h"

Bullet::Bullet(int startX, int startY, int speed) : x(startX), y(startY), speed(speed), destroyed(false) {}

void Bullet::move() {
    y -= speed;
    if (y < 0) {
        destroyed = true;
    }
}

void Bullet::render() const {
    if (!destroyed) {
        zeroXy(x, y);
        std::cout << "|";
    }
}

int Bullet::getX() const {
    return x;
}

int Bullet::getY() const {
    return y;
}

bool Bullet::isDestroyed() const {
    return destroyed;
}
