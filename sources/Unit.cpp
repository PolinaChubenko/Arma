#include "Unit.h"

Unit::Unit(int hp, int damage, float attackDistance, float attackFrequency, float speed) :
        hp(hp), damage(damage), attackDistance(attackDistance), attackFrequency(attackFrequency), speed(speed) {}
Unit::~Unit() = default;
void Unit::getAllInfo() const {
    std::cout << "I have: " << getHp() << "-hp; ";
    std::cout << getDamage() << "-damage; ";
    std::cout << getAttackDistance() << "-attack distance; ";
    std::cout << getAttackFrequency() << "-attack frequency; ";
    std::cout << getSpeed() << "-speed.\n\n";
}
int Unit::getHp() const {
    return hp;
}
int Unit::getDamage() const {
    return damage;
}
float Unit::getAttackDistance() const {
    return attackDistance;
}
float Unit::getAttackFrequency() const {
    return attackFrequency;
}
float Unit::getSpeed() const {
    return speed;
}
sf::Text &Unit::getHpText() {
    hp_text = sf::Text(std::to_string(getHp()), Assets::getInstance().font, 16);
    hp_text.setPosition(getPosition().first + 12, getPosition().second + 10);
    return hp_text;
}
int &Unit::changeHp() {
    return hp;
}


Spearman::Spearman(float x, float y) : Unit(50, 5, 38 + size, 0.9, 15.6) {
    position = {x - size, y - size};
    texture.setPosition(position.first, position.second);
}
void Spearman::getType() const {
    std::cout << "I am Spearman\n";
}
std::pair<float, float> Spearman::getPosition() const {
    return position;
}
UnitShape &Spearman::getTexture() {
    return texture;
}
void Spearman::setColor(Color color) {
    texture.setFillColor(color.getColor());
    texture.setOutlineThickness(1);
    texture.setOutlineColor(Color(BLACK).getColor());
}
void Spearman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}
void Spearman::hit(std::shared_ptr<Unit> &victim, float delta_time) {
    duration += delta_time;
    if (duration >= attackFrequency) {
        duration -= attackFrequency;
        victim->changeHp() -= damage;
    }
}


Swordsman::Swordsman(float x, float y) : Unit(30, 20, 28 + size, 1.0, 8.4) {
    position = {x - size, y - size};
    texture.setPosition(position.first, position.second);
}
void Swordsman::getType() const {
    std::cout << "I am Swordsman\n";
}
std::pair<float, float> Swordsman::getPosition() const {
    return position;
}
UnitShape &Swordsman::getTexture() {
    return texture;
}
void Swordsman::setColor(Color color) {
    texture.setFillColor(color.getColor());
    texture.setOutlineThickness(1);
    texture.setOutlineColor(Color(BLACK).getColor());
}
void Swordsman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}
void Swordsman::hit(std::shared_ptr<Unit> &victim, float delta_time) {
    duration += delta_time;
    if (duration >= attackFrequency) {
        duration -= attackFrequency;
        victim->changeHp() -= damage;
    }
}



Bowman::Bowman(float x, float y) : Unit(18, 5, 150 + size, 3.5, 12.5) {
    position = {x - size, y - size};
    texture.setPosition(position.first, position.second);
}
void Bowman::getType() const {
    std::cout << "I am Bowman\n";
}
std::pair<float, float> Bowman::getPosition() const {
    return position;
}
UnitShape &Bowman::getTexture() {
    return texture;
}
void Bowman::setColor(Color color) {
    texture.setFillColor(color.getColor());
    texture.setOutlineThickness(1);
    texture.setOutlineColor(Color(BLACK).getColor());
}
void Bowman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}
void Bowman::hit(std::shared_ptr<Unit> &victim, float delta_time) {
    duration += delta_time;
    if (duration >= attackFrequency) {
        duration -= attackFrequency;
        victim->changeHp() -= damage;
    }
}
