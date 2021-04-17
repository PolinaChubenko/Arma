#ifndef ARMA_RENDER_H
#define ARMA_RENDER_H

#include "Assets.h"

class Render : public sf::Drawable, public sf::Transformable {
private:
    sf::RenderWindow window_;
    std::unique_ptr<Model> game_;
    sf::Text text_, info_;
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

Render::Render(Model* game) : game_(game) {
    initialize();
}
sf::RenderWindow& Render::getWindow() {
    return window_;
}
bool Render::initialize() {
    setPosition(25.f, 25.f);
    window_.setVerticalSyncEnabled(true);
    window_.create(sf::VideoMode(1000, 700), "Arma!");

    text_.setFont(Assets::getInstance().font);
    text_.setString("Press A / S / D to choose the unit; then click on the board");
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::Black);
    text_.setPosition(5.f, 5.f);

    info_.setFont(Assets::getInstance().font);
    info_.setString("A - Spearman; S - Swordsman; D - Bowman");
    info_.setCharacterSize(24);
    info_.setFillColor(sf::Color::Black);
    info_.setPosition(5.f, 30.f);
    return true;
}
void Render::render() {
    window_.clear(sf::Color::White);
    window_.draw(*this);
    window_.draw(text_);
    window_.draw(info_);
    window_.display();
}
void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& el : game_->getUnits()) {
        target.draw((*el).getTexture());
    }
}

#endif //ARMA_RENDER_H
