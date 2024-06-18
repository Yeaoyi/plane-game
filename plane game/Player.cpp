#include "Player.h"

Player::Player(int startX, int startY, int speed, int lives) : x(startX), y(startY), speed(speed), lives(lives) {}

void Player::moveUp() {
    if (y > 0) y -= speed;
}

void Player::moveDown() {
    if (y < screenHeight - 1) y += speed;
}

void Player::moveLeft() {
    if (x > 0) x -= speed;
}

void Player::moveRight() {
    if (x < screenWidth - 1) x += speed;
}

void Player::shoot(std::vector<Bullet>& bullets) {
    bullets.emplace_back(x, y - 1, 2);
}


void Player::render() const {
    // 清屏
    system("cls");

    // 输出飞机
    for (int i = 0; i < height; ++i) {
        zeroXy(x, y + i);
        for (int j = 0; j < width; ++j) {
            std::cout << "X"; // 或者其他字符，例如 "X" 等
        }
    }
}



int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

int Player::getLives() const {
    return lives;
}

void Player::loseLife() {
    lives--;
}
