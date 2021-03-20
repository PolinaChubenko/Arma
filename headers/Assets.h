#ifndef ARMA_ASSETS_H
#define ARMA_ASSETS_H

#pragma once
#include <SFML/Graphics.hpp>

class Assets {
public:
    sf::Font font;
public:
    static Assets& getInstance();
    void load();
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
void Assets::load() {
    if (!font.loadFromFile("sources/calibri.ttf")) throw;
}


#endif //ARMA_ASSETS_H
