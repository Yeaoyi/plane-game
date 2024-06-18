#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Utilities.h"
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    void init();
    void processInput();
    void update();
    void render();
    void floatBullet();
    void enemyFighter();
    void handleCollisions();
    void checkGameOver();

    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    int score;
    bool isRunning;
};

#endif
