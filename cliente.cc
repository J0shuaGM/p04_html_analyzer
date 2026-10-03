// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo atributos.h: contiene la declaracion de la clase objeto astributo

#include <iostream>

#include "tools.h"
#include "almacen.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string fichero_entrada = argv[1]; 
  std::string fichero_salida = argv[2];
  std::ifstream entrada(fichero_entrada); 
  if(!entrada.is_open()) {
    std::cerr << "El fichero de entrda no se ha podido abrir" << std::endl;
    return 1;
  }
  Almacen almacen = Lectura(entrada);
  entrada.close(); 
  std::ofstream salida(fichero_salida); 
  if(!salida.is_open()) {
    std::cerr << "El fichero de salida no se ha podido abrir" << std::endl;
    return 1; 
  }
  Escritura(almacen, salida);
  salida.close();
  return 0;
}