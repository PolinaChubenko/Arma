#include "Color.h"

Color::Color(ColorType type) {
    switch (type) {
        case RED:
            color = sf::Color::Red;
            break;
        case BLUE:
            color = sf::Color::Blue;
            break;
        case BLACK:
            color = sf::Color::Black;
            break;
        case WHITE:
            color = sf::Color::White;
            break;
        case MAGENTA:
            color = sf::Color::Magenta;
            break;
        case CYAN:
            color = sf::Color::Cyan;
            break;
        default:
            break;
    }
}
sf::Color Color::getColor() {
    return color;
}
