# Universidad de La Laguna
# Escuela Superior de Ingenierıa y Tecnologıa
# Grado en Ingenierıa Inform´atica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 1: Contenedores asociativos
# Autor: Joshua Gomez Marrero 
# Correo: alu0101477398@ull.edu.es
# Fecha: 12/09/2026
# Archivo Makefile

# Nombre del archivo de salida
TARGET = analyzer

# Lista de archivos fuente(.cc)
SOURCES = cliente.cc tools.cc almacen.cc 

# Dependencias de los archivos fuente 
DEPENDENCIES = tools.h etiquetas.h documento.h comentarios.h atributos.h almacen.h
# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++17

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)