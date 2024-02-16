#pragma once

#include <C:\Users\daraem\source\repos\physicsplus\SFML\include\SFML\Graphics.hpp>

SquareForm sForm;

void cameraZoom(sf::Event event, float& size, float& positionX, float& positionY) {
    if (event.type == sf::Event::MouseWheelMoved)
    {
        if (event.mouseWheel.delta < 0) {
            sForm.zoomOut(size, positionX, positionY);
        }
        else {
            sForm.zoomIn(size, positionX, positionY);
        }
    }
}

void cameraMovement(float& size, float& positionX, float& positionY) {
    float v = 1.5f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        positionX += size * v;
        positionY += size * v;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        positionX -= size * v;
        positionY -= size * v;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        positionX += size * v;
        positionY -= size * v;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        positionX -= size * v;
        positionY += size * v;
    }
}

void mouse(sf::RenderWindow &window, SquareForm &Sform, int size) {
    sf::Mouse mouse;
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(mouse.getPosition(window));
    sf::Color color = { 0,0,0 };

    for (uint32_t i = 0; i < sForm.positions.size(); i++) {
        if (mousePos.x >= sForm.positions[i].x && mousePos.x <= sForm.positions[i].x + size && mousePos.y >= sForm.positions[i].y && mousePos.y <= sForm.positions[i].y + size) {
            Sform.addSquareSELECTOR(size, sForm.positionsRB[i], { 255,0,0 });
        }
    }
}

bool mouseConf(sf::RenderWindow &window) {
    return false;
}