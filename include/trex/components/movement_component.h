#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_MOVEMENT_COMPONENT_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_MOVEMENT_COMPONENT_H_

#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

class MovementComponent : public IComponent {
public:
    Vec2 speed_;
    Vec2 direction_;
    bool checkwalkUp_ = true;
    bool checkwalkDown_ = true;
    bool checkwalkRight_ = true;
    bool checkwalkLeft_ = true;
    explicit MovementComponent(Vec2 speed, Vec2 dir = ZeroVec2) : speed_(speed), direction_(dir) {}
};
#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_MOVEMENT_COMPONENT_H_
