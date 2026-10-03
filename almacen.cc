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

#include "almacen.h"

/**
 * @brief Sobrecarga del operador de insercion para el análisis HTML
 * @param salida variable que contiene la salida de la escritura
 * @param almacen variable a ser escrita (contiene la estructura HTML, etiquetas, atributos y comentarios)
 */
std::ostream& operator<<(std::ostream& salida, Almacen almacen) {
  salida << "PROGRAM: pagina.html" << std::endl;
  salida << std::endl;
  salida << "DESCRIPTION: " << std::endl;
  if(!almacen.comentarios_.getVectorComentarios().empty()) {
    salida << almacen.comentarios_.getComentario(0).first << std::endl;
  }
  salida << std::endl; 
  salida << "STRUCTURE:" << std::endl;
  for(const auto& est : almacen.estructura_.getVectorEstructura()) {
    salida << est.first << ": " << (est.second ? "True" : "False") << std::endl;
  }

  if(almacen.estructura_.getDcotype().first) {
    salida << "DOCTYPE : HTML5" << std::endl;
  } else {
    salida << "DOCTYPE : False" << std::endl;
  }
  salida << std::endl;

  salida << "TAGS: " << std::endl;
  for(const auto& etiqueta : almacen.etiquetas_.getVectorEtiquetas()) {
    salida << "[Line " << etiqueta.second << "] " << etiqueta.first << std::endl;
  }
  salida << std::endl;

  salida << "ATTRIBUTES: " << std::endl;
  int ultima_linea = -1;
  std::string ultima_etiqueta;
  for(const auto& atributo : almacen.atributo_.getVectorAtributo()) {
    const std::size_t separador = atributo.first.find('\n');
    const std::string nombre_etiqueta = atributo.first.substr(0, separador);
    const std::string atributo_real = separador == std::string::npos
        ? atributo.first
        : atributo.first.substr(separador + 1);

    if(atributo.second != ultima_linea || nombre_etiqueta != ultima_etiqueta) {
      if(ultima_linea != -1) salida << std::endl;
      salida << "[Line " << atributo.second << "] " << nombre_etiqueta << std::endl;
      ultima_linea = atributo.second;
      ultima_etiqueta = nombre_etiqueta;
    }
    salida << atributo_real << std::endl;
  }
  salida << std::endl;
  
  salida << "COMMENTS: " << std::endl;
  for(int i = 0; i < almacen.comentarios_.getVectorComentarios().size(); ++i) {
    if(i == 0) {
      salida << "[Line " << almacen.comentarios_.getVectorComentarios()[i].second << "] DESCRIPTION" << std::endl;
      salida << almacen.comentarios_.getVectorComentarios()[i].first << std::endl; 
    } else {
      salida << "[Line " << almacen.comentarios_.getVectorComentarios()[i].second << "]" << std::endl;
      salida << almacen.comentarios_.getVectorComentarios()[i].first << std::endl; 
    }
    salida << std::endl;
  }
  return salida;
}