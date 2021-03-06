#ifndef ARMA_UNIT_H
#define ARMA_UNIT_H

#include <iostream>
#include <memory>
#include <Assets.h>
#include "GameMaths.h"
#include "Graphics.h"
#include "UnitTexture.h"

class Unit {
protected:
    constexpr static const float size = 25;
    int hp;
    int damage;
    float attackDistance;
    float attackFrequency;
    float speed;
public:
    explicit Unit(int, int, float, float, float);
    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] float getAttackDistance() const;
    [[nodiscard]] float getAttackFrequency() const;
    [[nodiscard]] float getSpeed() const;
    int& changeHp();

    virtual void getType() const = 0;
    [[nodiscard]] virtual std::pair<float, float> getPosition() const = 0;
    virtual UnitTexture& getTexture() = 0;
    virtual void setColor(Color) = 0;

    virtual void move(std::pair<float, float>, float) = 0;
    virtual void hit(std::shared_ptr<Unit>&, float) = 0;
    virtual ~Unit() = 0;
};


class Spearman : public Unit {
protected:
    std::pair<float, float> position;
    UnitTexture texture;
    float duration = 0;
public:
    Spearman(float, float);
    void getType() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    UnitTexture& getTexture() override;
    void setColor(Color) override;
    void move(std::pair<float, float>, float) override;
    void hit(std::shared_ptr<Unit>&, float) override;
};


class Swordsman : public Unit {
protected:
    std::pair<float, float> position;
    UnitTexture texture;
    float duration = 0;
public:
    Swordsman(float, float);
    void getType() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    UnitTexture& getTexture() override;
    void setColor(Color) override;
    void move(std::pair<float, float>, float) override;
    void hit(std::shared_ptr<Unit>&, float) override;
};


class Bowman : public Unit {
protected:
    std::pair<float, float> position;
    UnitTexture texture;
    float duration = 0;
public:
    Bowman(float, float);
    void getType() const override;
    [[nodiscard]] std::pair<float, float> getPosition() const override;
    UnitTexture& getTexture() override;
    void setColor(Color) override;
    void move(std::pair<float, float>, float) override;
    void hit(std::shared_ptr<Unit>&, float) override;
};

#endif //ARMA_UNIT_H
