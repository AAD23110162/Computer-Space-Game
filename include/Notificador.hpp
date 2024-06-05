#pragma once
#include <list>
#include <Subscriptor.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class Notificador
{
private:
    list<Subscriptor *> observers;
public:
    Notificador(/* args */) {}
    ~Notificador() {}
    void AgregarSubscriptor(Subscriptor *subscriptor)
    {
        observers.push_back(subscriptor);
    }
    void Notificar(sf::Event evento)
    {
        for (auto &subscriptor : observers)
        {
            subscriptor->Actualizar(evento);
        }
    }
};