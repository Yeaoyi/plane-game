#pragma once
class Player {
public:
    Player();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void shoot();
    void render() const;
    void increaseScore(int points); // 增加分数方法

private:
    int x, y;
    int speed;
    int score; // 分数变量
};
