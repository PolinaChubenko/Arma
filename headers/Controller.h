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
    std::unique_ptr<Render> render_;
    std::unique_ptr<Model> game_;
public:
    explicit Controller(Render*, Model*);
    ~Controller() = default;
    void run();
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Controller::Controller(Render *render, Model *game) : render_(render), game_(game){}
void Controller::run() {
    while (render_->getWindow().isOpen()) {
        sf::Event event{};
        Units type;
        while (render_->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                render_->getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x, y = event.mouseButton.y;
                    std::cout << "pos: " << x << " " << y << ". ";
                    switch (type) {
                        case SPEARMAN:
                            game_->newSpearman(x, y);
                            break;
                        case SWORDSMAN:
                            game_->newSwordsman(x, y);
                            break;
                        case BOWMAN:
                            game_->newBowman(x, y);
                            break;
                        default:
                            break;
                    }
                    if (!game_->getUnits().empty()) {
                        std::vector<std::unique_ptr<Unit>>::iterator it;
                        it = (game_->getUnits().end() - 1);
                        (*it)->getTexture().setFillColor(sf::Color::Blue);
                        (*it)->getInfo();
                        std::cout << "I have: " << (*it)->getHp() << "-hp; ";
                        std::cout << (*it)->getDamage() << "-damage; ";
                        std::cout << (*it)->getAttackDistance() << "-attack distance; ";
                        std::cout << (*it)->getAttackFrequency() << "-attack frequency; ";
                        std::cout << (*it)->getSpeed() << "-speed.\n\n";
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
        render_->render();
    }
}

#endif //ARMA_CONTROLLER_H
