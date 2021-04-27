#ifndef ARMA_GRAPHICS_H
#define ARMA_GRAPHICS_H

#include "Assets.h"
#include <map>
#include "Color.h"

using UnitShape = sf::CircleShape;

class Graphics {
private:
    sf::RenderWindow window;
    std::map<std::string, sf::Text> texts;
    std::map<std::string, sf::Vertex[2]> lines;
    sf::Clock clock;
    sf::Event event{};
public:
    bool isWindowOpen() {
        return window.isOpen();
    }
    bool isPollEvent() {
        return window.pollEvent(event);
    }
    bool isEventClosed() const {
        return event.type == sf::Event::Closed;
    }
    bool isEventMouseLeftButtonPressed() const {
        return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
    }
    std::pair<float, float> getMousePosition() const {
        auto x = static_cast<float>(event.mouseButton.x);
        auto y = static_cast<float>(event.mouseButton.y);
        return {x, y};
    }
    bool isEventKeyPressed() const {
        return event.type == sf::Event::KeyPressed;
    }
    bool isKey_A() const {
        return event.key.code == sf::Keyboard::A;
    }
    bool isKey_S() const {
        return event.key.code == sf::Keyboard::S;
    }
    bool isKey_D() const {
        return event.key.code == sf::Keyboard::D;
    }
    bool isKey_Enter() const {
        return event.key.code == sf::Keyboard::Enter;
    }
    float getDeltaTimeAsMilliseconds() {
        float delta_time = static_cast<float>(clock.getElapsedTime().asMilliseconds());
        clock.restart();
        return delta_time;
    }
    void createWindow(int width, int height, std::string title, int limit) {
        window.create(sf::VideoMode(width, height), title);
        window.setFramerateLimit(limit);
    }
    sf::RenderWindow& getWindow() {
        return window;
    }
    void display() {
        window.display();
    }
    void clear() {
        window.clear(sf::Color::White);
    }
    void closeWindow() {
        window.close();
    }
    void createText(std::string id, int size, Color color, float x, float y) {
        texts[id].setFont(Assets::getInstance().font);
        texts[id].setCharacterSize(size);
        texts[id].setPosition(x, y);
        setTextColor(id, color);
    }
    void createText(std::string id, std::string s, int size, Color color, float x, float y) {
        createText(id, size, color, x, y);
        texts[id].setString(s);
    }
    void setText(std::string id, std::string s) {
        texts.at(id).setString(s);
    }
    void setTextColor(std::string id, Color color) {
        texts.at(id).setFillColor(color.getColor());
    }
    void createLine(std::string id, std::pair<float, float> p1, std::pair<float, float> p2, Color color) {
        lines[id][0] = sf::Vertex({p1.first, p1.second});
        lines[id][1] = sf::Vertex({p2.first, p2.second});
        setLineColor(id, color);
    }
    void setLineColor(std::string id, Color color) {
        lines.at(id)[0].color = lines.at(id)[1].color = color.getColor();
    }

    void drawText(std::string id) {
        window.draw(texts.at(id));
    }
    void drawLine(std::string id) {
        window.draw(lines.at(id), 2, sf::Lines);
    }
};

#endif //ARMA_GRAPHICS_H
