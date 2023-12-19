#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SCENES_GAME_SCENE_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SCENES_GAME_SCENE_H_

#include <lib/ecs/engine.h>
#include <lib/scenes/i_scene.h>
#include <trex/controls.h>


class GameScene : public IScene {
  const int width_ = 80;
  const int ground_y_ = 15;
  const float step_size_ = 1;
  const Engine engine{};
  const Controls& controls;

 public:
  GameScene(Context* const ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_SCENES_GAME_SCENE_H_
