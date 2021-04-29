#ifndef ARMA_GRAPHICS_H
#define ARMA_GRAPHICS_H

#include "Assets.h"
#include "Color.h"
#include "UnitTexture.h"
#include <map>

class Graphics {
private:
    sf::RenderWindow window;
    std::map<std::string, sf::Text> texts;
    std::map<std::string, sf::Vertex[2]> lines;
    sf::Clock clock;
    sf::Event event{};
public:
    bool isWindowOpen();
    void createWindow(int, int, std::string, int);
    void display();
    void clear();
    void closeWindow();

    bool isPollEvent();
    bool isEventClosed() const;
    bool isEventMouseLeftButtonPressed() const;
    std::pair<float, float> getMousePosition() const;
    bool isEventKeyPressed() const;
    bool isKey_A() const;
    bool isKey_S() const;
    bool isKey_D() const;
    bool isKey_Enter() const;
    float getDeltaTimeAsMilliseconds();

    void createText(std::string, int, Color, float, float);
    void createText(std::string, std::string, int, Color, float, float);
    void setText(std::string, std::string s);
    void setTextColor(std::string, Color color);
    void createLine(std::string, std::pair<float, float>, std::pair<float, float>, Color);
    void setLineColor(std::string, Color);

    void drawText(std::string);
    void drawLine(std::string);
    void drawUnitTexture(UnitTexture&);
};

#endif //ARMA_GRAPHICS_H
