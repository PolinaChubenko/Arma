#include "config.h"
#include "headers/Assets.h"
#include "headers/Model.h"
#include "headers/Render.h"
#include "headers/Controller.h"

int main() {
    Assets::getInstance().load(RESOURCE_PATH);
    Model game;
    Graphics graphics;
    Render render(&game, &graphics);
    Controller controller(&render, &game, &graphics);
    controller.run();
    return 0;
}
