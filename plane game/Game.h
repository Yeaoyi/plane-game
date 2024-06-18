#pragma once
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Utilities.h"
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    void processInput();
    void update();
    void render();
    void updateScore();

    Player player;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;

    bool isRunning;
    int score;
};

#endif
