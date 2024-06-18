#include <SFML/Graphics.hpp>
#include <NaveJugador.hpp>
#include <Notificador.hpp>
#include <NaveEnemiga.hpp>
#include <Proyectil.hpp>

int main()
{
    // Crea una ventana de SFML con una resolución de 800x600 píxeles y un título "Computer Space"
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Computer Space");
    NaveJugador naveJugador;
    NaveEnemiga naveEnemiga;
    Notificador notificador;
    notificador.AgregarSubscriptor(&naveJugador);

    std::vector<Proyectil> proyectiles; // Declare and initialize the `proyectiles` variable

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        // Error al cargar la fuente
        return -1;
    }
    sf::Text tiempoText;
    tiempoText.setFont(font);
    tiempoText.setCharacterSize(24);
    tiempoText.setFillColor(sf::Color::White);
    tiempoText.setPosition(10, window.getSize().y - 80);

    sf::Text colisionesText;
    colisionesText.setFont(font);
    colisionesText.setCharacterSize(24);
    colisionesText.setFillColor(sf::Color::White);
    colisionesText.setPosition(10, window.getSize().y - 40);

    sf::Clock clock;
    sf::Time tiempoTotal = sf::seconds(90.0f);
    sf::Time tiempoRestante = tiempoTotal;
    int colisiones = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                naveJugador.Actualizar(event);
                if (event.key.code == sf::Keyboard::Space)
                {
                    naveJugador.disparar(proyectiles); // Use the `proyectiles` variable
                }
            }
        }

        sf::Time deltaTime = clock.restart();
        tiempoRestante -= deltaTime;

        if (tiempoRestante <= sf::Time::Zero) {
            // El tiempo ha llegado a cero, finalizar el juego
            window.close();
            std::cout << "Game over" << std::endl;
        }

        tiempoText.setString("Tiempo: " + std::to_string(static_cast<int>(tiempoRestante.asSeconds())) + "s");
        colisionesText.setString("Score: " + std::to_string(colisiones));

        window.clear(sf::Color::Black);

        // Dibujar el objeto triangular
        naveJugador.Dibujar(window);
        naveEnemiga.Dibujar(window);
        naveEnemiga.Mover();

        for (auto& proyectil : proyectiles)
        {
            proyectil.mover();
            proyectil.dibujar(window);

            // Verifica si el proyectil y la nave enemiga están colisionando
            if (proyectil.getForma().getGlobalBounds().intersects(naveEnemiga.getForma().getGlobalBounds())) {
                // Aquí es donde manejas la colisión. Por ejemplo, podrías destruir la nave enemiga y el proyectil.
                std::cout << "Colision detectada!" << std::endl;
                colisiones++;
            }
        }

        window.draw(tiempoText);
        window.draw(colisionesText);

        window.display();
    }

    return 0;
}
