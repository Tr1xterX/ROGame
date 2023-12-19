#pragma once
#ifndef INCLUDE_I_LEVEL_READER_H_
#define INCLUDE_I_LEVEL_READER_H_

#include <vector>

#include "./obj-manager.h"
#include "./wall.h"

class ILevelReader {
 public:
    virtual ~ILevelReader() {}
    virtual void readLevel(ObjectManager& objectManager) = 0;
};

#endif  // INCLUDE_I_LEVEL_READER_H_
