// Alumno1: Pedro Bedmar Lopez
// Alumno2: Alejandro Escalona Garcia


#ifndef SIMULADOR_H
#define SIMULADOR_H


//#include <iostream>
#include <time.h>
#include<fstream>
#include <cmath>
#include <cstring>
#include <string>
#include "pelotas.h"
#include "utilidades.h"

using namespace std;
using namespace miniwin;

class Simulador{

private:
    int ancho;
    int alto;
    Pelotas original;
    Pelotas actual;
    
public:

   Simulador();
   
   Simulador(const string &cadena );
   
   ~Simulador();
   
   Pelotas & getActual();
   
   Pelotas & getOriginal();
   
   Pelotas getActual() const;
   
   Pelotas getOriginal() const;
   
   void step(int n);
   
   bool salvar(string cadena) const;


  
};

void pintar(const Simulador &partida, int espera2);


#endif /* SIMULADOR_H */

