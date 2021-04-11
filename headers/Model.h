#ifndef ARMA_MODEL_H
#define ARMA_MODEL_H

#include "UnitFactory.h"
#include <vector>

class Model {
protected:
    std::unique_ptr<SpearmenFactory> spearmenFactory = std::make_unique<SpearmenFactory>();
    std::unique_ptr<SwordsmenFactory> swordsmenFactory = std::make_unique<SwordsmenFactory>();
    std::unique_ptr<BowmenFactory> bowmenFactory = std::make_unique<BowmenFactory>();
    std::vector<std::unique_ptr<Unit>> units;
    std::vector<std::unique_ptr<Unit>> enemies;

    sf::Color blue = sf::Color::Blue;
    sf::Color red = sf::Color::Red;
public:
    Model();
    std::vector<std::unique_ptr<Unit>>& getUnits();
    std::vector<std::unique_ptr<Unit>>& getEnemies();
    size_t unitsAmount();
    size_t enemiesAmount();
    void newSpearman(int, int);
    void newSwordsman(int, int);
    void newBowman(int, int);
    void createEnemiesArmy();
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Model::Model() {
    createEnemiesArmy();
}
std::vector<std::unique_ptr<Unit>>& Model::getUnits() {
    return units;
}
std::vector<std::unique_ptr<Unit>>& Model::getEnemies() {
    return enemies;
}
size_t Model::unitsAmount() {
    return units.size();
}
size_t Model::enemiesAmount() {
    return enemies.size();
}
void Model::newSpearman(int x, int y) {
    units.emplace_back(spearmenFactory->createUnit(x, y));
    units[units.size() - 1]->setColor(blue);
}
void Model::newSwordsman(int x, int y) {
    units.emplace_back(swordsmenFactory->createUnit(x, y));
    units[units.size() - 1]->setColor(blue);
}
void Model::newBowman(int x, int y) {
    units.emplace_back(bowmenFactory->createUnit(x, y));
    units[units.size() - 1]->setColor(blue);
}
void Model::createEnemiesArmy() {
    enemies.emplace_back(spearmenFactory->createUnit(700, 230));
    enemies.emplace_back(spearmenFactory->createUnit(700, 330));
    enemies.emplace_back(spearmenFactory->createUnit(700, 430));
    enemies.emplace_back(spearmenFactory->createUnit(700, 530));

    enemies.emplace_back(bowmenFactory->createUnit(800, 230));
    enemies.emplace_back(bowmenFactory->createUnit(800, 330));
    enemies.emplace_back(bowmenFactory->createUnit(800, 430));
    enemies.emplace_back(bowmenFactory->createUnit(800, 530));

    for (auto& el : enemies) {
        (*el).setColor(red);
    }
}


#endif //ARMA_MODEL_H
