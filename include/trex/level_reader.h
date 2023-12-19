#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_LEVEL_READER_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_LEVEL_READER_H_

#include "lib/ecs/entity_manager.h"
#include "trex/ilevel-reader.h"
#include <fstream>
#include <string>

class TextLevelReader : public ILevelReader {
public:
    void ReadLevel(const std::string& filePath, EntityManager* entityManager) override;
};

#endif // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_TREX_LEVEL_READER_H_
