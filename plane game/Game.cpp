#include "Game.h"
#include <iostream>
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h> // for Sleep()

Game::Game() : isRunning(true) {
    // 初始化游戏，如创建玩家飞机和敌人
    hideCursor();
}

void Game::run() {
    while (isRunning) {
        clearScreen();
        processInput();
        updateScore(); // 更新分数
        update();
        render();
        Sleep(100); // 控制游戏循环的速度
    }
}

void Game::processInput() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
        case 'w': // Up
            player.moveUp();
            break;
        case 's': // Down
            player.moveDown();
            break;
        case 'a': // Left
            player.moveLeft();
            break;
        case 'd': // Right
            player.moveRight();
            break;
        case ' ': // Shoot
            player.shoot();
            break;
        case 27: // ESC to exit
            isRunning = false;
            break;
        }
    }
}

void Game::update() {
    // 更新游戏逻辑，如玩家和敌人的位置、子弹的移动等
    for (auto& enemy : enemies) {
        enemy.move();
    }
    for (auto& bullet : bullets) {
        bullet.move();
    }
    // 检测碰撞等
}

void Game::render() {
    // 渲染游戏场景
    clearScreen();
    player.render();
    for (const auto& enemy : enemies) {
        enemy.render();
    }
    for (const auto& bullet : bullets) {
        bullet.render();
    }
    // 显示当前分数
    std::cout << "Score: " << score << std::endl;
}

void Game::updateScore() {
    // 在游戏中实现的逻辑，例如击败敌人或者持续存活时间等可以增加分数的操作
    // 这里简单示范每帧增加1分
    score++;
}
