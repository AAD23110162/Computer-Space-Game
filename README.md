# Computer Space

### Por: Alejandro Aguirre Díaz y Alvaro Martin Ortiz Ascencio
##### Video de ejecuion del juego: Haz click sobre la imagen para ver el video
[![Ver Video](./assets/imagenes/captura1.png)](./assets/video/Version%20FF.mp4 "Haz clic para ver el video") 

## Descripción

Este proyecto tiene como objetivo recrear el clásico juego de arcade **Computer Space** de 1971 utilizando el lenguaje de programación C++. Computer Space es reconocido como uno de los primeros videojuegos de arcade comerciales y este proyecto busca rendir homenaje a ese hito en la historia de los videojuegos.

## Características

- Recreación contemporanea del juego original de Computer Space.
- Gráficos y sonidos retro para mantener la autenticidad del juego.
- Código escrito en C++ y modelado en su mayoría con clases y objetos.

## Instrucciones para Compilar y Ejecutar el Juego

Dentro de este repositorio hay un archivo `makefile` que está diseñado para simplificar el proceso de compilación y ejecución del juego utilizando el compilador `g++` y las librerías de SFML. A continuación, se describen los componentes clave del `makefile` y cómo usarlo para compilar y ejecutar el juego.

## Componentes del Makefile

- **TARGET**: Especifica el nombre del archivo ejecutable que se generará, en este caso `bin/main`.
- **CC**: Define el compilador a usar, que es `g++` para programas en C++.
- **SFML_LIBS**: Incluye las banderas necesarias para enlazar las librerías de SFML, permitiendo el uso de gráficos, ventanas, sistema y audio.
- **SRC_DIR**: Indica el directorio donde se encuentran los archivos fuente `.cpp`.
- **SOURCES**: Utiliza una función de Makefile para encontrar automáticamente todos los archivos `.cpp` en el directorio especificado por `SRC_DIR`.

### Reglas del Makefile

- **Compilación (`$(TARGET)`)**: Compila el programa enlazando los archivos fuente `.cpp` y los archivos de cabecera `.hpp` con las librerías de SFML. El resultado es el archivo ejecutable definido en `TARGET`.
- **Ejecución (`run`)**: Ejecuta el archivo compilado.
- **Limpieza (`clean`)**: Elimina el archivo ejecutable para limpiar el directorio de trabajo.

### Cómo Compilar el Juego

Para compilar el juego, asegúrate de estar en el directorio que contiene el `Makefile` y ejecuta el siguiente comando en la terminal: **make**

Este comando compilará el juego generando el archivo ejecutable en la ubicación especificada por `TARGET`.

### Cómo Ejecutar el Juego

Una vez compilado el juego, puedes ejecutarlo con el siguiente comando: **make run**

Este comando buscará el archivo ejecutable y lo ejecutará, iniciando el juego.

### Cómo Limpiar los Archivos Generados
Si deseas eliminar el archivo ejecutable y limpiar tu directorio de trabajo, puedes usar el siguiente comando: **make clean**

Este comando eliminará el archivo ejecutable, dejando los archivos fuente intactos.

Siguiendo estas instrucciones, podrás compilar y ejecutar el juego de manera sencilla utilizando el `Makefile` proporcionado.

## Descripción de Clases, Métodos y Relaciones
![Diagrama de Clases](assets/imagenes/Diagrama%20UML2.png )

#### Programa principal `Main`
Es el programa principal que inicia la ejecución del juego realizando las siguiente funciones:
#### Inicialización de Componentes del Juego
- Se cargan y configuran los recursos necesarios para el juego, como sonidos (disparos) y fuentes para el texto.
- Se crea una ventana de juego usando SFML con un tamaño de 1200x800 píxeles y un título "Computer Space".
- Se instancian las naves del jugador y enemigas, así como un notificador que parece ser parte de un sistema de eventos o notificaciones.

#### Carga de Recursos
- Se intenta cargar una fuente desde el sistema para usarla en la visualización de texto en pantalla. Si la carga falla, el juego termina prematuramente.

#### Bucle Principal del Juego
- El juego entra en un bucle que se mantiene activo mientras la ventana del juego esté abierta.
- Dentro del bucle, se manejan eventos de entrada del usuario, como el cierre de la ventana y la detección de teclas presionadas. Específicamente, al presionar la tecla Espacio, el jugador dispara un proyectil.
- Se carga y reproduce un sonido cada vez que el jugador dispara.

#### Actualización del Estado del Juego
- Se lleva un registro del tiempo restante y las colisiones (puntuación) durante el juego.
- El tiempo restante se va reduciendo con cada iteración del bucle y, si llega a cero, el juego termina.
- Se actualiza el texto en pantalla para mostrar el tiempo restante y la puntuación actual.

#### Dibujo y Renderizado
- Se limpia la ventana con un fondo negro al inicio de cada iteración del bucle.
- Se dibujan la nave del jugador, las naves enemigas y los proyectiles en la ventana.
- Se verifica si algún proyectil ha colisionado con alguna de las naves enemigas para incrementar la puntuación.

#### Manejo de Colisiones
- Para cada proyectil disparado, se verifica si intersecta con alguna de las naves enemigas. En caso de colisión, se incrementa el contador de colisiones y se muestra un mensaje en la consola.

#### Finalización del Juego
- Si el tiempo restante llega a cero o si la ventana se cierra, el bucle principal termina y con él el juego, mostrando un mensaje de "Game over" en la consola.

Este programa demuestra el uso de SFML para la creación de juegos 2D en C++, abarcando la gestión de ventanas, eventos, gráficos, y sonidos. Además, introduce conceptos básicos de la programación de juegos como el manejo de colisiones, el control de tiempo, y la interacción con el usuario a través de entradas de teclado.

#### Clase `NaveJugador`
Representa la nave controlada por el jugador, con métodos para su actualización y dibujo.
- Atributos:
  - `triangle`: Forma geométrica de la nave.
- Métodos:
  - `NaveJugador()`: Constructor que inicializa la nave del jugador.
  - `~NaveJugador()`: Destructor.
  - `Actualizar(evento: sf::Event)`: Actualiza el estado de la nave basado en eventos.
  - `Dibujar(window: sf::RenderWindow)`: Dibuja la nave en la ventana proporcionada.
  - `getPosicion()`: Devuelve la posición actual de la nave.
  - `disparar(proyectiles: std::vector<Proyectil>&)`: Dispara un proyectil.

#### Clase `NaveEnemiga`
Representa las naves enemigas en el juego.
- Atributos:
  - `rectangle`: Forma geométrica de la nave enemiga.
  - `velocidad`, `direccionX`, `direccionY`: Atributos para el movimiento de la nave.
- Métodos:
  - `NaveEnemiga()`: Constructor que inicializa la nave enemiga.
  - `~NaveEnemiga()`: Destructor.
  - `Mover()`: Actualiza la posición de la nave enemiga.
  - `getForma()`: Devuelve la forma de la nave enemiga.
  - `Dibujar(window: sf::RenderWindow)`: Dibuja la nave enemiga en la ventana.
  - `Actualizar(evento: sf::Event)`: Actualiza el estado de la nave enemiga basado en eventos.

#### Clase `Proyectil`
Representa los proyectiles disparados por las naves.
- Atributos:
  - `forma`: Forma geométrica del proyectil.
  - `velocidad`: Velocidad de movimiento del proyectil.
- Métodos:
  - `Proyectil(x, y, velocidad, rotacion)`: Constructor que inicializa el proyectil.
  - `getForma()`: Devuelve la forma del proyectil.
  - `mover()`: Actualiza la posición del proyectil.
  - `Actualizar(evento: sf::Event)`: Actualiza el estado del proyectil basado en eventos.
  - `dibujar(target: sf::RenderTarget&)`: Dibuja el proyectil en el objetivo proporcionado.
  - `getPosicion()`: Devuelve la posición actual del proyectil.

#### Clase `Notificador`
Maneja el sistema de notificaciones para eventos dentro del juego.
- Atributos:
  - `observers`: Lista de subscriptores a notificaciones.
- Métodos:
  - `Notificador()`: Constructor.
  - `~Notificador()`: Destructor.
  - `AgregarSubscriptor(subscriptor: Subscriptor*)`: Agrega un subscriptor a la lista.
  - `Notificar(evento: sf::Event)`: Notifica a todos los subscriptores sobre un evento.

#### Clase `Subscriptor`
Interfaz para clases que deseen subscribirse a notificaciones de eventos.
- Métodos:
  - `Subscriptor()`: Constructor.
  - `~Subscriptor()`: Destructor.
  - `Actualizar(evento: sf::Event)`: Método para actualizar el estado basado en el evento.

### Relaciones entre las clases y el programa principal

- `Main` es la clase principal que inicia y controla el flujo del juego, interactuando directamente con `NaveJugador`, `NaveEnemiga`, `Notificador` y `Proyectil`.
- `Notificador` mantiene una relación de uno a muchos (`1` -- `*`) con `Subscriptor`, permitiendo que múltiples entidades se subscriban a notificaciones de eventos.
- `Subscriptor` es una interfaz implementada por `NaveJugador`, `NaveEnemiga` y `Proyectil`, lo que les permite recibir notificaciones de eventos y actuar en consecuencia.

Este diseño permite una arquitectura flexible y extensible, facilitando la adición de nuevas entidades que pueden interactuar con el sistema de eventos del juego.

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