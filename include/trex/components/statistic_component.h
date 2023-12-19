#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_STATISTIC_COMPONENT_H
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_STATISTIC_COMPONENT_H

#include <lib/ecs/component.h>
class StatisticComponent : public IComponent {
public:
    int coins_ = 0;
    int food_ = 60;
    int health_= 666;
    int steps_ = 0;

    explicit StatisticComponent(int coins, int food, int health) : coins_(coins), food_(food), health_(health) {}
};

#endif //_HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_STATISTIC_COMPONENT_H
