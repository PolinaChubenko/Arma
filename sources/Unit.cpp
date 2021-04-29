#include "Unit.h"

Unit::Unit(int hp, int damage, float attackDistance, float attackFrequency, float speed) :
        hp(hp), damage(damage), attackDistance(attackDistance), attackFrequency(attackFrequency), speed(speed) {}
Unit::~Unit() = default;
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
int &Unit::changeHp() {
    return hp;
}


Spearman::Spearman(float x, float y) : Unit(50, 5, 38 + size, 0.9, 15.6),
                                       texture(size, 5) {
    position = {x - size, y - size};
    texture.setPosition(position);
}
void Spearman::getType() const {
    std::cout << "I am Spearman\n";
}
std::pair<float, float> Spearman::getPosition() const {
    return position;
}
UnitTexture &Spearman::getTexture() {
    texture.setHpText(hp);
    return texture;
}
void Spearman::setColor(Color color) {
    texture.setColor(color);
}
void Spearman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position);
}
void Spearman::hit(std::shared_ptr<Unit> &victim, float delta_time) {
    duration += delta_time;
    if (duration >= attackFrequency) {
        duration -= attackFrequency;
        victim->changeHp() -= damage;
    }
}


Swordsman::Swordsman(float x, float y) : Unit(30, 20, 28 + size, 1.0, 8.4),
                                         texture(size) {
    position = {x - size, y - size};
    texture.setPosition(position);
}
void Swordsman::getType() const {
    std::cout << "I am Swordsman\n";
}
std::pair<float, float> Swordsman::getPosition() const {
    return position;
}
UnitTexture &Swordsman::getTexture() {
    texture.setHpText(hp);
    return texture;
}
void Swordsman::setColor(Color color) {
    texture.setColor(color);
}
void Swordsman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position);
}
void Swordsman::hit(std::shared_ptr<Unit> &victim, float delta_time) {
    duration += delta_time;
    if (duration >= attackFrequency) {
        duration -= attackFrequency;
        victim->changeHp() -= damage;
    }
}



Bowman::Bowman(float x, float y) : Unit(18, 5, 150 + size, 3.5, 12.5),
                                   texture(size, 4) {
    position = {x - size, y - size};
    texture.setPosition(position);
}
void Bowman::getType() const {
    std::cout << "I am Bowman\n";
}
std::pair<float, float> Bowman::getPosition() const {
    return position;
}
UnitTexture &Bowman::getTexture() {
    texture.setHpText(hp);
    return texture;
}
void Bowman::setColor(Color color) {
    texture.setColor(color);
}
void Bowman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position);
}
void Bowman::hit(std::shared_ptr<Unit> &victim, float delta_time) {
    duration += delta_time;
    if (duration >= attackFrequency) {
        duration -= attackFrequency;
        victim->changeHp() -= damage;
    }
}
