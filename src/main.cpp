#include <SFML/Graphics.hpp>
#include <NaveJugador.hpp>
#include <Notificador.hpp>
#include <NaveEnemiga.hpp>

int main()
{
    // Crea una ventana de SFML con una resolución de 800x600 píxeles y un título "Computer Space"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Computer Space");
    NaveJugador naveJugador;
    NaveEnemiga naveEnemiga;
    Notificador notificador;
    notificador.AgregarSubscriptor(&naveJugador);

    while (window.isOpen())
    {

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed)
                {
                    notificador.Notificar(event);
                }
            }

            window.clear(sf::Color::Black);

            // Dibujar el objeto triangular
            naveJugador.Dibujar(window);
            naveEnemiga.Dibujar(window);
            naveEnemiga.Mover();
            window.display();
        }

        // Muestra en pantalla los cambios realizados
        window.display();
    }

    return 0;
}