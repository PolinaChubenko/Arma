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

#endif //ARMA_CONTROLLER_H
