# Computer Space

### Por: Alejandro Aguirre Díaz y Alvaro Martin

## Descripción

Este proyecto tiene como objetivo recrear el clásico juego de arcade **Computer Space** de 1971 utilizando el lenguaje de programación C++. Computer Space es reconocido como uno de los primeros videojuegos de arcade comerciales y este proyecto busca rendir homenaje a ese hito en la historia de los videojuegos.

## Características

- Recreación lo mas fiel posible del juego original de Computer Space.
- Gráficos y sonidos retro para mantener la autenticidad del juego.
- Código escrito en C++ y modelado en su mayoria con clases y objetos.

# Descripción de Clases, Métodos y Relaciones

## 1. Juego

### Atributos:
- **ancho** (int): Dimensiones horizontales del juego.
- **alto** (int): Dimensiones verticales del juego.
- **nivelActual** (Nivel): Instancia de la clase Nivel que representa el nivel actual del juego.
- **puntaje** (int): Puntaje acumulado del jugador.
- **estaCorriendo** (bool): Estado que indica si el juego está en ejecución.

### Métodos:
- **iniciar()**: Inicia el juego estableciendo el nivel inicial y otros parámetros necesarios.
- **actualizar()**: Actualiza el estado del juego, incluyendo la lógica de movimiento y colisiones.
- **renderizar()**: Dibuja el estado actual del juego en la pantalla.
- **verificarColisiones()**: Verifica y maneja las colisiones entre naves y proyectiles.
- **terminar()**: Termina el juego y muestra los resultados finales.

## 2. Nivel

### Atributos:
- **numeroNivel** (int): Número que identifica el nivel actual.
- **jugador** (NaveJugador): Instancia de la nave del jugador.
- **enemigos** (List<NaveEnemiga>): Lista de naves enemigas en el nivel.
- **proyectiles** (List<Proyectil>): Lista de proyectiles en el nivel.

### Métodos:
- **iniciar()**: Configura los parámetros iniciales del nivel, como la posición de las naves y los enemigos.
- **actualizar()**: Actualiza el estado del nivel, manejando la lógica de juego específica del nivel.
- **renderizar()**: Dibuja el nivel en la pantalla, incluyendo naves y proyectiles.
- **verificarColisiones()**: Verifica colisiones dentro del nivel y actúa en consecuencia.
- **terminar()**: Termina el nivel y limpia los recursos.

## 3. Nave

### Atributos:
- **x** (int): Coordenada x de la nave.
- **y** (int): Coordenada y de la nave.
- **velocidad** (int): Velocidad de movimiento de la nave.
- **direccion** (int): Dirección del movimiento de la nave.

### Métodos:
- **mover()**: Mueve la nave en la dirección actual a la velocidad establecida.
- **disparar()**: Crea y devuelve un nuevo proyectil disparado desde la nave.

## 4. NaveJugador (hereda de Nave)

### Atributos:
- **vidas** (int): Cantidad de vidas del jugador.

### Métodos:
- **moverIzquierda()**: Mueve la nave del jugador a la izquierda.
- **moverDerecha()**: Mueve la nave del jugador a la derecha.
- **moverArriba()**: Mueve la nave del jugador hacia arriba.
- **moverAbajo()**: Mueve la nave del jugador hacia abajo.
- **disparar()**: Dispara un proyectil desde la nave del jugador.

## 5. NaveEnemiga (hereda de Nave)

### Atributos:
- **patronComportamiento** (int): Patrón de comportamiento que define cómo se mueve y actúa la nave enemiga.

### Métodos:
- **mover()**: Mueve la nave enemiga siguiendo su patrón de comportamiento.
- **disparar()**: Dispara un proyectil desde la nave enemiga.

## 6. Proyectil

### Atributos:
- **x** (int): Coordenada x del proyectil.
- **y** (int): Coordenada y del proyectil.
- **velocidad** (int): Velocidad del proyectil.
- **direccion** (int): Dirección en la que se mueve el proyectil.

### Métodos:
- **mover()**: Mueve el proyectil en la dirección actual a la velocidad establecida.

## 7. ControladorJuego

### Atributos:
- **juego** (Juego): Instancia del juego que está siendo controlado.

### Métodos:
- **manejarEntrada()**: Maneja la entrada del usuario, como teclas presionadas.
- **actualizarJuego()**: Actualiza el estado del juego según la entrada del usuario y la lógica del juego.
- **renderizarJuego()**: Renderiza el estado actual del juego en la pantalla.

## Relaciones y Multiplicidad

### Composición:
- Nivel tiene una relación de composición con NaveJugador, NaveEnemiga y Proyectil. Esto indica que cuando un Nivel es destruido, también lo son las instancias de estas clases.

### Multiplicidad:
- Nivel tiene un NaveJugador (1).
- Nivel puede tener múltiples NaveEnemiga (0..*).
- Nivel puede tener múltiples Proyectil (0..*).

### Asociación:
- Juego tiene una relación de asociación con Nivel, indicando que un Juego puede tener un nivel actual.
- ControladorJuego tiene una relación de asociación con Juego, indicando que controla el juego.

#### Multiplicidad:
- Juego tiene un Nivel (1).
- ControladorJuego controla un Juego (1).

## Herencia:
- NaveJugador y NaveEnemiga heredan de Nave.

## Descripción Extendida

### Juego:
Es la clase principal que gestiona el flujo del juego. Almacena las dimensiones del juego (ancho y alto), el nivel actual, el puntaje y el estado del juego (estaCorriendo).

Métodos clave incluyen:
- **iniciar()**: Configura el estado inicial del juego.
- **actualizar()**: Lógica principal que se ejecuta en cada frame.
- **renderizar()**: Dibuja el juego en pantalla.
- **verificarColisiones()**: Comprueba y maneja colisiones entre objetos.
- **terminar()**: Finaliza el juego.

### Nivel:
Representa un nivel dentro del juego. Contiene el número del nivel, el jugador (NaveJugador), listas de enemigos (NaveEnemiga) y proyectiles (Proyectil).

Métodos clave incluyen:
- **iniciar()**: Configura el estado inicial del nivel.
- **actualizar()**: Lógica específica del nivel que se ejecuta en cada frame.
- **renderizar()**: Dibuja el nivel en pantalla.
- **verificarColisiones()**: Comprueba y maneja colisiones dentro del nivel.
- **terminar()**: Finaliza el nivel.

### Nave:
Clase base para todos los tipos de naves. Atributos incluyen la posición (x, y), la velocidad y la dirección.

Métodos incluyen:
- **mover()**: Mueve la nave según su velocidad y dirección.
- **disparar()**: Genera un proyectil.

### NaveJugador (hereda de Nave):
Especifica las funcionalidades de la nave controlada por el jugador. Atributo adicional vidas.

Métodos incluyen:
- **moverIzquierda()**, **moverDerecha()**, **moverArriba()**, **moverAbajo()**: Movimientos del jugador.
- **disparar()**: Genera un proyectil.

### NaveEnemiga (hereda de Nave):
Especifica las funcionalidades de las naves enemigas. Atributo adicional patronComportamiento.

Métodos incluyen:
- **mover()**: Mueve la nave enemiga según su patrón.
- **disparar()**: Genera un proyectil.

### Proyectil:
Representa los proyectiles disparados por las naves. Atributos incluyen la posición (x, y), la velocidad y la dirección.

Método principal **mover()**: Actualiza la posición del proyectil.

### ControladorJuego:
Gestiona la interacción del usuario con el juego. Almacena una referencia al juego (juego).

Métodos incluyen:
- **manejarEntrada()**: Procesa la entrada del usuario.
- **actualizarJuego()**: Actualiza el estado del juego basándose en la entrada del usuario.
- **renderizarJuego()**: Renderiza el estado actual del juego en la pantalla.

Este diseño UML proporciona una visión clara de la estructura y relaciones entre las clases en el juego "Computer Space 1971", con detalles extendidos sobre los atributos, métodos y tipos de relaciones.

