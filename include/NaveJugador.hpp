#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <iostream>

class NaveJugador : public Subscriptor
{
private:
    sf::ConvexShape triangle;

public:
    NaveJugador(/* args */)
    {
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(0, 0));
        triangle.setPoint(1, sf::Vector2f(50, 0));
        triangle.setPoint(2, sf::Vector2f(25, 50));
        triangle.setFillColor(sf::Color::Red);
        triangle.setPosition(375, 275);
    }
    ~NaveJugador() {}
    void Actualizar(sf::Event evento)
    {
        // Controlar el objeto triangular con las flechas del teclado
        if (evento.key.code == sf::Keyboard::Left){
           // triangle.move(-5, 0);
            triangle.rotate(90);
        }
        else if (evento.key.code == sf::Keyboard::Right)
            triangle.move(5, 0);
        else if (evento.key.code == sf::Keyboard::Up)
            triangle.move(0, -5);
        else if (evento.key.code == sf::Keyboard::Down)
            triangle.move(0, 5);
    }
    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(triangle);
    }
};