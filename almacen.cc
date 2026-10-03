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

  salida << "STRUCTURE: " << std::endl;
  for(const auto& est : almacen.estructura_.getVectorEstructura()) {
    salida << est.first << ": " << (est.second ? "True" : "False") << std::endl;
  }

  if(almacen.estructura_.getDcotype().first) {
    salida << "DOCTYPE" << std::endl;
    salida << "HTML5" << std::endl; 
  }
  salida << std::endl;

  salida << "TAGS: " << std::endl;
  for(const auto& etiqueta : almacen.etiquetas_.getVectorEtiquetas()) {
    salida << "[Line " << etiqueta.second << "] " << etiqueta.first << std::endl;
  }
  salida << std::endl;

  salida << "ATTRIBUTES: " << std::endl;
  int ultima_linea = -1; 
  std::string ultima_etiqueta_impresa = "";
  for(const auto& atributo : almacen.atributo_.getVectorAtributo()) {
    std::string contenido = atributo.first;
    size_t pos_salto = contenido.find('\n');
    std::string nombre_etiqueta = contenido.substr(0, pos_salto); 
    std::string atributo_real = contenido.substr(pos_salto + 1);
    if(atributo.second != ultima_linea || nombre_etiqueta != ultima_etiqueta_impresa) {
      if(ultima_linea != -1) salida << std::endl;
      salida << "[Line " << atributo.second << "] " << nombre_etiqueta << std::endl;
      ultima_linea = atributo.second;
      ultima_etiqueta_impresa = nombre_etiqueta;
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
  }
  return salida;
}