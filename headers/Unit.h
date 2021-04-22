#ifndef ARMA_UNIT_H
#define ARMA_UNIT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameMaths.h"

class Unit {
protected:
    constexpr static const float size = 25;
    int hp;
    int damage;
    float attackDistance;
    float attackFrequency;
    float speed;
    sf::Text hp_text;
public:
    explicit Unit(int, int, float, float, float);
    void getAllInfo() const;
    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] float getAttackDistance() const;
    [[nodiscard]] float getAttackFrequency() const;
    [[nodiscard]] float getSpeed() const;
    sf::Text& getHpText();
    int& changeHp();

    virtual void getType() const = 0;
    [[nodiscard]] virtual std::pair<float, float> getPosition() const = 0;
    virtual sf::CircleShape& getTexture() = 0;
    virtual void setColor(sf::Color) = 0;

    virtual void move(std::pair<float, float>, float) = 0;
    virtual void hit(std::shared_ptr<Unit>&) = 0;
    virtual ~Unit() = 0;
};


class Spearman : public Unit {
protected:
    std::pair<float, float> position;
    sf::CircleShape texture = sf::CircleShape(size, 5);
public:
    Spearman(float, float);
    void getType() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
    void move(std::pair<float, float>, float) override;
    void hit(std::shared_ptr<Unit>&) override;
};


class Swordsman : public Unit {
protected:
    std::pair<float, float> position;
    sf::CircleShape texture = sf::CircleShape(size);
public:
    Swordsman(float, float);
    void getType() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
    void move(std::pair<float, float>, float) override;
    void hit(std::shared_ptr<Unit>&) override;
};


class Bowman : public Unit {
protected:
    std::pair<float, float> position;
    sf::CircleShape texture = sf::CircleShape(size, 4);
public:
    Bowman(float, float);
    void getType() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
    void move(std::pair<float, float>, float) override;
    void hit(std::shared_ptr<Unit>&) override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/
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


Spearman::Spearman(float x, float y) : Unit(50, 35, 38 + size, 0.9, 15.6) {
    position = {x - size, y - size};
    texture.setPosition(position.first, position.second);
}
void Spearman::getType() const {
    std::cout << "I am Spearman\n";
}
std::pair<float, float> Spearman::getPosition() const {
    return position;
}
sf::CircleShape &Spearman::getTexture() {
    return texture;
}
void Spearman::setColor(sf::Color color) {
    texture.setFillColor(color);
    texture.setOutlineThickness(1);
    texture.setOutlineColor(sf::Color(0, 0, 0));
}
void Spearman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}
void Spearman::hit(std::shared_ptr<Unit> &victim) {
    victim->changeHp() -= getDamage();
}


Swordsman::Swordsman(float x, float y) : Unit(30, 110, 28 + size, 1.0, 8.4) {
    position = {x - size, y - size};
    texture.setPosition(position.first, position.second);
}
void Swordsman::getType() const {
    std::cout << "I am Swordsman\n";
}
std::pair<float, float> Swordsman::getPosition() const {
    return position;
}
sf::CircleShape &Swordsman::getTexture() {
    return texture;
}
void Swordsman::setColor(sf::Color color) {
    texture.setFillColor(color);
    texture.setOutlineThickness(1);
    texture.setOutlineColor(sf::Color(0, 0, 0));
}
void Swordsman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}
void Swordsman::hit(std::shared_ptr<Unit> &victim) {
    victim->changeHp() -= getDamage();
}



Bowman::Bowman(float x, float y) : Unit(18, 35, 150 + size, 3.5, 12.5) {
    position = {x - size, y - size};
    texture.setPosition(position.first, position.second);
}
void Bowman::getType() const {
    std::cout << "I am Bowman\n";
}
std::pair<float, float> Bowman::getPosition() const {
    return position;
}
sf::CircleShape &Bowman::getTexture() {
    return texture;
}
void Bowman::setColor(sf::Color color) {
    texture.setFillColor(color);
    texture.setOutlineThickness(1);
    texture.setOutlineColor(sf::Color(0, 0, 0));
}
void Bowman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}
void Bowman::hit(std::shared_ptr<Unit> &victim) {
    victim->changeHp() -= getDamage();
}

#endif //ARMA_UNIT_H
