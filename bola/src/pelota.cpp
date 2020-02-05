/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "pelota.h"

using namespace std;


    Pelota::Pelota(){

        x=10+rand()%MIN_X-10;
        y=10+rand()%MIN_Y-10;
        dx=10+rand()%MAX_VEL-10;
        dy=10+rand()%MAX_VEL-10;
        Radio=30;
        color = PColor::ROJO;
        int eleccionColor = 1+rand()%2;
        
        switch(eleccionColor){
            case 1:
                color=PColor::ROJO;
                break;
            case 2:
                color=PColor::VERDE;
                break;
            default:
                color=PColor::ROJO;
        }
        

      }
    
 
     Pelota::Pelota(float x1, float y1)
     {
         x=x1;
         y=y1;
         dx=1;
         dy=1;
         Radio=20;
         color = PColor::ROJO;
     } 
     
    Pelota::Pelota(float x1, float y1, float dx1, float dy1, float radio, PColor color = PColor::ROJO)
    {
        x=x1;
        y=y1;
        dx=dx1;
        dy=dy1;
        Radio=radio;
        this->color = color;
    }
    
    Pelota::Pelota(const Pelota &pelota1)
    {
        x = pelota1.Get_x();
        y = pelota1.Get_y();
        dx = pelota1.Get_dx();
        dy = pelota1.Get_dy();
        Radio = pelota1.Get_radio();
        color = pelota1.Get_color();
    
    }

    float Pelota::Get_x() const
    {
      return x;
    }

    float Pelota:: Get_y() const
    {
      return y;
    }

    float Pelota:: Get_dx() const
    {
      return dx;
    }

    float Pelota:: Get_dy() const
    {
      return dy;
    }
    
    void Pelota:: Set_x(const float x1){
        x=x1;
    }
    
    void Pelota:: Set_y(const float y1){
        y=y1;
    }
    
    void Pelota:: Set_dx(const float dx1){
        dx=dx1;
    }
    
    void Pelota:: Set_dy(const float dy1){
        dy=dy1;
    }
    
    
    void Pelota:: set_color(const PColor color2)
    {
        color = color2;
    }
    
    float Pelota::distancia(const Pelota &dos) const
    {
        
        
        float distanciaX = x - dos.x;
        float distanciaY = y - dos.y; 
        
        distanciaX = (distanciaX * distanciaX);
        distanciaY = (distanciaY * distanciaY);
        
        float distancia = sqrt ( distanciaX + distanciaY) - Radio - dos.Radio;
        
        return distancia;
    }

       
    bool Pelota::colisionado(const Pelota &dos)
    {
        if (distancia(dos) <= UMBRAL)
            return true;
        
        else
            return false;
    
    }

    
     float Pelota::Get_radio() const
     {
         return Radio;
         
     }
     
     PColor Pelota::Get_color() const
     {
         return color;
     
     }
     
      void Pelota::set_radio(const float radio1)
      {
          Radio = radio1;
      
      }
    
    
