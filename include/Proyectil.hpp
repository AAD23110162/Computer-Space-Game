#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <cmath>

class Proyectil : public Subscriptor {
private:
    sf::CircleShape forma;
    float velocidad = 0.000000001f;
    sf::Vector2f direccion;

public:
    Proyectil(float x, float y, float velocidad, sf::Vector2f direccion)
        : velocidad(velocidad), direccion(direccion) {
        forma.setRadius(5.0f);
        forma.setFillColor(sf::Color::Red);
        forma.setPosition(x, y);
    }

    void mover() {
        float angle = forma.getRotation();
        float radians = angle * 3.14159 / 180.0;
        float dx = std::sin(radians) * 2;
        float dy = -std::cos(radians) * 2;
        direccion = sf::Vector2f(dx, dy);
        forma.move(dx, dy);
    }

    virtual void Actualizar(sf::Event evento) override {
        // Implementación específica de cómo este proyectil responde a eventos.
        // Por ahora, está vacío porque los proyectiles generalmente no responden a eventos directamente.
    }

    void dibujar(sf::RenderTarget& target) {
        target.draw(forma);
    }

    sf::Vector2f getPosicion() const {
        return forma.getPosition();
    }
};;
