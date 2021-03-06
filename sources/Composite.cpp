#include "Composite.h"

ComposeUnits::ComposeUnits(
        Color color) : color(color) {}

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
std::vector<std::shared_ptr<Unit>> &ComposeUnits::getUnits() {
    return units;
}
void ComposeUnits::removeUnit(std::shared_ptr<Unit> &unit) {
    auto del_unit = std::find(units.begin(), units.end(), unit);
    if (del_unit != units.end()) {
        swap(*del_unit, units.back());
        units.pop_back();
    }
}
size_t ComposeUnits::size() {
    return units.size();
}
std::shared_ptr<Unit> ComposeUnits::getTarget(std::shared_ptr<Unit>& unit, ComposeUnits &enemies) {
    float min_dis = 1e5;
    std::shared_ptr<Unit> victim = nullptr;
    for (auto& en : enemies.getUnits()) {
        float new_dis = distance(en->getPosition(), unit->getPosition());
        if (new_dis <= min_dis) {
            min_dis = new_dis;
            victim = en;
        }
    }
    return victim;
}
void ComposeUnits::attack(ComposeUnits &whom_to_attack, float delta_time) {
    for (auto& it : units) {
        std::shared_ptr<Unit> victim = getTarget(it, whom_to_attack);
        if (victim) {
            std::pair<float, float> vector = victim->getPosition() - it->getPosition();
            float dis = distance(victim->getPosition(), it->getPosition());
            if (dis > it->getAttackDistance())
                it->move(vector, delta_time);
            else {
                it->hit(victim, delta_time);
                if (victim->getHp() <= 0)
                    whom_to_attack.removeUnit(victim);
            }
        }
    }
}
