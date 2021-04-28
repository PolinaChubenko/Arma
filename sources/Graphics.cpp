#include "Graphics.h"

bool Graphics::isWindowOpen() {
    return window.isOpen();
}
void Graphics::createWindow(int width, int height, std::string title, int limit) {
    window.create(sf::VideoMode(width, height), title);
    window.setFramerateLimit(limit);
}
sf::RenderWindow& Graphics::getWindow() {
    return window;
}
void Graphics::display() {
    window.display();
}
void Graphics::clear() {
    window.clear(sf::Color::White);
}
void Graphics::closeWindow() {
    window.close();
}


bool Graphics::isPollEvent() {
    return window.pollEvent(event);
}
bool Graphics::isEventClosed() const {
    return event.type == sf::Event::Closed;
}
bool Graphics::isEventMouseLeftButtonPressed() const {
    return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
}
std::pair<float, float> Graphics::getMousePosition() const {
    auto x = static_cast<float>(event.mouseButton.x);
    auto y = static_cast<float>(event.mouseButton.y);
    return {x, y};
}
bool Graphics::isEventKeyPressed() const {
    return event.type == sf::Event::KeyPressed;
}
bool Graphics::isKey_A() const {
    return event.key.code == sf::Keyboard::A;
}
bool Graphics::isKey_S() const {
    return event.key.code == sf::Keyboard::S;
}
bool Graphics::isKey_D() const {
    return event.key.code == sf::Keyboard::D;
}
bool Graphics::isKey_Enter() const {
    return event.key.code == sf::Keyboard::Enter;
}
float Graphics::getDeltaTimeAsMilliseconds() {
    float delta_time = static_cast<float>(clock.getElapsedTime().asMilliseconds());
    clock.restart();
    return delta_time;
}


void Graphics::createText(std::string id, int size, Color color, float x, float y) {
    texts[id].setFont(Assets::getInstance().font);
    texts[id].setCharacterSize(size);
    texts[id].setPosition(x, y);
    setTextColor(id, color);
}
void Graphics::createText(std::string id, std::string s, int size, Color color, float x, float y) {
    createText(id, size, color, x, y);
    texts[id].setString(s);
}
void Graphics::setText(std::string id, std::string s) {
    texts.at(id).setString(s);
}
void Graphics::setTextColor(std::string id, Color color) {
    texts.at(id).setFillColor(color.getColor());
}
void Graphics::createLine(std::string id, std::pair<float, float> p1, std::pair<float, float> p2, Color color) {
    lines[id][0] = sf::Vertex({p1.first, p1.second});
    lines[id][1] = sf::Vertex({p2.first, p2.second});
    setLineColor(id, color);
}
void Graphics::setLineColor(std::string id, Color color) {
    lines.at(id)[0].color = lines.at(id)[1].color = color.getColor();
}


void Graphics::drawText(std::string id) {
    window.draw(texts.at(id));
}
void Graphics::drawLine(std::string id) {
    window.draw(lines.at(id), 2, sf::Lines);
}

