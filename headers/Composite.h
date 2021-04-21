#ifndef ARMA_COMPOSITE_H
#define ARMA_COMPOSITE_H

#include "UnitFactory.h"
#include <vector>

class ComposeUnits {
protected:
    std::unique_ptr<SpearmenFactory> spearmenFactory = std::make_unique<SpearmenFactory>();
    std::unique_ptr<SwordsmenFactory> swordsmenFactory = std::make_unique<SwordsmenFactory>();
    std::unique_ptr<BowmenFactory> bowmenFactory = std::make_unique<BowmenFactory>();
    std::vector<std::unique_ptr<Unit>> units;
    sf::Color color;
public:
    ComposeUnits() = default;
    explicit ComposeUnits(sf::Color);
    void newSpearman(float, float);
    void newSwordsman(float, float);
    void newBowman(float, float);
    std::vector<std::unique_ptr<Unit>>& getUnits();
    size_t size();
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

ComposeUnits::ComposeUnits(sf::Color color) : color(color) {}

void ComposeUnits::newSpearman(float x, float y) {
    units.emplace_back(spearmenFactory->createUnit(x, y));
    units[units.size() - 1]->setColor(color);
}
void ComposeUnits::newSwordsman(float x, float y) {
    units.emplace_back(swordsmenFactory->createUnit(x, y));
    units[units.size() - 1]->setColor(color);
}
void ComposeUnits::newBowman(float x, float y) {
    units.emplace_back(bowmenFactory->createUnit(x, y));
    units[units.size() - 1]->setColor(color);
}
std::vector<std::unique_ptr<Unit>> &ComposeUnits::getUnits() {
    return units;
}
size_t ComposeUnits::size() {
    return units.size();
}

#endif //ARMA_COMPOSITE_H
