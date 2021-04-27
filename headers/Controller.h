#ifndef ARMA_CONTROLLER_H
#define ARMA_CONTROLLER_H

#include "Render.h"
#include "Model.h"

class Controller {
private:
    std::unique_ptr<Render> render;
    std::unique_ptr<Model> game;
    std::unique_ptr<Graphics> graphics;
    UnitsType type = SPEARMAN;
    float delta_time = 0;
public:
    explicit Controller(Render*, Model*, Graphics*);
    ~Controller() = default;
    void run();
    void update_time();
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Controller::Controller(Render *render, Model *game, Graphics* graphics) : render(render), game(game), graphics(graphics) {}
void Controller::run() {
    while (graphics->isWindowOpen()) {
        update_time();

        while (graphics->isPollEvent()) {

            if (graphics->isEventClosed())
                graphics->closeWindow();

            if (graphics->isEventMouseLeftButtonPressed())
                game->addUnit(type, graphics->getMousePosition());

            if (graphics->isEventKeyPressed()) {

                if (graphics->isKey_A()) type = SPEARMAN;
                else if (graphics->isKey_S()) type = SWORDSMAN;
                else if (graphics->isKey_D()) type = BOWMAN;
                else if (graphics->isKey_Enter()) game->setWar();
            }
        }
        game->attack(delta_time);
        render->render();
    }
}
void Controller::update_time() {
    delta_time = graphics->getDeltaTimeAsMilliseconds() / 800;
}

#endif //ARMA_CONTROLLER_H
