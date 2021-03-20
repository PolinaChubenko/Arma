#ifndef ARMA_UNIT_H
#define ARMA_UNIT_H

#pragma once
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
    virtual ~Unit() = 0;
};
Unit::~Unit() = default;


class Spearman : public Unit {
protected:
    int hp_ = 50;
    int damage_ = 35;
    int attackDistance_ = 28;
    float attackFrequency_ = 0.9;
    float speed_ = 0.6;
    std::pair<int, int> position_;
    sf::CircleShape texture_ = sf::CircleShape(25.f, 5);
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
};


class Swordsman : public Unit {
protected:
    int hp_ = 30;
    int damage_ = 110;
    int attackDistance_ = 8;
    float attackFrequency_ = 1.0;
    float speed_ = 0.4;
    std::pair<int, int> position_;
    sf::CircleShape texture_ = sf::CircleShape(25.f);
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
};


class Bowman : public Unit {
protected:
    int hp_ = 18;
    int damage_ = 35;
    int attackDistance_ = 150;
    float attackFrequency_ = 3.5;
    float speed_ = 0.5;
    std::pair<int, int> position_;
    sf::CircleShape texture_ = sf::CircleShape(25.f, 4);
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
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Spearman::Spearman(int x, int y) : position_(std::make_pair(x - 25, y - 25)) {
    texture_.setPosition(float(x - 25), float(y - 25));
};
void Spearman::getInfo() const {
    std::cout << "I am Spearman\n";
}
int Spearman::getHp() const {
    return hp_;
}
int Spearman::getDamage() const {
    return damage_;
}
int Spearman::getAttackDistance() const {
    return attackDistance_;
}
float Spearman::getAttackFrequency() const {
    return attackFrequency_;
}
float Spearman::getSpeed() const {
    return speed_;
}
std::pair<int, int> Spearman::getPosition() const {
    return position_;
}
sf::CircleShape &Spearman::getTexture() {
    return texture_;
}



Swordsman::Swordsman(int x, int y) : position_(std::make_pair(x - 25, y - 25)) {
    texture_.setPosition(float(x - 25), float(y - 25));
}
void Swordsman::getInfo() const {
    std::cout << "I am Swordsman\n";
}
int Swordsman::getHp() const {
    return hp_;
}
int Swordsman::getDamage() const {
    return damage_;
}
int Swordsman::getAttackDistance() const {
    return attackDistance_;
}
float Swordsman::getAttackFrequency() const {
    return attackFrequency_;
}
float Swordsman::getSpeed() const {
    return speed_;
}
std::pair<int, int> Swordsman::getPosition() const {
    return position_;
}
sf::CircleShape &Swordsman::getTexture() {
    return texture_;
}



Bowman::Bowman(int x, int y) : position_(std::make_pair(x - 25, y - 25)) {
    texture_.setPosition(float(x - 25), float(y - 25));
}
void Bowman::getInfo() const {
    std::cout << "I am Bowman\n";
}
int Bowman::getHp() const {
    return hp_;
}
int Bowman::getDamage() const {
    return damage_;
}
int Bowman::getAttackDistance() const {
    return attackDistance_;
}
float Bowman::getAttackFrequency() const {
    return attackFrequency_;
}
float Bowman::getSpeed() const {
    return speed_;
}
std::pair<int, int> Bowman::getPosition() const {
    return position_;
}
sf::CircleShape &Bowman::getTexture() {
    return texture_;
}


#endif //ARMA_UNIT_H
