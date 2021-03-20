#include "headers/Assets.h"
#include "headers/Model.h"
#include "headers/Render.h"
#include "headers/Controller.h"

int main() {
    Assets::getInstance().load();
    Model game;
    Render render(&game);
    Controller controller(&render, &game);
    controller.run();
    return 0;
}
