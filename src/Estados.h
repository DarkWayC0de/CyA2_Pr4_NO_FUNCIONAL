// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 12/10/2019
// Archivo Estados.h: Declaracion de la clase Estados para crear un automa 
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    12/10/2019 - Creación (primera versión) del código
//

#ifndef ESTADO_H
#define ESTADO_H

#include <vector>

class Estado {
 public:
   std::vector<std::pair<char,unsigned>> Transiciones_;
   Estado();
   virtual ~Estado();
   unsigned getEstado() const;
   unsigned getN_Transiciones() const;
   bool getAceptacion() const;
   std::vector<std::pair<char, unsigned>>& getTransiciones();
   std::vector<std::pair<char, unsigned>>& setTransiciones();
   unsigned& setN_Transiciones();
   unsigned& setEstado();
   bool& setAceptacion();
   
   bool operator==(Estado& segundooperador);
   bool operator<(const Estado& segundooperador)const;
   

 private:
   unsigned Estado_, N_Transiciones_;
   bool Aceptacion_;
   //std::vector<std::pair<char,unsigned>> Transiciones_;
};

#endif //ESTADO_H

















































