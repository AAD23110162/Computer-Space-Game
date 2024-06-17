class NaveEnemiga : public Subscriptor
{
private:
    sf::RectangleShape rectangle;
    float velocidad;
    float direccionX;
    float direccionY;

public:
    NaveEnemiga()
    {
        rectangle.setSize(sf::Vector2f(50, 50));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(375, 275);
        velocidad = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Velocidad aleatoria entre 1 y 5
        direccionX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Dirección aleatoria inicial entre 1 y 5
        direccionY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 4.0f + 1.0f; // Dirección aleatoria inicial entre 1 y 5
    }
    virtual ~NaveEnemiga() {}

    void Mover()
    {
        sf::Vector2f currentPosition = rectangle.getPosition();

        currentPosition.x += direccionX;
        currentPosition.y += direccionY;

        rectangle.setPosition(currentPosition);

        if (currentPosition.x >= 750 || currentPosition.x <= 0)
        {
            direccionX = -direccionX;
        }

        if (currentPosition.y >= 550 || currentPosition.y <= 0)
        {
            direccionY = -direccionY;
        }
    }

    void Dibujar(sf::RenderWindow &window)
    {
        window.draw(rectangle);
    }

    virtual void Actualizar(sf::Event evento) override
    {
        // Implementación específica para NaveEnemiga
    }
};
