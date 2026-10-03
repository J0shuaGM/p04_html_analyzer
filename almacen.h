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

#ifndef ALMACEN_H
#define ALMACEN_H

#include "atributos.h"
#include "comentarios.h"
#include "etiquetas.h"
#include "documento.h"

class Almacen {
  public: 
    //Constructor
    Almacen() {};

    //Getters
    Atributo getAtributo(void) { return atributo_; }
    Comentarios getComentarios(void) { return comentarios_; }
    EstDocumento getDocumento(void) { return estructura_; }
    Etiquetas getEtiquetas(void) { return etiquetas_; }

    //Setters
    Atributo setAtributo(Atributo atributo) { atributo_ = atributo; }
    Comentarios setComentarios(Comentarios comentarios) { comentarios_ = comentarios; }
    EstDocumento setDocumento(EstDocumento estructura) { estructura_ = estructura; }
    Etiquetas setEtiquetas(Etiquetas etiquetas) { etiquetas_ = etiquetas; }

    //Sobrecarga del orperador de salida
    friend std::ostream& operator<<(std::ostream& salida, const Almacen almacen);

  private:
    Atributo atributo_; 
    Comentarios comentarios_; 
    EstDocumento estructura_;
    Etiquetas etiquetas_;
};


#endif