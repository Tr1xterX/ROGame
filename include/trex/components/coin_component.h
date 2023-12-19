#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COIN_COMPONENT_H
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COIN_COMPONENT_H

#include <lib/ecs/component.h>

class CoinComponent : public IComponent {
public:
    int coin_cost_;
    int coin_multi_;
    int is_processed_;

    CoinComponent(int coin_cost) : coin_cost_(coin_cost) {}
};
#endif // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COIN_COMPONENT_H
