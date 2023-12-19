#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_JUMP_COMPONENT_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_JUMP_COMPONENT_H_

#include <lib/ecs/component.h>

class JumpComponent : public IComponent {
 public:
  float max_speed_y_;
  float ground_y_;

  JumpComponent(float max_speed_y, float ground_y)
      : max_speed_y_(max_speed_y), ground_y_(ground_y) {}
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_JUMP_COMPONENT_H_
