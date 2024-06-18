#include "Player.h"
#include <iostream>

Player::Player() : x(10), y(10), speed(1) {
    // 初始化玩家位置和速度
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
    // 处理玩家射击逻辑
}

void Player::render() const {
    std::cout << "\033[" << y << ";" << x << "H" << "P";
}

void Player::increaseScore(int points) {
    score += points;
}
