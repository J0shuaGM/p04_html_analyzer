// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expreciones regulares
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 5/10/2025
// Archivo tools.cc: delcaracion de funciones
// Contiene la implementacion de las fundciones que no pertenecen a metodos


#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

#include "tools.h"
#include "almacen.h"
#include "comentarios.h"
#include "documento.h"
#include "etiquetas.h"
#include "atributos.h"



/**
 * @brief Funcion que explica como usar este programa 
 * @param argc Numero de argumentos pasados por linea de comandos
 * @param agrv Las cadenas que han sido pasadas por linea de comandos
*/
void Usage(int argc, char* argv[]) {
  switch (argc) {
    case 1: {
      std::cerr << argv[0] << " Modo de empleo: ./Expresiones Entrada.cc Salida.txt" << std::endl;
      std::cerr << "Use: " << argv[0] << " --help para mas información" << std::endl;
      exit(EXIT_SUCCESS);
      break;
    }
    case 2: {
      std::string parametro = argv[1];
      if (parametro == "--help") {
        std::cout << "Este programa analiza un fichero en html y escribe sus caracteristicas en un fichero detexto" << std::endl;
        std::cout << "Se necesita un fichero html de entrada y un fichero .txt de salida para poder ser ejecutado" << std::endl;
        exit(EXIT_SUCCESS);
      }
      else {
        std::cerr << argv[0] << " Modo de empleo: ./Expreciones Entrada.cc Salida.txt" << std::endl;
        std::cerr << "Use: " << argv[0] << " --help para mas información" << std::endl;
        exit(EXIT_SUCCESS);
      }
      break;   
    }
    case 3: {
      break;
    }
    default: {
      std::cerr << argv[0] << " Modo de empleo: ./Expreciones Entrada.cc Salida.txt" << std::endl;
      std::cerr << "Use: " << argv[0] << " --help para mas información" << std::endl;
      exit(EXIT_SUCCESS); 
      break;
    }
  }
}



Almacen Lectura(std::ifstream& fichero) {
  std::string linea, comentario_encontrado; 
  int contador = 0; 
  bool dentro_comentario = false; 
  int linea_inicio_comentario = 0;

  //Expresiones regulares
  std::regex inicio_comentario(R"(<!--)");            // Detectar el inicio de comentario HTML
  std::regex fin_comentario(R"(-->)");                // Detectar el fin del comentario HTML
  std::regex comentario_una_linea(R"(<!--.*?-->)");   // Detectar comentario HTML en una sola línea
  std::regex doctype(R"(<!DOCTYPE\s+html>)");         // Detectar la estructura básica DOCTYPE
  std::regex expEtiquetas(R"(<\s*(/)?\s*(html|head|title|body|h1|p|a|img)\b([^>]*)>)"); // Detectar etiquetas
  std::regex expAtributos(R"ATTR(([a-zA-Z_:][a-zA-Z0-9_.:-]*)\s*=\s*("[^"]*"|'[^']*'|[^\s>]+))ATTR"); // Detectar atributos

  std::smatch coincidencias; 

  Almacen almacen; 
  Etiquetas etiquetas; 
  Comentarios comentario; 
  Atributo atributos; 
  EstDocumento estructura;

  while(std::getline(fichero, linea)) {
    ++contador; 

    //Busqueda de comentario multilinea
    if(dentro_comentario) {
      comentario_encontrado += linea + "\n";
      if(std::regex_search(linea, fin_comentario)) {
        dentro_comentario = false; 
        comentario.setComentarios(comentario_encontrado, linea_inicio_comentario);
      }
      continue; 
    }
    //Busqueda de comentario simple
    if(std::regex_search(linea, coincidencias, comentario_una_linea)) {
      comentario.setComentarios(coincidencias.str(), contador);
      continue; 
    }
    //Iniciar flag de comentario multiliena
    if(std::regex_search(linea, inicio_comentario)) {
      dentro_comentario = true; 
      linea_inicio_comentario = contador;
      comentario_encontrado = linea.substr(linea.find("<!--")) + "\n";
      continue; 
    }
    //Busqueda Doctype
    if(std::regex_search(linea, coincidencias, doctype)) {
      estructura.setDoctype(true, contador); 
    }
    //Busqueda de etiquetas
    auto etiquetas_begin = std::sregex_iterator(linea.begin(), linea.end(), expEtiquetas);
    auto etiquetas_end = std::sregex_iterator();
    for (std::sregex_iterator i = etiquetas_begin; i != etiquetas_end; ++i) {
      std::smatch match = *i;
      bool es_cierre = (match[1].str() == "/"); 
      std::string nombre_etiqueta = match[2].str();
      std::string atributos_str = match[3].str();
      etiquetas.setEtiquetas(es_cierre ? "/" + nombre_etiqueta : nombre_etiqueta, contador);
      if (!es_cierre && !atributos_str.empty()) {
        auto attr_begin = std::sregex_iterator(atributos_str.begin(), atributos_str.end(), expAtributos);
        auto attr_end = std::sregex_iterator();
        for (std::sregex_iterator a = attr_begin; a != attr_end; ++a) {
          std::smatch attr_match = *a;
          std::string par_texto = attr_match.str();
          std::string concatenar = nombre_etiqueta + "\n" + par_texto;
          atributos.setAtributo(par_texto, contador);
        }
      }
    }
  }
  almacen.setAtributo(atributos);
  almacen.setComentarios(comentario);
  almacen.setDocumento(estructura); 
  almacen.setEtiquetas(etiquetas);
  return almacen;
}



void Escritura(Almacen almacen, std::ofstream& salida) {
  salida << almacen; 
}