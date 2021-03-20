#include "headers/Assets.h"
#include "headers/Unit.h"
#include "headers/UnitFactory.h"

#include <iostream>

int main() {
    std::unique_ptr<SpearmenFactory> spearmenFactory = std::make_unique<SpearmenFactory>();
    std::unique_ptr<SwordsmenFactory> swordsmenFactory = std::make_unique<SwordsmenFactory>();
    std::unique_ptr<BowmenFactory> bowmenFactory = std::make_unique<BowmenFactory>();

    std::vector<std::unique_ptr<Unit>> units;
    units.emplace_back(spearmenFactory->createUnit(1, 1));
    units.push_back(swordsmenFactory->createUnit(1, 1));
    units.push_back(bowmenFactory->createUnit(1, 1));

    for(auto& el : units) {
        el->getInfo();
        std::cout << "I have " << el->getHp() << " HP" << std::endl;
    }

    Assets::getInstance().load();
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
