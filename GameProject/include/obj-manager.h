#pragma once

#ifndef INCLUDE_OBJ_MANAGER_H_
#define INCLUDE_OBJ_MANAGER_H_

#include <vector>

#include "./coin.h"
#include "./food.h"
#include "./player.h"
#include "./wall.h"

class ObjectManager {
    Player *player_;

    std::vector<Coin> coins{
            {5,  10},
            {40, 15},
            {25, 5}};

    std::vector<Food> foods{
            {10, 5,  20},
            {50, 10, 10},
            {20, 8,  5}};

    std::vector<Wall> walls;

 public:
    explicit ObjectManager(Player *player) : player_(player) {}

    void Update();

    void addWall(int x, int y);

 private:
    bool CheckCollision(int x1, int y1, int x2, int y2);
};

#endif  // INCLUDE_OBJ_MANAGER_H_
