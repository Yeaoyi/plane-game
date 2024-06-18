#include "Bullet.h"
#include <iostream>

Bullet::Bullet(int startX, int startY, int direction)
    : x(startX), y(startY), speed(10), direction(direction) {
    // ��ʼ���ӵ�λ�á��ٶȺͷ���
}

void Bullet::move() {
    // �����ӵ��ƶ��߼�
    y += direction * speed;
}

void Bullet::render() const {
    std::cout << "\033[" << y << ";" << x << "H" << ".";
}
