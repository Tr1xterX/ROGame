#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_OBSTACLES_CONTROL_SYSTEM_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_OBSTACLES_CONTROL_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/ecs/entity.h>
#include "lib/ecs/engine.h"

class ObstaclesSystem : public ISystem {
  float starting_point_;

  bool Filter(const Entity& entity) const;
  void OnEachEntity(Entity* entity) const;

 public:
    Engine* engine_;
  ObstaclesSystem(EntityManager* entity_manager, SystemManager* system_manager, float starting_point);

 protected:
  void OnUpdate() override;
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_OBSTACLES_CONTROL_SYSTEM_H_
