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
    void increaseScore(int points); // ���ӷ�������

private:
    int x, y;
    int speed;
    int score; // ��������
};
