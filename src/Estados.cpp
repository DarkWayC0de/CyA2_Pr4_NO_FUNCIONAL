// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 12/10/2019
// Archivo Estados.cpp: Implentacion de la clase Estados para crear automata
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    12/10/2019 - Creación (primera versión) del código
//

#include "Estados.h"

Estado::Estado() : Estado_(0), N_Transiciones_(0), Aceptacion_(false) {
}

Estado::~Estado(){
}

bool Estado::operator==(Estado& segundooperador){
  if (this -> Estado_ != segundooperador.getEstado()) return false;
  if (this -> N_Transiciones_ != 
      segundooperador.getN_Transiciones()) return false;
  if (this -> Aceptacion_ != segundooperador.getAceptacion()) return false;
  if (this -> Transiciones_ != segundooperador.getTransiciones()) return false;
  return true;
}


bool Estado::operator<(const Estado& segundooperador) const{
  return (this -> Estado_ < segundooperador.getEstado());
}

unsigned Estado::getEstado() const{
  return this -> Estado_;
}

unsigned Estado::getN_Transiciones() const{
  return this -> N_Transiciones_;
}

bool Estado::getAceptacion() const{
  return this -> Aceptacion_;
}

std::vector<std::pair<char, unsigned>>& Estado::getTransiciones(){
  return this -> Transiciones_;
}

std::vector<std::pair<char, unsigned>>& Estado::setTransiciones(){
  return this -> Transiciones_;
}

unsigned& Estado::setN_Transiciones(){
  return N_Transiciones_;
}

unsigned& Estado::setEstado(){
  return Estado_;
}

bool& Estado::setAceptacion(){
  return Aceptacion_; 
}
