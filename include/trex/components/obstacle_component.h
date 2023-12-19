#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_OBSTACLE_COMPONENT_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_OBSTACLE_COMPONENT_H_

#include <lib/ecs/component.h>

/**
 * Иногда компоненты могут не иметь полей в принципе.
 * В таком случае такие компоненты выступают как тэги, которые
 * используются системами для определения типа сущности
 */
class ObstacleComponent : public IComponent {
  // Nothing to do, because it's a tag for systems
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_COMPONENTS_OBSTACLE_COMPONENT_H_
