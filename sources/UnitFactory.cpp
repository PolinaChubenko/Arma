#include "UnitFactory.h"

std::shared_ptr<Unit> SpearmenFactory::createUnit(float x, float y) {
    return std::make_shared<Spearman>(x, y);
}


std::shared_ptr<Unit> SwordsmenFactory::createUnit(float x, float y) {
    return std::make_shared<Swordsman>(x, y);
}


std::shared_ptr<Unit> BowmenFactory::createUnit(float x, float y) {
    return std::make_shared<Bowman>(x, y);
}
