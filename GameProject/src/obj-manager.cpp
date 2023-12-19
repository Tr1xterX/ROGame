#include "./obj-manager.h"

bool ObjectManager::CheckCollision(int x1, int y1, int x2, int y2) {
    return x1 == x2 && y1 == y2;
}

void ObjectManager::addWall(int x, int y) {
    walls.push_back(Wall(x, y));
}

void ObjectManager::Update() {
    for (auto i = coins.begin(); i != coins.end();) {
        i->Update();

        if (CheckCollision(player_->GetX(), player_->GetY(), i->GetX(), i->GetY())) {
            player_->CoinsCollected();
            i = coins.erase(i);
        } else {
            ++i;
        }
    }

    for (auto i = foods.begin(); i != foods.end();) {
        i->Update();

        if (CheckCollision(player_->GetX(), player_->GetY(), i->GetX(), i->GetY())) {
            player_->EatFood(i->GetFoodValue());
            i = foods.erase(i);
        } else {
            ++i;
        }
    }

    for (const auto& wall : walls) {
        if (CheckCollision(player_->GetX(), player_->GetY(), wall.GetY(), wall.GetY())) {
            player_->CancelMove();
        }

        wall.Update();
    }
}


