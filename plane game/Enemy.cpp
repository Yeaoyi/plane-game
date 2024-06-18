#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int startX, int startY) : x(startX), y(startY), speed(3) {
    // ��ʼ������λ�ú��ٶ�
}

void Enemy::move() {
    // ��������ƶ��߼�
    y += speed;
}

void Enemy::render() const {
    std::cout << "\033[" << y << ";" << x << "H" << "E";
}
