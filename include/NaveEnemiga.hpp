#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

class NaveEnemiga : public Subscriptor
{
private:
    sf::RectangleShape rectangle;
    float velocidad;

public:
    NaveEnemiga(/* args */)
    {
        rectangle.setSize(sf::Vector2f(50, 50));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(375, 275);
        velocidad = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Random speed between 1 and 5
    }
    ~NaveEnemiga() {}

    void Mover()
    {
        // Actualizar la posición del rectángulo
        rectangle.move(velocidad, 0);

        // Cambiar la dirección de movimiento aleatoriamente
        if (rectangle.getPosition().x >= 750 || rectangle.getPosition().x <= 0)
        {
            velocidad = -velocidad;
        }
    }

    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(rectangle);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Window");

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    const int numNaves = 2;
    NaveEnemiga naves[numNaves];

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < numNaves; i++)
        {
            naves[i].Mover();
        }

        window.clear();
        for (int i = 0; i < numNaves; i++)
        {
            naves[i].Dibujar(window);
        }
        window.display();
    }

    return 0;
}