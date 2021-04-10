#ifndef ARMA_UNIT_H
#define ARMA_UNIT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Unit {
public:
    virtual void getInfo() const = 0;
    [[nodiscard]] virtual int getHp() const = 0;
    [[nodiscard]] virtual int getDamage() const = 0;
    [[nodiscard]] virtual int getAttackDistance() const = 0;
    [[nodiscard]] virtual float getAttackFrequency() const = 0;
    [[nodiscard]] virtual float getSpeed() const = 0;
    [[nodiscard]] virtual std::pair<int, int> getPosition() const = 0;
    virtual sf::CircleShape& getTexture() = 0;
    virtual void setColor(sf::Color) = 0;
    virtual ~Unit() = 0;
};
Unit::~Unit() = default;


class Spearman : public Unit {
protected:
    int hp = 50;
    int damage = 35;
    int attackDistance = 28;
    float attackFrequency = 0.9;
    float speed = 0.6;
    std::pair<int, int> position;
    sf::CircleShape texture = sf::CircleShape(25.f, 5);
public:
    Spearman(int, int);
    void getInfo() const override;
    [[nodiscard]] int getHp() const override;
    [[nodiscard]] int getDamage() const override;
    [[nodiscard]] int getAttackDistance() const override;
    [[nodiscard]] float getAttackFrequency() const override;
    [[nodiscard]] float getSpeed() const override;
    [[nodiscard]] std::pair<int, int> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
};


class Swordsman : public Unit {
protected:
    int hp = 30;
    int damage = 110;
    int attackDistance = 8;
    float attackFrequency = 1.0;
    float speed = 0.4;
    std::pair<int, int> position;
    sf::CircleShape texture = sf::CircleShape(25.f);
public:
    Swordsman(int, int);
    void getInfo() const override;
    [[nodiscard]] int getHp() const override;
    [[nodiscard]] int getDamage() const override;
    [[nodiscard]] int getAttackDistance() const override;
    [[nodiscard]] float getAttackFrequency() const override;
    [[nodiscard]] float getSpeed() const override;
    [[nodiscard]] std::pair<int, int> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
};


class Bowman : public Unit {
protected:
    int hp = 18;
    int damage = 35;
    int attackDistance = 150;
    float attackFrequency = 3.5;
    float speed_ = 0.5;
    std::pair<int, int> position;
    sf::CircleShape texture = sf::CircleShape(25.f, 4);
public:
    Bowman(int, int);
    void getInfo() const override;
    [[nodiscard]] int getHp() const override;
    [[nodiscard]] int getDamage() const override;
    [[nodiscard]] int getAttackDistance() const override;
    [[nodiscard]] float getAttackFrequency() const override;
    [[nodiscard]] float getSpeed() const override;
    [[nodiscard]] std::pair<int, int> getPosition() const override;
    sf::CircleShape& getTexture() override;
    void setColor(sf::Color) override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Spearman::Spearman(int x, int y) : position(std::make_pair(x - 25, y - 25)) {
    texture.setPosition(float(x - 25), float(y - 25));
}
void Spearman::getInfo() const {
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
std::pair<int, int> Spearman::getPosition() const {
    return position;
}
sf::CircleShape &Spearman::getTexture() {
    return texture;
}
void Spearman::setColor(sf::Color color) {
    texture.setFillColor(color);
}


Swordsman::Swordsman(int x, int y) : position(std::make_pair(x - 25, y - 25)) {
    texture.setPosition(float(x - 25), float(y - 25));
}
void Swordsman::getInfo() const {
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
std::pair<int, int> Swordsman::getPosition() const {
    return position;
}
sf::CircleShape &Swordsman::getTexture() {
    return texture;
}
void Swordsman::setColor(sf::Color color) {
    texture.setFillColor(color);
}



Bowman::Bowman(int x, int y) : position(std::make_pair(x - 25, y - 25)) {
    texture.setPosition(float(x - 25), float(y - 25));
}
void Bowman::getInfo() const {
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
    return speed_;
}
std::pair<int, int> Bowman::getPosition() const {
    return position;
}
sf::CircleShape &Bowman::getTexture() {
    return texture;
}
void Bowman::setColor(sf::Color color) {
    texture.setFillColor(color);
}

#endif //ARMA_UNIT_H
