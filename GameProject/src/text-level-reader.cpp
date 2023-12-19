#include <fstream>
#include <string>

#include "./text-level-reader.h"

TextLevelReader::TextLevelReader(const std::string& filename) : filename(filename) {}

void TextLevelReader::readLevel(ObjectManager& objectManager) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    std::string line;
    int y = 0;
    while (std::getline(file, line)) {
        int x = 0;
        for (char c : line) {
            if (c == '#') {
                objectManager.addWall(x, y);
            }
            x++;
        }
        y++;
    }

    file.close();
}
