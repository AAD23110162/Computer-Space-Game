#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <Proyectil.hpp>
#include <iostream>
#include <cmath>
#include <ctime>

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
        triangle.setFillColor(sf::Color::Blue);
        triangle.setPosition(375, 275);
    }
    ~NaveJugador() {}
    void Actualizar(sf::Event evento)
    {
        // Controlar el objeto triangular con las flechas del teclado
        if (evento.key.code == sf::Keyboard::Left){
           // triangle.move(-5, 0);
            triangle.rotate(-8);
        }
        else if (evento.key.code == sf::Keyboard::Right){
            //triangle.move(5, 0);
            triangle.rotate(8);}

        
            //triangle.move(5, 0);
            else if (evento.key.code == sf::Keyboard::Up) {
                float angle = triangle.getRotation();
                float radians = angle * 3.14159 / 180.0;
                float dx = std::sin(radians) * 2;
                float dy = -std::cos(radians) * 2;
                
                // Define the maximum speed and acceleration values
                float maxSpeed = 100.0f;
                float acceleration = 5.0f;
                float deceleration = 0.1f;
                
                // Calculate the current speed
                float currentSpeed = std::sqrt(dx * dx + dy * dy);
                // Apply acceleration or deceleration based on the current speed and time elapsed
                if (currentSpeed < maxSpeed) {
               //     dx += std::sin(radians) * acceleration * evento.key.timeSinceLastFrame.asSeconds();
                //    dy -= std::cos(radians) * acceleration * evento.key.timeSinceLastFrame.asSeconds();
                } else if (currentSpeed > 0) {
               //     dx -= std::sin(radians) * deceleration * evento.key.timeSinceLastEvent.asSeconds();
               //     dy += std::cos(radians) * deceleration * evento.key.timeSinceLastEvent.asSeconds();
                }
                
                triangle.move(dx, dy);
            }else if (evento.key.code == sf::Keyboard::Down) {
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
    sf::Vector2f getPosicion() const
    {
        return triangle.getPosition();
    }
    
    void disparar(std::vector<Proyectil>& proyectiles) 
    {
        sf::Vector2f posicion = this->getPosicion();
        sf::Vector2f direccion = {0, -1}; // Hacia arriba
        proyectiles.push_back(Proyectil(posicion.x, posicion.y, 10.0f, direccion));
    }
};