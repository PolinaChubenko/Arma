#ifndef ARMA_GAMEMATHS_H
#define ARMA_GAMEMATHS_H

#include <cmath>

void normalise(std::pair<float, float>& vector) {
    float x = vector.first, y = vector.second;
    auto d = static_cast<float>(std::hypot(x, y));
    float norm_x = x / d;
    float norm_y = y / d;
    vector = {norm_x, norm_y};
}

//float distance(sf::Vector2f from, sf::Vector2f to) {
//    sf::Vector2f XY = from - to;
//    return static_cast<float>(hypot(XY.x, XY.y));
//}

#endif //ARMA_GAMEMATHS_H
