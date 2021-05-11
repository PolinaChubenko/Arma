#ifndef ARMA_RENDER_H
#define ARMA_RENDER_H

#include "Graphics.h"
#include "Model.h"

class Render {
private:
    std::unique_ptr<Model> game;
    std::unique_ptr<Graphics> graphics;
public:
    explicit Render(Model*, Graphics*);
    void render();
    void updatePlaces();
    void updateResult();
};

#endif //ARMA_RENDER_H
