#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
class NaveEnemiga : public Subscriptor
{
private:
    sf::RectangleShape rectangle;
    float velocidad;
    float direccionX;
    float direccionY;

public:
    NaveEnemiga()
    {
        rectangle.setSize(sf::Vector2f(20, 20));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(375, 275);
        velocidad = 0.01f; // Set the velocity to 1 unit per second
        direccionX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Random initial direction between 1 and 5
        direccionY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Random initial direction between 1 and 5
    }
    virtual ~NaveEnemiga() {}

    void Mover()
    {
        sf::Vector2f currentPosition = rectangle.getPosition();

        currentPosition.x += direccionX * velocidad;
        currentPosition.y += direccionY * velocidad;

        rectangle.setPosition(currentPosition);

        if (currentPosition.x >= 750 || currentPosition.x <= 0)
        {
            direccionX = -direccionX;
        }

        if (currentPosition.y >= 550 || currentPosition.y <= 0)
        {
            direccionY = -direccionY;
        }
    }
    sf::RectangleShape getForma() const
    {
        return rectangle;
    }
    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(rectangle);
    }

    virtual void Actualizar(sf::Event evento) override
    {
        // Implementación específica para NaveEnemiga
    }
};
