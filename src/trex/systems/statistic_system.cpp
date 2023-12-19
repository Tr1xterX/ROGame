#include "trex/systems/statistic_system.h"
#include <trex/components/coin_component.h>
#include <trex/components/statistic_component.h>
#include "lib/ecs/entity_manager.h"


static bool Filter(const Entity& entity1, const Entity& entity2) {
    return entity1.Contains<StatisticComponent>() && entity2.Contains<CoinComponent>();
}

void StatisticSystem::OnUpdateEntity(Entity* entity1, Entity* entity2) const {
    auto sc = entity1->Get<StatisticComponent>();
    auto cc = entity2->Get<CoinComponent>();

    sc->coins_ += cc->coin_cost_ * cc-> coin_multi_;
}

void StatisticSystem::OnUpdate() {
    for (auto& entity1 : GetEntityManager()) {
        for (auto& entity2 : GetEntityManager()) {
            if (Filter(entity1, entity2)) {
                OnUpdateEntity(&entity1, &entity2);
            }
        }
    }
}

StatisticSystem::StatisticSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
        : ISystem(entity_manager, system_manager) {}
