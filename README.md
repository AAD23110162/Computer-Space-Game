# Computer Space

### Por: Alejandro Aguirre Díaz y Alvaro Martin Ortiz Ascencio

## Descripción

Este proyecto tiene como objetivo recrear el clásico juego de arcade **Computer Space** de 1971 utilizando el lenguaje de programación C++. Computer Space es reconocido como uno de los primeros videojuegos de arcade comerciales y este proyecto busca rendir homenaje a ese hito en la historia de los videojuegos.

## Características

- Recreación lo más fiel posible del juego original de Computer Space.
- Gráficos y sonidos retro para mantener la autenticidad del juego.
- Código escrito en C++ y modelado en su mayoría con clases y objetos.

## Descripción de Clases, Métodos y Relaciones

### Juego
Representa el juego en sí, manteniendo el estado actual, como el nivel, el puntaje y si el juego está corriendo.
- Métodos:
  - `iniciar()`: Inicia el juego.
  - `actualizar()`: Actualiza el estado del juego.
  - `renderizar()`: Dibuja el estado actual del juego en la pantalla.
  - `verificarColisiones()`: Verifica si han ocurrido colisiones entre objetos del juego.
  - `terminar()`: Finaliza el juego.

### Nivel
Representa un nivel dentro del juego, incluyendo los enemigos, proyectiles y el jugador.
- Métodos:
  - `iniciar()`: Inicia el nivel.
  - `actualizar()`: Actualiza el estado del nivel.
  - `renderizar()`: Dibuja el estado actual del nivel en la pantalla.
  - `verificarColisiones()`: Verifica colisiones dentro del nivel.
  - `terminar()`: Finaliza el nivel.

### Nave
Clase abstracta que representa una nave genérica en el juego.
- Métodos:
  - `mover()`: Mueve la nave.
  - `disparar()`: Dispara un proyectil.

### NaveJugador
Representa la nave controlada por el jugador.
- Métodos:
  - `moverIzquierda()`, `moverDerecha()`, `moverArriba()`, `moverAbajo()`: Mueven la nave en las direcciones indicadas.

### NaveEnemiga
Representa una nave enemiga en el juego.
- Métodos:
  - `mover()`: Mueve la nave enemiga según su patrón de comportamiento.

### Proyectil
Representa un proyectil disparado por una nave.
- Métodos:
  - `mover()`: Mueve el proyectil.

### ControladorJuego
Controla la entrada del usuario y actualiza el juego basado en esa entrada.
- Métodos:
  - `manejarEntrada()`: Maneja la entrada del usuario.
  - `actualizarJuego()`: Actualiza el estado del juego basado en la entrada del usuario.
  - `renderizarJuego()`: Dibuja el estado actual del juego.

### Notificador
Maneja el sistema de notificaciones para eventos dentro del juego.
- Métodos:
  - `AgregarSubscriptor(subscriptor: Subscriptor*)`: Agrega un subscriptor a la lista de notificaciones.
  - `Notificar(evento: sf::Event)`: Notifica a todos los subscriptores sobre un evento.

### Subscriptor
Interfaz para clases que deseen subscribirse a notificaciones de eventos.
- Métodos:
  - `Actualizar(evento: sf::Event)`: Actualiza el estado del subscriptor basado en el evento.

## Relaciones

- `Juego` contiene un `Nivel`.
- `Nivel` contiene una `NaveJugador`, múltiples `NaveEnemiga` y `Proyectil`.
- `NaveJugador` y `NaveEnemiga` heredan de `Nave`.
- `ControladorJuego` tiene una relación de composición con `Juego`.
- `Notificador` tiene una relación de composición con `Subscriptor`, `NaveJugador`, `NaveEnemiga`, `Proyectil` y `ControladorJuego`, indicando que puede notificar a estas entidades sobre eventos.