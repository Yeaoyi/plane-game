#include "Bullet.h"
#include <iostream>

Bullet::Bullet(int startX, int startY, int direction)
    : x(startX), y(startY), speed(10), direction(direction) {
    // 初始化子弹位置、速度和方向
}

void Bullet::move() {
    // 处理子弹移动逻辑
    y += direction * speed;
}

void Bullet::render() const {
    std::cout << "\033[" << y << ";" << x << "H" << ".";
}
