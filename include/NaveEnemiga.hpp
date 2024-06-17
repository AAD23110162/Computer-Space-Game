#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <memory>

class NaveEnemiga : public Subscriptor
{
private:
    sf::RectangleShape rectangle;
    float velocidad;

public:
    NaveEnemiga()
    {
        rectangle.setSize(sf::Vector2f(50, 50));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(375, 275);
        velocidad = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Velocidad aleatoria entre 1 y 5
    }
    virtual ~NaveEnemiga() {}

    void Mover()
    {
        sf::Vector2f currentPosition = rectangle.getPosition();
        float randomX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Random value between 1 and 5
        float randomY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Random value between 1 and 5

        currentPosition.x += randomX;
        currentPosition.y += randomY;

        rectangle.setPosition(currentPosition);

        if (currentPosition.x >= 750 || currentPosition.x <= 0)
        {
            randomX = -randomX;
        }

        if (currentPosition.y >= 550 || currentPosition.y <= 0)
        {
            randomY = -randomY;
        }
    }

    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(rectangle);
    }

    // Implementación del método virtual puro de Subscriptor
    virtual void Actualizar(sf::Event evento) override
    {
        // Implementación específica para NaveEnemiga
    }
};