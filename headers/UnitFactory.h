#ifndef ARMA_UNITFACTORY_H
#define ARMA_UNITFACTORY_H

#include "Unit.h"

class UnitFactory {
public:
    virtual std::unique_ptr<Unit> createUnit(float, float) = 0;
    virtual ~UnitFactory() = 0;
};
UnitFactory::~UnitFactory() = default;


class SpearmenFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(float, float) override;
};


class SwordsmenFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(float, float) override;
};


class BowmenFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(float, float) override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

std::unique_ptr<Unit> SpearmenFactory::createUnit(float x, float y) {
    return std::make_unique<Spearman>(x, y);
}


std::unique_ptr<Unit> SwordsmenFactory::createUnit(float x, float y) {
    return std::make_unique<Swordsman>(x, y);
}


std::unique_ptr<Unit> BowmenFactory::createUnit(float x, float y) {
    return std::make_unique<Bowman>(x, y);
}


#endif //ARMA_UNITFACTORY_H
