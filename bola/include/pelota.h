// Alumno1: Pedro Bedmar Lopez
// Alumno2: Alejandro Escalona Garcia


#ifndef PELOTA_H
#define PELOTA_H


#include "definiciones.h"


enum class PColor {
  NEGRO, ROJO, VERDE, AZUL,
  AMARILLO, MAGENTA, CYAN, BLANCO
};

class Pelota
{
private: 
    
    float x;
    float y;
    float dx;
    float dy;
    float Radio;
    PColor color;
   
public:
    
    Pelota();
    
    Pelota(float x1, float y1);
    
    Pelota(float x1, float y1, float dx1, float dy1, float radio, PColor color );
    
    Pelota(const Pelota &pelota1);

    float Get_x()const;
 
    float Get_y()const;

    float Get_dx()const;

    float Get_dy()const;
    
    float Get_radio()const;
    
    void Set_x(const float x1);
    
    void Set_y(const float y1);
    
    void Set_dx(const float dx1);
    
    void Set_dy(const float dy1);
    
    void set_radio(const float radio1);
    
    void set_color(const PColor color2);

    float distancia(const Pelota & dos)const;
    
    bool colisionado(const Pelota &dos);
    
    PColor Get_color() const;


};


#endif /* PELOTA_H */

