// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 12/10/2019
// Archivo Automata.cpp: Implentacion de la clase Automata que se utilizara en 
//                       la clase Eliminador_Comentarios
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    12/10/2019 - Creación (primera versión) del código
//


#include <fstream>
#include <iostream>
#include "Automata.h"

Automata::Automata(std::string nombrefichero){
  this -> cargarAutomata(nombrefichero);
}

Automata::~Automata(){
}

void Automata::cargarAutomata(std::string nombrefichero){
  const std::string FINLINEA = "endl";
  const char CARACTERFINLINEA = '\n';
  std::ifstream readfile(nombrefichero);
  if (readfile.is_open()){
    readfile >> N_Estados_;
    readfile >> Arranque_;
    this -> Estado_Actual_ = this -> Arranque_;
    for ( int i = 0; i < N_Estados_; i++){
      Estado nuevoEstado;
      readfile >> nuevoEstado.setEstado() >> nuevoEstado.setAceptacion() 
               >> nuevoEstado.setN_Transiciones();
      std::pair<char, unsigned> nuevapareja;
      for ( int j = 0; j < nuevoEstado.getN_Transiciones(); j++){
        std::string palabrafichero;
        readfile >> palabrafichero;
        if (palabrafichero == FINLINEA){
          nuevapareja.first = CARACTERFINLINEA;
        } else if (palabrafichero.size() == 1){
          nuevapareja.first = palabrafichero[0];
        } else {
          std::cout << "ERROR, palabra desconocida al definir transicion de "
                    << "automata "<<palabrafichero<<CARACTERFINLINEA;
          exit(2);
        }            
        readfile >> nuevapareja.second;
        nuevoEstado.getTransiciones().push_back(nuevapareja);
      }
      nuevapareja.first = CUALQUIERCARACTER;
      readfile >> nuevapareja.second;
      nuevoEstado.getTransiciones().push_back(nuevapareja);
      this -> Automata_.insert(nuevoEstado);
    }
    readfile.close();  
  }else{
    std::cout << "ERROR, apertura de archivo de datos de automata " <<
                 nombrefichero << CARACTERFINLINEA;
    exit (1);
  }
}

unsigned Automata::avanza_caracter(char caracter){
  for (auto i = this -> Automata_.begin(); i != this -> Automata_.end(); i++){
    if ( i -> getEstado() == Estado_Actual_){
      int caracterdesconocido;
      int transicion = -1;
      for (int j = 0; j <= i->getN_Transiciones(); j++){
        if ( i ->Transiciones_[j].first == CUALQUIERCARACTER){
          caracterdesconocido = j;
        } else if (i -> Transiciones_[j].first == caracter){
          transicion = i -> Transiciones_[j].second;
        }
      }
      if (transicion == -1){
        transicion = i -> Transiciones_[caracterdesconocido].second;
      }
     Estado_Actual_ = transicion;
     break;  
    }
  }
    return Estado_Actual_;
}



