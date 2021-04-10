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
public:
    Model();
    std::vector<std::unique_ptr<Unit>>& getUnits();
    std::vector<std::unique_ptr<Unit>>& getEnemies();
    void newSpearman(int, int);
    void newSwordsman(int, int);
    void newBowman(int, int);
    void createBotsArmy();
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Model::Model() {
    createBotsArmy();
}
std::vector<std::unique_ptr<Unit>>& Model::getUnits() {
    return units;
}
std::vector<std::unique_ptr<Unit>>& Model::getEnemies() {
    return enemies;
}
void Model::newSpearman(int x, int y) {
    units.emplace_back(spearmenFactory->createUnit(x, y));
    sf::Color blue = sf::Color::Blue;
    units[units.size() - 1]->getTexture().setFillColor(blue);
}
void Model::newSwordsman(int x, int y) {
    units.emplace_back(swordsmenFactory->createUnit(x, y));
    sf::Color blue = sf::Color::Blue;
    units[units.size() - 1]->getTexture().setFillColor(blue);
}
void Model::newBowman(int x, int y) {
    units.emplace_back(bowmenFactory->createUnit(x, y));
    units[units.size() - 1]->getTexture().setFillColor(sf::Color::Blue);
}
void Model::createBotsArmy() {
    enemies.emplace_back(spearmenFactory->createUnit(680, 230));
    enemies.emplace_back(spearmenFactory->createUnit(680, 330));
    enemies.emplace_back(spearmenFactory->createUnit(680, 430));
    enemies.emplace_back(spearmenFactory->createUnit(680, 530));

    enemies.emplace_back(bowmenFactory->createUnit(800, 230));
    enemies.emplace_back(bowmenFactory->createUnit(800, 330));
    enemies.emplace_back(bowmenFactory->createUnit(800, 430));
    enemies.emplace_back(bowmenFactory->createUnit(800, 530));

    for (auto& el : enemies) {
        (*el).getTexture().setFillColor(sf::Color::Red);
    }
}


#endif //ARMA_MODEL_H
