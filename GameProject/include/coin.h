#pragma once
#ifndef INCLUDE_COIN_H_
#define INCLUDE_COIN_H_

class Coin {
    char symbol = '$';

 public:
    Coin(int x, int y) : x(x), y(y) {}

    void Update();

    int GetX();

    int GetY();

 private:
    int x;
    int y;
};


#endif  // INCLUDE_COIN_H_
