#ifndef ARMA_MODEL_H
#define ARMA_MODEL_H

#include "Composite.h"
#include "Enums.h"

class Model {
protected:
    ComposeUnits player;
    ComposeUnits enemy;
    GameStage game_stage = ENTRY;
    void updateGameState();
    void initEnemy();
public:
    Model();
    std::vector<std::shared_ptr<Unit>>& getPlayerUnits();
    std::vector<std::shared_ptr<Unit>>& getEnemyUnits();
    size_t playerUnitsAmount();
    size_t enemyUnitsAmount();
    void addUnit(UnitsType, std::pair<float, float>);

    bool isEntry();
    bool isWar();
    bool isVictory();
    bool isDefeat();
    void setWar();
    void attack(float);
};

#endif //ARMA_MODEL_H
