// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 14/10/2019
// Archivo Eliminar_Comentarios.cpp: Implentacion de la clase 
//                                   Eliminar_Comentarios
//
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    14/10/2019 - Creación (primera versión) del código
//

#include <iostream>
#include "Eliminar_Comentarios.h"


Eliminar_comentarios::Eliminar_comentarios() : estadoactual_(0),
                                               estadopasado_(0),
                                               caracteractual_(' '),
                                               caracterpasado_(' ') {
  Automata_ = new Automata("data/grafo1.data");
}
Eliminar_comentarios::~Eliminar_comentarios(){
 delete[] Automata_;
}

void Eliminar_comentarios::textoAprocesar(std::ostream& writefile,
                                     std::istream& readfile){


  readfile.get( caracteractual_);
  while (!readfile.eof()){
      estadoactual_ = Automata_ -> avanza_caracter(caracteractual_);
   if (estadoactual_ == 0){
     switch (estadopasado_){
       case 0 :
         writefile << caracteractual_;
         break;
       case 1 :
         writefile << caracterpasado_;
         writefile << caracteractual_;
         break;
       case 2 :
         writefile << caracteractual_;
         break;
       default:
       break;
     }
   }
      caracterpasado_ = caracteractual_;
      estadopasado_ = estadoactual_;
      readfile.get( caracteractual_);
  }
  if (estadoactual_ == 1){
    writefile << caracterpasado_;
  }
}


