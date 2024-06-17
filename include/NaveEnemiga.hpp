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
        rectangle.move(velocidad, 0);
        if (rectangle.getPosition().x >= 750 || rectangle.getPosition().x <= 0)
        {
            velocidad = -velocidad;
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