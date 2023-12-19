#pragma once
#ifndef INCLUDE_TEXT_LEVEL_READER_H_
#define INCLUDE_TEXT_LEVEL_READER_H_

#include <vector>
#include <string>
#include <iostream>

#include "./i-level-reader.h"

class TextLevelReader : public ILevelReader {
 public:
    explicit TextLevelReader(const std::string &filename);

    void readLevel(ObjectManager &objectManager) override;

 private:
    std::string filename;
};


#endif  // INCLUDE_TEXT_LEVEL_READER_H_
