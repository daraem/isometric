#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "fisicas.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics");
    sf::Mouse mouse;

    window.setFramerateLimit(60);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<Circle> circles;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (mouse.isButtonPressed(mouse.Left)) {
            Circle circle;
            circle.shape.setRadius(25);
            circle.shape
            Sleep(100);
        }

        window.clear();
        for (const Circle& circle : circles) {
            window.draw(circle.shape);
        }
        update(circles);
        window.display();
    }

    return 0;
}
