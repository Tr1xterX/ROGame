#ifndef GAMEPROJECTESC_ILEVEL_READER_H
#define GAMEPROJECTESC_ILEVEL_READER_H

#include <iostream>
#include "lib/ecs/entity_manager.h"
class ILevelReader {
public:
    virtual ~ILevelReader() {}
    virtual void ReadLevel(const std::string& filePath, EntityManager* entityManager) = 0;
};
#endif //GAMEPROJECTESC_ILEVEL_READER_H
