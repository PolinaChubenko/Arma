#ifndef ARMA_COMPOSITE_H
#define ARMA_COMPOSITE_H

#include "UnitFactory.h"
#include <vector>

class ComposeUnits {
protected:
    std::unique_ptr<SpearmenFactory> spearmenFactory = std::make_unique<SpearmenFactory>();
    std::unique_ptr<SwordsmenFactory> swordsmenFactory = std::make_unique<SwordsmenFactory>();
    std::unique_ptr<BowmenFactory> bowmenFactory = std::make_unique<BowmenFactory>();
    std::vector<std::shared_ptr<Unit>> units;
    Color color;
public:
    explicit ComposeUnits(Color);
    void newSpearman(float, float);
    void newSwordsman(float, float);
    void newBowman(float, float);
    std::vector<std::shared_ptr<Unit>>& getUnits();
    void removeUnit(std::shared_ptr<Unit>&);
    size_t size();
    void attack(ComposeUnits&, float);
    static std::shared_ptr<Unit> getTarget(std::shared_ptr<Unit>&, ComposeUnits&);
};

#endif //ARMA_COMPOSITE_H
