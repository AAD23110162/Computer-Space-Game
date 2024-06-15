#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <iostream>

class NaveJugador : public Subscriptor
{
private:
    sf::CircleShape circle;

public:
    NaveJugador(/* args */)
    {
        circle.setRadius(25);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(375, 275);
    }
    ~NaveJugador() {}
    void Actualizar(sf::Event evento)
    {
        // Controlar el objeto circular con las flechas del teclado
        float velocidadMaxima = 100.0f;
        float aceleracion = 5.0f;

        if (evento.key.code == sf::Keyboard::Left){
            circle.move(-5, 0);
        }
        else if (evento.key.code == sf::Keyboard::Right){
            circle.move(5, 0);
        }
        else if (evento.key.code == sf::Keyboard::Up){
            sf::Vector2f currentVelocity = circle.getPosition();
            sf::Vector2f newVelocity = currentVelocity + sf::Vector2f(0, -aceleracion);
            if (newVelocity.y < -velocidadMaxima) {
                newVelocity.y = -velocidadMaxima;
            }
            circle.setPosition(newVelocity);
        }
        else if (evento.key.code == sf::Keyboard::Down){
            sf::Vector2f currentVelocity = circle.getPosition();
            sf::Vector2f newVelocity = currentVelocity + sf::Vector2f(0, aceleracion);
            if (newVelocity.y > velocidadMaxima) {
                newVelocity.y = velocidadMaxima;
            }
            circle.setPosition(newVelocity);
        }
    }
    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(circle);
    }
};
