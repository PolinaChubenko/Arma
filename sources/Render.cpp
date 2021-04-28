#include "Render.h"


Render::Render(Model* game, Graphics* graphics) : game(game), graphics(graphics) {
    graphics->createWindow(1000, 700, "Arma!", 60);
    std::string info = "Press A/S/D (Spearman, Swordsman, Bowman) to choose the unit\n"
                       "Click on the board to place the army. Press ENTER to start the war!";
    graphics->createText("info", info, 24, Color(BLACK), 5.f, 5.f);
    graphics->createText("places", 24, Color(BLACK), 800.f, 5.f);
    graphics->createText("result", 55, Color(WHITE), 400.f, 340.f);
    graphics->createLine("vertical", {400, 640}, {400, 85}, Color(MAGENTA));
    graphics->createLine("horizontal", {20, 85}, {980, 85}, Color(MAGENTA));
}
void Render::render() {
    graphics->clear();

    if (game->isEntry() || game->isWar()) {
        for (auto& el : game->getPlayerUnits()) {
            graphics->getWindow().draw((*el).getTexture());
            graphics->getWindow().draw((*el).getHpText());
        }
        for (auto& el : game->getEnemyUnits()) {
            graphics->getWindow().draw((*el).getTexture());
            graphics->getWindow().draw((*el).getHpText());
        }
    }
    updatePlaces();
    graphics->drawText("places");
    graphics->drawText("info");
    if (game->isEntry()) {
        graphics->drawLine("vertical");
    }
    graphics->drawLine("horizontal");
    if (game->isVictory() || game->isDefeat()) {
        updateResult();
        graphics->drawText("result");
    }
    graphics->display();
}
void Render::updatePlaces() {
    if (game->isEntry()) {
        std::string p = std::to_string(game->enemyUnitsAmount() - game->playerUnitsAmount());
        p += " soldiers left";
        graphics->setText("places", p);
    }
}
void Render::updateResult() {
    if (game->isVictory()) {
        graphics->setText("result", "You won!");
        graphics->setTextColor("result", Color(MAGENTA));
    }
    else if (game->isDefeat()) {
        graphics->setText("result", "You lost...");
        graphics->setTextColor("result", Color(RED));
    }
}
