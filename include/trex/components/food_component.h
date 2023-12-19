
#ifndef GAMEPROJECTESC_FOOD_COMPONENT_H
#define GAMEPROJECTESC_FOOD_COMPONENT_H

#include <lib/ecs/component.h>

class FoodComponent : public IComponent {
public:
    int food_cost_;
    int food_multi_;

    FoodComponent(int food_cost) : food_cost_(food_cost) {}
};

#endif //GAMEPROJECTESC_FOOD_COMPONENT_H
