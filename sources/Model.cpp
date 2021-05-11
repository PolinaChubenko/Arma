#include "Model.h"

Model::Model() : player(Color(BLUE)), enemy(Color(RED)) {
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
void Model::addUnit(UnitsType type, std::pair<float, float> pos) {
    float x = pos.first, y = pos.second;
    if (game_stage == ENTRY && x <= 400 && y >= 85 && player.size() < enemy.size() - units_delta) {
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
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> type(1, 3);
    std::uniform_int_distribution<int> uni_x(450,900);
    std::uniform_int_distribution<int> uni_y(120, 600);
    for (int i = 0; i < 8; ++i) {
        auto t = type(rng);
        auto x = uni_x(rng);
        auto y = uni_y(rng);
        if (t == 1) enemy.newSpearman(x, y);
        else if (t == 2) enemy.newSwordsman(x, y);
        else enemy.newBowman(x, y);
    }
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
    if (game_stage == ENTRY && player.size() > 0)
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
