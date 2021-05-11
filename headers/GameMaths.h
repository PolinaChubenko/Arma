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
std::pair<float, float> operator-(std::pair<float, float> p1, std::pair<float, float> p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
std::pair<float, float> operator+(std::pair<float, float> p1, std::pair<float, float> p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
float distance(std::pair<float, float> from, std::pair<float, float> to) {
    std::pair<float, float> vector = to - from;
    return static_cast<float>(std::hypot(vector.first, vector.second));
}

#endif //ARMA_GAMEMATHS_H
