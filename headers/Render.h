#ifndef ARMA_RENDER_H
#define ARMA_RENDER_H

#include "Assets.h"

class Render : public sf::Drawable, public sf::Transformable {
private:
    sf::RenderWindow window;
    std::unique_ptr<Model> game;
    sf::Text text, info;
    sf::Vertex line1[2];
    sf::Vertex line2[2];
public:
    explicit Render(Model*);
    ~Render() override = default;
    sf::RenderWindow& getWindow();
    bool initialize();
    void render();
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



/******************************************/
/////////////   DEFINITIONS   /////////////
/******************************************/

Render::Render(Model* game) : game(game) {
    initialize();
}
sf::RenderWindow& Render::getWindow() {
    return window;
}
bool Render::initialize() {
    setPosition(25.f, 25.f);
    window.setVerticalSyncEnabled(true);
    window.create(sf::VideoMode(1000, 700), "Arma!");

    text.setFont(Assets::getInstance().font);
    text.setString("Press A / S / D to choose the unit; then click on the board");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(5.f, 5.f);

    info.setFont(Assets::getInstance().font);
    info.setString("A - Spearman; S - Swordsman; D - Bowman");
    info.setCharacterSize(24);
    info.setFillColor(sf::Color::Black);
    info.setPosition(5.f, 30.f);

    line1[0] = sf::Vertex(sf::Vector2f(400, 640));
    line1[1] = sf::Vertex(sf::Vector2f(400, 85));
    line2[0] = sf::Vertex(sf::Vector2f(20, 85));
    line2[1] = sf::Vertex(sf::Vector2f(980, 85));

    line1[0].color = sf::Color::Magenta;
    line1[1].color = sf::Color::Magenta;
    line2[0].color = sf::Color::Magenta;
    line2[1].color = sf::Color::Magenta;
    return true;
}
void Render::render() {
    window.clear(sf::Color::White);
    window.draw(*this);
    window.draw(text);
    window.draw(info);
    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.display();
}
void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& el : game->getUnits()) {
        target.draw((*el).getTexture());
    }
    for(auto& el : game->getEnemies()) {
        target.draw((*el).getTexture());
    }
}

#endif //ARMA_RENDER_H
