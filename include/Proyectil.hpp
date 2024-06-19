#pragma once
#include <SFML/Graphics.hpp>
#include <Subscriptor.hpp>
#include <cmath>

class Proyectil : public Subscriptor {
private:
    sf::CircleShape forma;
    float velocidad = 0.000000001f;

public:
    Proyectil(float x, float y, float velocidad, float rotacion)
        : velocidad(velocidad) {
        forma.setRadius(5.0f);
        forma.setFillColor(sf::Color::Red);
        forma.setPosition(x, y);
        forma.setRotation(rotacion);
    }
    sf::CircleShape getForma() const {
        return forma;
    }
    void Mover() {
        float angle = forma.getRotation();
        float radians = angle * 3.14159 / 180.0;
        float dx = std::sin(radians) * 2;
        float dy = -std::cos(radians) * 2;
        forma.move(dx, dy);
    }

    virtual void Actualizar(sf::Event evento) override {
        // Implementación específica de cómo este proyectil responde a eventos.
        // Por ahora, está vacío porque los proyectiles generalmente no responden a eventos directamente.
    }

    void Dibujar(sf::RenderTarget& target) {
        target.draw(forma);
    }

    sf::Vector2f GetPosicion() const {
        return forma.getPosition();
    }
};;
