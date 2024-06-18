#pragma once
#include <SFML/Graphics.hpp>

class Colision {
public:
    bool verificarColision(int x1, int y1, int x2, int y2) {
        // Comparar las posiciones en x e y de los dos objetos
        if (x1 == x2 && y1 == y2) {
            incrementarContador(); // Incrementa el contador de colisiones
            return true; // Hay colisión
        }
        return false; // No hay colisión
    }

    int getContador() const {
        return contador;
    }

private:
    void incrementarContador() {
        contador++;
    }

    int contador = 0;
};