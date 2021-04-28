#include "Assets.h"

Assets& Assets::getInstance() {
    static Assets instance;
    return instance;
}
void Assets::load(std::string source_dir) {
    if (!font.loadFromFile(source_dir + "calibri.ttf")) throw;
}
