#ifndef ARMA_COLOR_H
#define ARMA_COLOR_H

#include "Enums.h"
#include "Assets.h"

class Color {
private:
    sf::Color color;
public:
    explicit Color(ColorType);
    sf::Color getColor();
};

#endif //ARMA_COLOR_H
