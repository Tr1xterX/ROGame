#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_JUMP_CONTROL_SYSTEM_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_JUMP_CONTROL_SYSTEM_H_

#include <lib/ecs/system.h>
#include <trex/controls.h>

class Entity;  // forward declaration because we include this class in the cpp file

class ControlSystem : public ISystem {
  const Controls& controls_;
  void OnUpdateEntity(Entity* entity) const;

 protected:
  void OnUpdate() override;

 public:
  ControlSystem(EntityManager* entity_manager, SystemManager* system_manager, const Controls& controls);
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_JUMP_CONTROL_SYSTEM_H_
