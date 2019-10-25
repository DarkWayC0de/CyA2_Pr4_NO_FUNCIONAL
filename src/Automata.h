// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 12/10/2019
// Archivo Automata.cpp: Declaracion de la clase Automata que sera usado por
//                      la clase Eliminador_Comentarios
//
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    12/10/2019 - Creación (primera versión) del código
//

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <set>
#include "Estados.h"

class Automata{
 public:
  Automata(std::string nombrefichero);
  ~Automata();
  unsigned avanza_caracter(char caracter);

 private:
   std::set<Estado> Automata_;
   unsigned N_Estados_, Arranque_, Estado_Actual_;
   const char CUALQUIERCARACTER = '#';
   void cargarAutomata(std::string nombrefichero);
};

#endif //AUTOMATA_H
