// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo comentarios.h: contiene la declaracion de la clase objeto comentarios

#ifndef COMENTARIOS_H
#define COMENTARIOS_H

#include <iostream>
#include <string>
#include <vector>

class Comentarios {
  public:
    //Constructor por defecto
    Comentarios() {}

    //Destructor
    ~Comentarios() {}

    //Getters
    std::pair<std::string, int> getComentario(int indice) { return comentarios_[indice]; }
    std::vector<std::pair<std::string, int>> getVectorComentarios(void) { return comentarios_; }

    //setters
    void setComentarios(const std::string comentario, int linea) { comentarios_.push_back(std::pair<std::string, int>(comentario, linea)); }

  private:
    std::vector<std::pair<std::string, int>> comentarios_;
};

#endif