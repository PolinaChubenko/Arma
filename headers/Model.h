#ifndef ARMA_MODEL_H
#define ARMA_MODEL_H

#include "Composite.h"

enum UnitsType{
    SPEARMAN,
    SWORDSMAN,
    BOWMAN
};

class Model {
protected:
    ComposeUnits player;
    ComposeUnits enemy;
    bool is_war_started = false;
public:
    Model();
    std::vector<std::unique_ptr<Unit>>& getPlayerUnits();
    std::vector<std::unique_ptr<Unit>>& getEnemyUnits();
    size_t playerUnitsAmount();
    size_t enemyUnitsAmount();
    void addUnit(UnitsType, float, float);
    void initEnemy();

    [[nodiscard]] bool get_is_war() const;
    void set_is_war(bool);
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Model::Model() : player(sf::Color::Blue), enemy(sf::Color::Red) {
    initEnemy();
}
std::vector<std::unique_ptr<Unit>>& Model::getPlayerUnits() {
    return player.getUnits();
}
std::vector<std::unique_ptr<Unit>>& Model::getEnemyUnits() {
    return enemy.getUnits();
}
size_t Model::playerUnitsAmount() {
    return player.size();
}
size_t Model::enemyUnitsAmount() {
    return enemy.size();
}
void Model::addUnit(UnitsType type, float x, float y) {
    if (x <= 400 && y >= 85 && player.size() < enemy.size()) {
        switch (type) {
            case SPEARMAN:
                player.newSpearman(x, y);
                break;
            case SWORDSMAN:
                player.newSwordsman(x, y);
                break;
            case BOWMAN:
                player.newBowman(x, y);
                break;
            default:
                break;
        }
    }
}
void Model::initEnemy() {
    enemy.newSpearman(700, 230);
    enemy.newSpearman(700, 330);
    enemy.newSpearman(700, 430);
    enemy.newSpearman(700, 530);

    enemy.newBowman(800, 230);
    enemy.newBowman(800, 330);
    enemy.newBowman(800, 430);
    enemy.newBowman(800, 530);
}
bool Model::get_is_war() const {
    return is_war_started;
}
void Model::set_is_war(bool is_war) {
    is_war_started = is_war;
}


#endif //ARMA_MODEL_H
