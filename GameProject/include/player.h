#pragma once

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <vector>

#include "./control.h"
#include "./food.h"

class Player {
    char symbol = '@';
    const Control &control;

    void Render();

    void Move();

 public:
    Player(const Control &control, int x, int y)
        : control(control), x_(x), y_(y) {}

    void Update();

    void CoinsCollected();

    int GetCoinsCollected() const;

    int GetStep() const;

    int GetX() const;

    int GetY() const;

    void EatFood(int food);

    int GetHunger() const;

    bool IsDead() const;

    bool CancelMove() const;
 private:
    int x_;
    int y_;
    int steps_ = 0;
    int coinCollected_ = 0;
    int hunger_ = 99;
    int max_hunger = 200;
};

#endif  // INCLUDE_PLAYER_H_

