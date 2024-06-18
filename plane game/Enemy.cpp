#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int startX, int startY) : x(startX), y(startY), speed(3) {
    // 初始化敌人位置和速度
}

void Enemy::move() {
    // 处理敌人移动逻辑
    y += speed;
}

void Enemy::render() const {
    std::cout << "\033[" << y << ";" << x << "H" << "E";
}
