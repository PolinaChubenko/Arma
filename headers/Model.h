#ifndef ARMA_MODEL_H
#define ARMA_MODEL_H

#include "UnitFactory.h"
#include <vector>

class Model {
protected:
    std::unique_ptr<SpearmenFactory> spearmenFactory_ = std::make_unique<SpearmenFactory>();
    std::unique_ptr<SwordsmenFactory> swordsmenFactory_ = std::make_unique<SwordsmenFactory>();
    std::unique_ptr<BowmenFactory> bowmenFactory_ = std::make_unique<BowmenFactory>();
    std::vector<std::unique_ptr<Unit>> units_;
public:
    Model() = default;
    std::vector<std::unique_ptr<Unit>>& getUnits();
    void newSpearman(int, int);
    void newSwordsman(int, int);
    void newBowman(int, int);
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

std::vector<std::unique_ptr<Unit>>& Model::getUnits() {
    return units_;
}
void Model::newSpearman(int x, int y) {
    units_.emplace_back(spearmenFactory_->createUnit(x, y));
}
void Model::newSwordsman(int x, int y) {
    units_.emplace_back(swordsmenFactory_->createUnit(x, y));
}
void Model::newBowman(int x, int y) {
    units_.emplace_back(bowmenFactory_->createUnit(x, y));
}


#endif //ARMA_MODEL_H
