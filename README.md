# Computer Space

### Por: Alejandro Aguirre Díaz y Alvaro Martin Ortiz Ascencio

## Descripción

Este proyecto tiene como objetivo recrear el clásico juego de arcade **Computer Space** de 1971 utilizando el lenguaje de programación C++. Computer Space es reconocido como uno de los primeros videojuegos de arcade comerciales y este proyecto busca rendir homenaje a ese hito en la historia de los videojuegos.

## Características

- Recreación lo más fiel posible del juego original de Computer Space.
- Gráficos y sonidos retro para mantener la autenticidad del juego.
- Código escrito en C++ y modelado en su mayoría con clases y objetos.

## Descripción de Clases, Métodos y Relaciones
![Diagrama de Clases](assets/imagenes/Diagrama%20UML.png )
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

## Uso de la Clase Notificador y la Interfaz Subscriptor

### Clase Notificador

La clase `Notificador` permite realizar la comunicación entre diferentes partes del juego sin acoplamiento fuerte. Actúa como un publicador que notifica a sus suscriptores sobre eventos relevantes.

- **Métodos Principales**:
  - `AgregarSubscriptor(subscriptor: Subscriptor*)`: Añade un nuevo suscriptor a la lista de notificaciones.
  - `Notificar(evento: sf::Event)`: Notifica a todos los suscriptores registrados sobre un evento, llamando al método `Actualizar` de cada uno.

### Interfaz Subscriptor

La interfaz `Subscriptor` define cómo los objetos pueden registrarse para recibir notificaciones de eventos. Cualquier clase que implemente esta interfaz puede actuar como suscriptor.

- **Método Requerido**:
  - `Actualizar(evento: sf::Event)`: Define la acción a realizar cuando se recibe una notificación de evento.

### Flujo de Trabajo

1. **Registro**: Las clases interesadas en recibir notificaciones (`NaveJugador`, `NaveEnemiga`, `ControladorJuego`, etc.) se registran en el `Notificador` como suscriptores.
2. **Notificación**: Cuando ocurre un evento (entrada del usuario, cambios de estado, etc.), el `Notificador` invoca `Notificar`, pasando el evento a todos los suscriptores.
3. **Manejo de Eventos**: Los suscriptores, a través de su implementación de `Actualizar`, responden al evento de manera adecuada.

Este mecanismo facilita una comunicación eficiente y desacoplada entre diferentes componentes del juego, promoviendo un diseño de software más limpio y mantenible.