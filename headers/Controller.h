#ifndef ARMA_CONTROLLER_H
#define ARMA_CONTROLLER_H

#include "Render.h"
#include "Model.h"

enum Units{
    SPEARMAN,
    SWORDSMAN,
    BOWMAN
};

class Controller {
private:
    std::unique_ptr<Render> render;
    std::unique_ptr<Model> game;
    Units type = SPEARMAN;
    sf::Clock clock;
public:
    explicit Controller(Render*, Model*);
    ~Controller() = default;
    void run();
    void addUnit(float, float);
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Controller::Controller(Render *render, Model *game) : render(render), game(game){}
void Controller::run() {
    while (render->getWindow().isOpen()) {
        sf::Event event{};
        float delta_time = static_cast<float>(clock.getElapsedTime().asMilliseconds());
        clock.restart();
        delta_time = delta_time / 800;

        while (render->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                render->getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto x = static_cast<float>(event.mouseButton.x);
                    auto y = static_cast<float>(event.mouseButton.y);
                    std::cout << "pos: " << x << " " << y << ". ";
                    addUnit(x, y);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    std::cout << "the SPEARMAN's key was pressed\n\n";
                    type = SPEARMAN;
                }
                if (event.key.code == sf::Keyboard::S) {
                    std::cout << "the SWORDSMAN's key was pressed\n\n";
                    type = SWORDSMAN;
                }
                if (event.key.code == sf::Keyboard::D) {
                    std::cout << "the BOWMAN's key was pressed\n\n";
                    type = BOWMAN;
                }

                if (event.key.code == sf::Keyboard::Enter) {
                    if (game->getUnits().size() == game->getEnemies().size()) {
                        game->set_is_war(true);
                    }
                }
            }
        }
        if (game->get_is_war()) {
            for(auto& it : game->getUnits()) {
                std::pair<float, float> vector;
                float dis = 100000;
                for(auto& en : game->getEnemies()) {
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
void Controller::addUnit(float x, float y) {
    if (x <= 400 && y >= 85 && game->getUnits().size() < game->getEnemies().size()) {
        switch (type) {
            case SPEARMAN:
                game->newSpearman(x, y);
                break;
            case SWORDSMAN:
                game->newSwordsman(x, y);
                break;
            case BOWMAN:
                game->newBowman(x, y);
                break;
            default:
                break;
        }
        render->updatePlaces();
        if (game->unitsAmount() > 0) {
            std::vector<std::unique_ptr<Unit>>::iterator it;
            it = (game->getUnits().end() - 1);
            (*it)->getType();
            (*it)->getAllInfo();
        }
    }
}

#endif //ARMA_CONTROLLER_H
