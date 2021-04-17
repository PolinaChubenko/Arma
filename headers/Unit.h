#ifndef ARMA_UNIT_H
#define ARMA_UNIT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameMaths.h"

class Unit {
protected:
    float size = 25;
public:
    void getAllInfo() const;
    virtual void getType() const = 0;
    [[nodiscard]] virtual int getHp() const = 0;
    [[nodiscard]] virtual int getDamage() const = 0;
    [[nodiscard]] virtual int getAttackDistance() const = 0;
    [[nodiscard]] virtual float getAttackFrequency() const = 0;
    [[nodiscard]] virtual float getSpeed() const = 0;
    [[nodiscard]] virtual std::pair<float, float> getPosition() const = 0;
    virtual sf::CircleShape& getTexture() = 0;
    virtual void setColor(sf::Color) = 0;
    virtual void move(std::pair<float, float>, float) = 0;
    virtual ~Unit() = 0;
};


class Spearman : public Unit {
protected:
    int hp = 50;
    int damage = 35;
    int attackDistance = 28;
    float attackFrequency = 0.9;
    float speed = 15.6;
    std::pair<float, float> position;
    sf::CircleShape texture = sf::CircleShape(size, 5);
public:
    Spearman(float, float);
    void getType() const override;
    [[nodiscard]] int getHp() const override;
    [[nodiscard]] int getDamage() const override;
    [[nodiscard]] int getAttackDistance() const override;
    [[nodiscard]] float getAttackFrequency() const override;
    [[nodiscard]] float getSpeed() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
    void move(std::pair<float, float>, float) override;
};


class Swordsman : public Unit {
protected:
    int hp = 30;
    int damage = 110;
    int attackDistance = 8;
    float attackFrequency = 1.0;
    float speed = 8.4;
    std::pair<float, float> position;
    sf::CircleShape texture = sf::CircleShape(size);
public:
    Swordsman(float, float);
    void getType() const override;
    [[nodiscard]] int getHp() const override;
    [[nodiscard]] int getDamage() const override;
    [[nodiscard]] int getAttackDistance() const override;
    [[nodiscard]] float getAttackFrequency() const override;
    [[nodiscard]] float getSpeed() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
    void move(std::pair<float, float>, float) override;
};


class Bowman : public Unit {
protected:
    int hp = 18;
    int damage = 35;
    int attackDistance = 150;
    float attackFrequency = 3.5;
    float speed = 12.5;
    std::pair<float, float> position;
    sf::CircleShape texture = sf::CircleShape(size, 4);
public:
    Bowman(float, float);
    void getType() const override;
    [[nodiscard]] int getHp() const override;
    [[nodiscard]] int getDamage() const override;
    [[nodiscard]] int getAttackDistance() const override;
    [[nodiscard]] float getAttackFrequency() const override;
    [[nodiscard]] float getSpeed() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
    void move(std::pair<float, float>, float) override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Unit::~Unit() = default;
void Unit::getAllInfo() const {
    std::cout << "I have: " << getHp() << "-hp; ";
    std::cout << getDamage() << "-damage; ";
    std::cout << getAttackDistance() << "-attack distance; ";
    std::cout << getAttackFrequency() << "-attack frequency; ";
    std::cout << getSpeed() << "-speed.\n\n";
}


Spearman::Spearman(float x, float y) : position({x - size, y - size}) {
    texture.setPosition(position.first, position.second);
}
void Spearman::getType() const {
    std::cout << "I am Spearman\n";
}
int Spearman::getHp() const {
    return hp;
}
int Spearman::getDamage() const {
    return damage;
}
int Spearman::getAttackDistance() const {
    return attackDistance;
}
float Spearman::getAttackFrequency() const {
    return attackFrequency;
}
float Spearman::getSpeed() const {
    return speed;
}
std::pair<float, float> Spearman::getPosition() const {
    return position;
}
sf::CircleShape &Spearman::getTexture() {
    return texture;
}
void Spearman::setColor(sf::Color color) {
    texture.setFillColor(color);
}
void Spearman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}


Swordsman::Swordsman(float x, float y) : position({x - size, y - size}) {
    texture.setPosition(position.first, position.second);
}
void Swordsman::getType() const {
    std::cout << "I am Swordsman\n";
}
int Swordsman::getHp() const {
    return hp;
}
int Swordsman::getDamage() const {
    return damage;
}
int Swordsman::getAttackDistance() const {
    return attackDistance;
}
float Swordsman::getAttackFrequency() const {
    return attackFrequency;
}
float Swordsman::getSpeed() const {
    return speed;
}
std::pair<float, float> Swordsman::getPosition() const {
    return position;
}
sf::CircleShape &Swordsman::getTexture() {
    return texture;
}
void Swordsman::setColor(sf::Color color) {
    texture.setFillColor(color);
}
void Swordsman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}



Bowman::Bowman(float x, float y) : position({x - size, y - size}) {
    texture.setPosition(position.first, position.second);
}
void Bowman::getType() const {
    std::cout << "I am Bowman\n";
}
int Bowman::getHp() const {
    return hp;
}
int Bowman::getDamage() const {
    return damage;
}
int Bowman::getAttackDistance() const {
    return attackDistance;
}
float Bowman::getAttackFrequency() const {
    return attackFrequency;
}
float Bowman::getSpeed() const {
    return speed;
}
std::pair<float, float> Bowman::getPosition() const {
    return position;
}
sf::CircleShape &Bowman::getTexture() {
    return texture;
}
void Bowman::setColor(sf::Color color) {
    texture.setFillColor(color);
}
void Bowman::move(std::pair<float, float> move_to, float delta_time) {
    normalise(move_to);
    position.first += move_to.first * delta_time * speed;
    position.second += move_to.second * delta_time * speed;
    texture.setPosition(position.first, position.second);
}

#endif //ARMA_UNIT_H
