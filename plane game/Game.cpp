#include "Game.h"
#include <iostream>
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h> // for Sleep()

Game::Game() : isRunning(true) {
    // ��ʼ����Ϸ���紴����ҷɻ��͵���
    hideCursor();
}

void Game::run() {
    while (isRunning) {
        clearScreen();
        processInput();
        updateScore(); // ���·���
        update();
        render();
        Sleep(100); // ������Ϸѭ�����ٶ�
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
    // ������Ϸ�߼�������Һ͵��˵�λ�á��ӵ����ƶ���
    for (auto& enemy : enemies) {
        enemy.move();
    }
    for (auto& bullet : bullets) {
        bullet.move();
    }
    // �����ײ��
}

void Game::render() {
    // ��Ⱦ��Ϸ����
    clearScreen();
    player.render();
    for (const auto& enemy : enemies) {
        enemy.render();
    }
    for (const auto& bullet : bullets) {
        bullet.render();
    }
    // ��ʾ��ǰ����
    std::cout << "Score: " << score << std::endl;
}

void Game::updateScore() {
    // ����Ϸ��ʵ�ֵ��߼���������ܵ��˻��߳������ʱ��ȿ������ӷ����Ĳ���
    // �����ʾ��ÿ֡����1��
    score++;
}
