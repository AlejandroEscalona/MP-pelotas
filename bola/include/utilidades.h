// Alumno1: Pedro Bedmar Lopez
// Alumno2: Alejandro Escalona Garcia


#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>
#include <time.h>
#include "miniwin.h"
#include "pelotas.h"



//Generales:

int RandomValor(int limite);

std::string formato_color(PColor color);

PColor formato_color(std::string color1);

//Pelota:

void pintar(Pelota &P);

void mover(Pelota &P);

void colisionar(Pelota &P, Pelota &T);

bool operator==(const Pelota &p1,const  Pelota &p2);

std::ostream& operator<<(std::ostream &os,const Pelota &p1);

std::istream& operator>>(std::istream &is, Pelota &p1);

//Pelotas:

void colisionar(Pelotas &P);

void mover(Pelotas &P);

void pintar(const Pelotas &P);

Pelotas & operator+=(Pelotas &P, const Pelota &pelota1);

std::ostream& operator<<(std::ostream &os,const Pelotas &p1);

std::istream& operator>>(std::istream &is, Pelotas &p1);

#endif /* UTILIDADES_H */

