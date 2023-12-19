#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_PRECOLLISION_SYSTEM_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_PRECOLLISION_SYSTEM_H_

#include <lib/ecs/system.h>
class PrecollisionSystem : public ISystem {
public:
    PrecollisionSystem(EntityManager* entity_manager, SystemManager* system_manager);

protected:
    void OnUpdate() override;
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_PRECOLLISION_SYSTEM_H_
