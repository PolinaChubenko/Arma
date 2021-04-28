#ifndef ARMA_ASSETS_H
#define ARMA_ASSETS_H

#include <SFML/Graphics.hpp>

class Assets {
public:
    sf::Font font;
public:
    static Assets& getInstance();
    void load(std::string);
private:
    Assets() = default;
    ~Assets() = default;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Assets& Assets::getInstance() {
    static Assets instance;
    return instance;
}
void Assets::load(std::string source_dir) {
    if (!font.loadFromFile(source_dir + "calibri.ttf")) throw;
}


#endif //ARMA_ASSETS_H
