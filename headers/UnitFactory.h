#ifndef ARMA_UNITFACTORY_H
#define ARMA_UNITFACTORY_H

#include "Unit.h"

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


#endif //ARMA_UNITFACTORY_H
