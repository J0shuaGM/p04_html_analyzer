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

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <iostream>
#include <string>
#include <vector>

class Atributo {
  public:
    //Constructor por defecto
    Atributo() {}

    //Destructor
    ~Atributo() {}

    //Getters
    std::pair<std::string, int> getAtributo(int indice) { return atributo_[indice]; }
    std::vector<std::pair<std::string, int>> getVectorAtributo(void) { return atributo_; }

    //setters
    void setAtributo(const std::string comentario, int linea) { atributo_.push_back(std::pair<std::string, int>(comentario, linea)); }

  private:
    std::vector<std::pair<std::string, int>> atributo_;
};

#endif