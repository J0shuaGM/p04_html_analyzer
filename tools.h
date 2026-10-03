// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo tools.h: contiene la declaracion diversas funciones de utilidad

#include <iostream>
#include <fstream>

#include "almacen.h"
#include "comentarios.h"
#include "documento.h"
#include "etiquetas.h"
#include "atributos.h"

void Usage(int argc, char *argv[]);
Almacen Lectura(std::ifstream& fichero);
void Escritura(Almacen almacen, std::ofstream& salida);