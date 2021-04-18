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

float distance(std::pair<float, float> from, std::pair<float, float> to) {
    std::pair<float, float> vector = {to.first - from.first, to.second - from.second};
    return static_cast<float>(std::hypot(vector.first, vector.second));
}

#endif //ARMA_GAMEMATHS_H
