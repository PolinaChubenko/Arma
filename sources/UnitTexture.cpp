#include "UnitTexture.h"

UnitTexture::UnitTexture(float size, int count) {
    if (count)
        shape = sf::CircleShape(size, count);
    else
        shape = sf::CircleShape(size);
    hp_text.setFont(Assets::getInstance().font);
    hp_text.setCharacterSize(16);
    hp_text.setFillColor(Color(WHITE).getColor());
}
void UnitTexture::setPosition(std::pair<float, float> pos) {
    shape.setPosition(pos.first, pos.second);
    hp_text.setPosition(pos.first + 12, pos.second + 10);
}
void UnitTexture::setHpText(int hp) {
    hp_text.setString(std::to_string(hp));
}
void UnitTexture::setColor(Color color) {
    shape.setFillColor(color.getColor());
    shape.setOutlineThickness(1);
    shape.setOutlineColor(Color(BLACK).getColor());
}
sf::CircleShape& UnitTexture::getShape() {
    return shape;
}
sf::Text& UnitTexture::getHpText() {
    return hp_text;
}
