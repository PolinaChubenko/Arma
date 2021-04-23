#ifndef ARMA_MODEL_H
#define ARMA_MODEL_H

#include "Composite.h"
#include "Enums.h"

class Model {
protected:
    ComposeUnits player;
    ComposeUnits enemy;
    GameStage game_stage = ENTRY;
public:
    Model();
    std::vector<std::shared_ptr<Unit>>& getPlayerUnits();
    std::vector<std::shared_ptr<Unit>>& getEnemyUnits();
    size_t playerUnitsAmount();
    size_t enemyUnitsAmount();
    void addUnit(UnitsType, float, float);
    void initEnemy();

    bool isEntry();
    bool isWar();
    bool isVictory();
    bool isDefeat();
    void setWar();
    void updateGameState();

    void attack(float);
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Model::Model() : player(sf::Color::Blue), enemy(sf::Color::Red) {
    initEnemy();
}
std::vector<std::shared_ptr<Unit>>& Model::getPlayerUnits() {
    return player.getUnits();
}
std::vector<std::shared_ptr<Unit>>& Model::getEnemyUnits() {
    return enemy.getUnits();
}
size_t Model::playerUnitsAmount() {
    return player.size();
}
size_t Model::enemyUnitsAmount() {
    return enemy.size();
}
void Model::addUnit(UnitsType type, float x, float y) {
    if (game_stage == ENTRY && x <= 400 && y >= 85 && player.size() < enemy.size()) {
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
    enemy.newSwordsman(700, 330);
    enemy.newSwordsman(700, 430);
    enemy.newSpearman(700, 530);

    enemy.newBowman(800, 230);
    enemy.newBowman(800, 330);
    enemy.newBowman(800, 430);
    enemy.newBowman(800, 530);
}
bool Model::isEntry() {
    return game_stage == ENTRY;
}
bool Model::isWar() {
    return game_stage == WAR;
}
bool Model::isVictory() {
    return game_stage == VICTORY;
}
bool Model::isDefeat() {
    return game_stage == DEFEAT;
}
void Model::setWar() {
    if (game_stage == ENTRY && player.size() == enemy.size())
        game_stage = WAR;
}
void Model::updateGameState() {
    if (enemyUnitsAmount() == 0) game_stage = VICTORY;
    else if (playerUnitsAmount() == 0) game_stage = DEFEAT;
}
void Model::attack(float delta_time) {
    if (game_stage != ENTRY) updateGameState();
    if (game_stage == WAR) {
        player.attack(enemy, delta_time);
        enemy.attack(player, delta_time);
    }
}


#endif //ARMA_MODEL_H
