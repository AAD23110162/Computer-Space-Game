# Nombre del archivo ejecutable
TARGET = bin/main

# Compilador
CC = g++

# Rutas de las librerías de SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Directorio de los archivos fuente
SRC_DIR = src

# Obtener todos los archivos fuente en el directorio SRC_DIR
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(wildcard include/*.hpp)
	$(CC) $(CFLAGS) $^ -o $@ $(SFML_LIBS) -Iinclude

# Regla para ejecutar el programa
run: $(TARGET)
	$(TARGET)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)