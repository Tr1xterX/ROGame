#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SCENES_GAME_OVER_SCENE_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SCENES_GAME_OVER_SCENE_H_

#include "lib/scenes/i_scene.h"
#include "trex/controls.h"

class GameOverScene : public IScene {
  const Controls& controls_;

 public:
  GameOverScene(Context* ctx, const Controls& controls);
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SCENES_GAME_OVER_SCENE_H_
