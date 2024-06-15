#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <iostream>
#include <cmath>

class NaveJugador : public Subscriptor
{
private:
    sf::ConvexShape triangle;

public:
    NaveJugador(/* args */)
    {
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(-25, -25));
        triangle.setPoint(1, sf::Vector2f(25, -25));
        triangle.setPoint(2, sf::Vector2f(0, 25));
        triangle.setFillColor(sf::Color::Red);
        triangle.setPosition(375, 275);
    }
    ~NaveJugador() {}
    void Actualizar(sf::Event evento)
    {
        // Controlar el objeto triangular con las flechas del teclado
        if (evento.key.code == sf::Keyboard::Left){
           // triangle.move(-5, 0);
            triangle.rotate(-2);
        }
        else if (evento.key.code == sf::Keyboard::Right)
{

            triangle.rotate(2);
        }
            else if (evento.key.code == sf::Keyboard::Up) {
                float angle = triangle.getRotation();
                float radians = angle * 3.14159 / 180.0;
                float dx = std::sin(radians) * 5;
                float dy = -std::cos(radians) * 5;
                triangle.move(dx, dy);
            }
            else if (evento.key.code == sf::Keyboard::Down) {
                float angle = triangle.getRotation();
                float radians = angle * 3.14159 / 180.0;
                float dx = -std::sin(radians) * 5;
                float dy = std::cos(radians) * 5;
                triangle.move(dx, dy);
            }
    }
    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(triangle);
    }
};