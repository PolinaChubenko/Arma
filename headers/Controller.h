#ifndef ARMA_CONTROLLER_H
#define ARMA_CONTROLLER_H

#include "Render.h"
#include "Model.h"

class Controller {
private:
    std::unique_ptr<Render> render;
    std::unique_ptr<Model> game;
    UnitsType type = SPEARMAN;
    sf::Clock clock;
public:
    explicit Controller(Render*, Model*);
    ~Controller() = default;
    void run();
    void timing(float&);
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Controller::Controller(Render *render, Model *game) : render(render), game(game){}
void Controller::run() {
    float delta_time;
    while (render->getWindow().isOpen()) {
        sf::Event event{};
        timing(delta_time);

        while (render->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                render->getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto x = static_cast<float>(event.mouseButton.x);
                    auto y = static_cast<float>(event.mouseButton.y);
                    game->addUnit(type, x, y);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    type = SPEARMAN;
                }
                if (event.key.code == sf::Keyboard::S) {
                    type = SWORDSMAN;
                }
                if (event.key.code == sf::Keyboard::D) {
                    type = BOWMAN;
                }

                if (event.key.code == sf::Keyboard::Enter) {
                    if (game->playerUnitsAmount() == game->enemyUnitsAmount()) {
                        game->set_is_war(true);
                    }
                }
            }
        }
        // movement to the target example
        if (game->get_is_war()) {
            for(auto& it : game->getPlayerUnits()) {
                std::pair<float, float> vector;
                float dis = 100000;
                for(auto& en : game->getEnemyUnits()) {
                    float delta1 = en->getPosition().first - it->getPosition().first;
                    float delta2 = en->getPosition().second - it->getPosition().second;
                    float new_dis = distance(en->getPosition(), it->getPosition());
                    if (new_dis <= dis) {
                        vector = {delta1, delta2};
                        dis = new_dis;
                    }
                }
                if (dis > it->getAttackDistance())
                    it->move(vector, delta_time);
            }
        }
        render->render();
    }
}
void Controller::timing(float &delta_time) {
    delta_time = static_cast<float>(clock.getElapsedTime().asMilliseconds());
    clock.restart();
    delta_time /= 800;
}

#endif //ARMA_CONTROLLER_H
