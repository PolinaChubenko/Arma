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

#endif //ARMA_ASSETS_H
