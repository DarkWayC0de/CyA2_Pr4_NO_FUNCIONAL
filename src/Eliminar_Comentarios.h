
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 12/10/2019
// Archivo Eliminar_Comentarios.h: Declaracion de la clase 
//                                 Eliminar_Comentarios
//
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    12/10/2019 - Creación (primera versión) del código
//

#ifndef ELIMINAR_COMENTARIOS_H
#define ELIMINAR_COMENTARIOS_H
#include "Automata.h"
#include <iostream>
class Eliminar_comentarios{
 public:
  ~Eliminar_comentarios();
  Eliminar_comentarios();
  void textoAprocesar(std::ostream& writefile, std::istream& readfile);
 private:
 Automata *Automata_;
 unsigned estadoactual_, estadopasado_;
 char caracteractual_ , caracterpasado_;

};

#endif //ELIMINAR_COMENTARIOS_H
