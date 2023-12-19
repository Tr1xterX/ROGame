#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_GAME_OVER_SYSTEM_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_GAME_OVER_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/scenes/context.h>

class GameOverSystem : public ISystem {
 private:
  Context* ctx_;

  void GameOver();

 protected:
  void OnUpdate() override;

 public:
  GameOverSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* ctx)
      : ISystem(entity_manager, system_manager), ctx_(ctx) {}
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SYSTEMS_GAME_OVER_SYSTEM_H_
