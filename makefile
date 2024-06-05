# Nombre del archivo ejecutable
TARGET = bin/main

# Compilador
CC = g++

# Rutas de las librerías de SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Archivos fuente
SOURCES = src/main.cpp

# Regla para compilar el programa
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(SFML_LIBS) -Iinclude

# Regla para ejecutar el programa
run: $(TARGET)
	$(TARGET)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)