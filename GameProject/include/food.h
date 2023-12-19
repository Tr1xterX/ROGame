#pragma once

#ifndef INCLUDE_FOOD_H_
#define INCLUDE_FOOD_H_

class Food {
    char symbol = '%';

 public:
    Food(int x, int y, int food_value) : x(x), y(y), food_value(food_value) {}

    void Update();

    int GetX() const;

    int GetY() const;

    int GetFoodValue() const;

 private:
    int x;
    int y;
    int food_value;
};

#endif  // INCLUDE_FOOD_H_
