#include "Game.h"
#include <iostream>
#include <conio.h>

Game::Game() : player(screenWidth / 2, screenHeight - 2, 2, 3), score(0), isRunning(true) {
    init();
    hideCursor();
}

void Game::init() {
    bullets.clear();
    enemies.clear();
    score = 0;
    system("color 0E"); // 设置控制台的字符颜色为白色，背景色为黑色
}

void Game::run() {
    while (isRunning) {
        processInput();
        update();
        render();
        Sleep(50);
    }
}

void Game::processInput() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
        case 'w':
            player.moveUp();
            break;
        case 's':
            player.moveDown();
            break;
        case 'a':
            player.moveLeft();
            break;
        case 'd':
            player.moveRight();
            break;
        case ' ':
            player.shoot(bullets);
            break;
        case 27:
            isRunning = false;
            break;
        }
    }
}


void Game::update() {
    floatBullet();
    enemyFighter();
    handleCollisions();
    checkGameOver(); // 检查游戏结束条件
}

void Game::render() {
    clearScreen();
    player.render();
    for (const auto& bullet : bullets) {
        bullet.render();
    }
    for (const auto& enemy : enemies) {
        enemy.render();
    }
    zeroXy(0, 0);
    std::cout << "Score: " << score << "  Lives: " << player.getLives() << std::endl;
}

void Game::floatBullet() {
    for (auto& bullet : bullets) {
        bullet.move();
    }
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& bullet) {
        return bullet.isDestroyed();
        }), bullets.end());
}

void Game::enemyFighter() {
    static int enemyTimer = 0;
    if (enemyTimer++ % 10 == 0) {
        enemies.push_back(Enemy(rand() % screenWidth, 0, 1));
    }
    for (auto& enemy : enemies) {
        enemy.move();
    }
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& enemy) {
        return enemy.getY() >= screenHeight;
        }), enemies.end());
}

void Game::handleCollisions() {
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end(); ) {
        bool bulletDestroyed = false;
        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
            if (bulletIt->getX() == enemyIt->getX() && bulletIt->getY() == enemyIt->getY()) {
                bulletIt = bullets.erase(bulletIt);
                enemyIt = enemies.erase(enemyIt);
                score += 10;
                bulletDestroyed = true;
                break;
            }
            else {
                ++enemyIt;
            }
        }
        if (!bulletDestroyed) {
            ++bulletIt;
        }
    }

    for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
        if (enemyIt->getX() == player.getX() && enemyIt->getY() == player.getY()) {
            player.loseLife();
            enemyIt = enemies.erase(enemyIt);
        }
        else {
            ++enemyIt;
        }
    }
}

void Game::checkGameOver() {
    if (player.getLives() <= 0) {
        isRunning = false;
        clearScreen();
        zeroXy(screenWidth / 2 - 5, screenHeight / 2);
        std::cout << "Game Over!" << std::endl;
        zeroXy(screenWidth / 2 - 7, screenHeight / 2 + 1);
        std::cout << "Final Score: " << score << std::endl;
        Sleep(2000); // 等待2秒后退出游戏
    }
}
