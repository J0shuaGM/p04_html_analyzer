// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo documento.h: contiene la declaracion de la clase objeto EstDocumento

#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <iostream>
#include <string>
#include <vector>

class EstDocumento {
  public:
    //Constructor por defecto
    EstDocumento() {}

    //Destructor
    ~EstDocumento() {}

    //Getters
    std::pair<std::string, int> getEstructura(int indice) { return estructuras_[indice]; }
    std::vector<std::pair<std::string, bool>> getVectorEstructura(void) { return estructuras_; }

    //setters
    void setEstructura(const std::string comentario, bool encontrado) { estructuras_.push_back(std::pair<std::string, int>(comentario, encontrado)); }
    void setDoctype(bool encontrado, int linea) { doctype_.first = encontrado; doctype_.second = linea; }

  private:
    std::vector<std::pair<std::string, bool>> estructuras_;
    std::pair<bool, int> doctype_;
};

#endif