#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_STATISTIC_SYSTEM_H
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_STATISTIC_SYSTEM_H

#include <lib/ecs/system.h>

class Entity;

class StatisticSystem : public ISystem {
    void OnUpdateEntity(Entity* entity1, Entity* entity2) const;

 protected:
    void OnUpdate() override;

 public:
    StatisticSystem(EntityManager* entity_manager, SystemManager* system_manager);
};

#endif // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_STATISTIC_SYSTEM_H
