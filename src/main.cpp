// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 12/10/2019
// Archivo main.cpp: Programa principal en c++
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    12/10/2019 - Creación (primera versión) del código
//

#include <iostream>
#include "Eliminar_Comentarios.h"

int main(){
  Eliminar_comentarios A;
  A.textoAprocesar(std::cout,std::cin);
  return 0;
}
