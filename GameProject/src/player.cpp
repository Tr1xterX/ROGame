#include <BearLibTerminal.h>
#include "./player.h"

void Player::Move() {
    if (control.IsUP()) {
        y_ -= 1;
        steps_++;
        hunger_--;
    }
    if (control.IsDown()) {
        y_ += 1;
        steps_++;
        hunger_--;
    }
    if (control.IsLeft()) {
        x_ -= 1;
        steps_++;
        hunger_--;
    }
    if (control.IsRight()) {
        x_ += 1;
        steps_++;
        hunger_--;
    }
}

void Player::Render() {
    terminal_color("cyan");
    terminal_put(x_, y_, symbol);
    terminal_color("cyan");
}

void Player::Update() {
    Move();
    Render();
}

void Player::CoinsCollected() {
    coinCollected_++;
}

int Player::GetCoinsCollected() const {
    return coinCollected_;
}

int Player::GetStep() const {
    return steps_;
}

int Player::GetX() const {
    return x_;
}

int Player::GetY() const {
    return y_;
}

void Player::EatFood(int food) {
    hunger_ += food;
    if (hunger_ > max_hunger) {
        hunger_ = max_hunger;
    }
}

int Player::GetHunger() const {
    return hunger_;
}

bool Player::IsDead() const {
    return hunger_ <= 0;
}

bool Player::CancelMove() const {
    return true;
}

