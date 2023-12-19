#pragma once

#ifndef INCLUDE_WALL_H_
#define INCLUDE_WALL_H_

class Wall {
 public:
    char symbol = '#';

    Wall(int x, int y): x(x), y(y) {}

    int GetX() const;

    int GetY() const;

    void Update() const;

 private:
    int x;
    int y;
};

#endif  // INCLUDE_WALL_H_
