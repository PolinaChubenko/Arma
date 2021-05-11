#ifndef ARMA_UNITTEXTURE_H
#define ARMA_UNITTEXTURE_H

#include "Assets.h"
#include "Color.h"

class UnitTexture {
private:
    sf::Text hp_text;
    sf::CircleShape shape;
public:
    explicit UnitTexture(float size, int count = 0);
    void setPosition(std::pair<float, float>);
    void setHpText(int);
    void setColor(Color);
    sf::CircleShape& getShape();
    sf::Text& getHpText();
};

#endif //ARMA_UNITTEXTURE_H
