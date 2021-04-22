#ifndef ARMA_UNITFACTORY_H
#define ARMA_UNITFACTORY_H

#include "Unit.h"
#include <memory>

class UnitFactory {
public:
    virtual std::shared_ptr<Unit> createUnit(float, float) = 0;
    virtual ~UnitFactory() = 0;
};
UnitFactory::~UnitFactory() = default;


class SpearmenFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createUnit(float, float) override;
};


class SwordsmenFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createUnit(float, float) override;
};


class BowmenFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createUnit(float, float) override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

std::shared_ptr<Unit> SpearmenFactory::createUnit(float x, float y) {
    return std::make_shared<Spearman>(x, y);
}


std::shared_ptr<Unit> SwordsmenFactory::createUnit(float x, float y) {
    return std::make_shared<Swordsman>(x, y);
}


std::shared_ptr<Unit> BowmenFactory::createUnit(float x, float y) {
    return std::make_shared<Bowman>(x, y);
}


#endif //ARMA_UNITFACTORY_H
