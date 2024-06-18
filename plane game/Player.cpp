#include "Player.h"
#include <iostream>

Player::Player() : x(10), y(10), speed(1) {
    // ��ʼ�����λ�ú��ٶ�
}

void Player::moveUp() {
    y -= speed;
}

void Player::moveDown() {
    y += speed;
}

void Player::moveLeft() {
    x -= speed;
}

void Player::moveRight() {
    x += speed;
}

void Player::shoot() {
    // �����������߼�
}

void Player::render() const {
    std::cout << "\033[" << y << ";" << x << "H" << "P";
}

void Player::increaseScore(int points) {
    score += points;
}
