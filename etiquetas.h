// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo etiquetas.h: contiene la declaracion de la clase objeto etiqueta

#ifndef ETIQUETAS_H
#define ETIQUETAS_H

#include <iostream>
#include <string>
#include <vector>

class Etiquetas {
  public:
    //Constructor por defecto
    Etiquetas() {}

    //Destructor
    ~Etiquetas() {}

    //Getters
    std::pair<std::string, int> getEtiqueta(int indice) { return etiquetas_[indice]; }
    std::vector<std::pair<std::string, int>> getVectorEtiquetas(void) { return etiquetas_; }

    //setters
    void setEtiquetas(const std::string etiqueta, int linea) { etiquetas_.push_back(std::pair<std::string, int>(etiqueta, linea)); }

  private:
    std::vector<std::pair<std::string, int>> etiquetas_;
};

#endif
