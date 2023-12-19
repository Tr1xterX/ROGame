#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_TRANSFORM_COMPONENT_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_TRANSFORM_COMPONENT_H_
#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

class TransformComponent : public IComponent {
 public:
  Vec2 pos_;

  explicit TransformComponent(const Vec2& pos) : pos_(pos) {}
};
#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_TRANSFORM_COMPONENT_H_
