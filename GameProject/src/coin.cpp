#include <BearLibTerminal.h>

#include "./coin.h"

void Coin::Update() {
    terminal_color("yellow");
    terminal_put(x, y, symbol);
    terminal_color("white");
}

int Coin::GetX() {
    return x;
}

int Coin::GetY() {
    return y;
}
