#include "./wall.h"
#include <BearLibTerminal.h>

int Wall::GetX() const {
    return x;
}

int Wall::GetY() const {
    return y;
}

void Wall::Update() const {
    terminal_put(x, y, symbol);
}

