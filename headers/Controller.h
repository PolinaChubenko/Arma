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
public:
    explicit Controller(Render*, Model*);
    ~Controller() = default;
    void run();
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Controller::Controller(Render *render, Model *game) : render(render), game(game){}
void Controller::run() {
    while (render->getWindow().isOpen()) {
        sf::Event event{};
        Units type;
        while (render->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                render->getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x, y = event.mouseButton.y;
                    std::cout << "pos: " << x << " " << y << ". ";
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
                        if (!game->getUnits().empty()) {
                            std::vector<std::unique_ptr<Unit>>::iterator it;
                            it = (game->getUnits().end() - 1);
//                            (*it)->getTexture().setFillColor(sf::Color::Blue);
                            (*it)->getInfo();
//                            std::cout << "I have: " << (*it)->getHp() << "-hp; ";
//                            std::cout << (*it)->getDamage() << "-damage; ";
//                            std::cout << (*it)->getAttackDistance() << "-attack distance; ";
//                            std::cout << (*it)->getAttackFrequency() << "-attack frequency; ";
//                            std::cout << (*it)->getSpeed() << "-speed.\n\n";
                        }
                    }
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
            }
        }
        render->render();
    }
}

#endif //ARMA_CONTROLLER_H
