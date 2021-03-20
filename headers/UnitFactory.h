#ifndef ARMA_UNITFACTORY_H
#define ARMA_UNITFACTORY_H

#pragma once
#include "Unit.h"

class UnitFactory {
public:
    virtual std::unique_ptr<Unit> createUnit(int, int) = 0;
    virtual ~UnitFactory() = 0;
};
UnitFactory::~UnitFactory() = default;


class SpearmenFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(int, int) override;
};


class SwordsmenFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(int, int) override;
};


class BowmenFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(int, int) override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

std::unique_ptr<Unit> SpearmenFactory::createUnit(int x, int y) {
    return std::make_unique<Spearman>(x, y);
}


std::unique_ptr<Unit> SwordsmenFactory::createUnit(int x, int y) {
    return std::make_unique<Swordsman>(x, y);
}


std::unique_ptr<Unit> BowmenFactory::createUnit(int x, int y) {
    return std::make_unique<Bowman>(x, y);
}


#endif //ARMA_UNITFACTORY_H
