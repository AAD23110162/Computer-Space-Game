#include <SFML/Graphics.hpp>
#include <NaveJugador.hpp>
#include <Notificador.hpp>
#include <NaveEnemiga.hpp>
#include <Proyectil.hpp>

int main()
{
    // Crea una ventana de SFML con una resolución de 800x600 píxeles y un título "Computer Space"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Computer Space");
    NaveJugador naveJugador;
    NaveEnemiga naveEnemiga;
    Notificador notificador;
    notificador.AgregarSubscriptor(&naveJugador);

    std::vector<Proyectil> proyectiles; // Declare and initialize the `proyectiles` variable

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {   naveJugador.Actualizar(event);
                if (event.key.code == sf::Keyboard::Space)
                {
                    
                    naveJugador.disparar(proyectiles); // Use the `proyectiles` variable
                }
            }
        }
       
        window.clear(sf::Color::Black);

        // Dibujar el objeto triangular
        naveJugador.Dibujar(window);
        naveEnemiga.Dibujar(window);
        naveEnemiga.Mover();

        for (auto& proyectil : proyectiles)
        {
            proyectil.mover();
            proyectil.dibujar(window);
        }
        for (Proyectil& proyectil : proyectiles) {
    // Verifica si el proyectil y la nave enemiga están colisionando
    if (proyectil.getForma().getGlobalBounds().intersects(naveEnemiga.getForma().getGlobalBounds())) {
        // Aquí es donde manejas la colisión. Por ejemplo, podrías destruir la nave enemiga y el proyectil.
        std::cout << "Colision detectada!" << std::endl;
    }
}

        window.display();
    }

    return 0;
}
