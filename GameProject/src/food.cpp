#include <BearLibTerminal.h>
#include "./food.h"


void Food::Update() {
    terminal_color("green");
    terminal_put(x, y, symbol);
    terminal_color("white");
}

int Food::GetX() const {
    return x;
}

int Food::GetY() const {
    return y;
}

int Food::GetFoodValue() const {
    return food_value;
}
