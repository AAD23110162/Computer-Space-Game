#pragma once
#include <SFML/Graphics.hpp>

class Subscriptor
{
private:
    /* data */
public:
    Subscriptor(/* args */) {}
    ~Subscriptor() {}
    virtual void Actualizar(sf::Event evento) = 0;
};