#include "utilidades.h"



using namespace std;
using namespace miniwin;

//Generales:

int RandomValor(int limite)
{
 

  int valor;

  valor = rand() % limite;

return valor;
}

string formato_color(PColor color)
{
    string color_final;
    
    PColor color2=PColor::ROJO;
    if(color2 == color)
        color_final="ROJO";
    else 
        color_final="VERDE";
    
    return color_final;

}

PColor formato_color(std::string color1)
{
    PColor color;
    if(color1 == "ROJO")
        color=PColor::ROJO;
    else
        color=PColor::VERDE;
    
    return color;

}


//Pelota:

void pintar(Pelota &P) {
    color((int) P.Get_color());
    circulo_lleno( P.Get_x() , P.Get_y() , P.Get_radio() );
}

void mover(Pelota &P){
    
   const float factor = 0.97;
   
   P.Set_x(P.Get_dx()+P.Get_x());
   P.Set_y(P.Get_dy()+P.Get_y());
   
   if (P.Get_x() > vancho() - P.Get_radio()) {
      P.Set_dx(-P.Get_dx() * factor);
      P.Set_x(vancho() - P.Get_radio());
   } 
	else if (P.Get_x() < P.Get_radio()) {
      P.Set_dx(-P.Get_dx() * factor);
      P.Set_x(P.Get_radio());
   } 
	else if (P.Get_y() > valto() - P.Get_radio()) {
      P.Set_dy(-P.Get_dy() * factor);
      P.Set_y(valto() - P.Get_radio());
   } 
	else if (P.Get_y() < P.Get_radio()) {
      P.Set_dy(-P.Get_dy() * factor);
      P.Set_y(P.Get_radio());
   }
   
  P.Set_dy(0.1+P.Get_dy());
}

void colisionar(Pelota &P, Pelota &T) {
    
    float auxiliary,auxiliarx;
    
    if(P.colisionado(T))
    {
        auxiliarx = (P.Get_dx());
        auxiliary = (P.Get_dy());
        P.Set_dx( T.Get_dx()*1.00 );
        P.Set_dy( T.Get_dy()*1.00 );
        T.Set_dx( auxiliarx*1.00 );
        T.Set_dy( auxiliary*1.00 );
    }
}

std::ostream& operator<<(std::ostream &os,const Pelota &p1 )
{

    
    os << p1.Get_x()<<" ";
    os << p1.Get_y()<<" ";
    os << p1.Get_dx()<<" ";
    os << p1.Get_dy()<<" " ;
    os << p1.Get_radio()<<" " ;
    os << formato_color( p1.Get_color() );
    return os;

}


std::istream& operator>>(std::istream &is, Pelota &p1)
{
    std::string auxcolor;
    float x,y,dx,dy,radio;
    
    is >> x;
    p1.Set_x(x);
    is >> y;
    p1.Set_y(y);
    is >> dx;
    p1.Set_dx(dx);
    is >> dy;
    p1.Set_dy(dy);
    is >>radio;
    p1.set_radio(radio);
    is >> auxcolor;
    PColor color2 =formato_color(auxcolor);
    p1.set_color(color2);
    
    return is;



}

//Pelotas:

void pintar(const Pelotas &P) {
    
    for(int i=0; i < P.Get_util(); i++){
        color((int) P.Get_pelota(i).Get_color());
        circulo_lleno( P.Get_pelota(i).Get_x() , P.Get_pelota(i).Get_y() , P.Get_pelota(i).Get_radio() );
    }
}



void mover(Pelotas &P){
   const float factor = 1;
   
   for(int i=0; i < P.Get_util(); i++)
   {
      mover(P.Get_pelota(i));

   
   }
}

void colisionar(Pelotas &P) {
    bool chocado=false;
    
    for(int i=0; i < P.Get_util(); i++){
        chocado=false;
        for(int k=i; k < P.Get_util() && !chocado; k++)
        {
            
            if(P.Get_pelota(i).colisionado(P.Get_pelota(k)))
            {
        
                if(i != k && P.Get_pelota(i).Get_color() == PColor::VERDE && P.Get_pelota(k).Get_color() == PColor::VERDE)
                { 
                    colisionar( P.Get_pelota(i), P.Get_pelota(k) );
                    Pelota pelota1=P.Get_pelota(i);
                    pelota1.Set_x(10+RandomValor(MIN_X-10));
                    pelota1.Set_y(10+RandomValor(MIN_Y-10));
                   if(P.Get_util() <10)
                   {
                       P.Aniadir(pelota1);
                       chocado=true;
                   }
                }
                
                if(i != k && P.Get_pelota(i).Get_color() == PColor::ROJO && P.Get_pelota(k).Get_color() == PColor::ROJO)
                {
                    colisionar( P.Get_pelota(i), P.Get_pelota(k) );
                }
                
                if(i != k && P.Get_pelota(i).Get_color() == PColor::ROJO && P.Get_pelota(k).Get_color() == PColor::VERDE)
                {
                    P.Borrar_pelota(k);
                }
                
                if(i != k && P.Get_pelota(i).Get_color() == PColor::VERDE && P.Get_pelota(k).Get_color() == PColor::ROJO)
                {
                    P.Borrar_pelota(i);
                }
                
                
                
            }
    
        }
    }
}

Pelotas & operator+=(Pelotas &P, const Pelota &pelota1)
{
    P.Aniadir(pelota1);   
    return P;
}

bool operator==(const Pelota &p1,const  Pelota &p2)
{
    if( p1.Get_radio() == p2.Get_radio() && p1.Get_color() == p2.Get_color() )
        return true;
    
    else
        return false;
}


std::ostream& operator<<(std::ostream &os,const Pelotas &p1 )
{
     for(int i=0; i < p1.Get_util(); i++){
        os << p1[i] << endl;
     }
    return os;

}



std::istream& operator>>(std::istream &is, Pelotas &p1)
{  
    Pelota aux;
    int n;
    is >> n;
    for(int i=0; i < n; i++)
    {
        is >> aux;
        p1.Aniadir(aux);
    }
    
    return is;

}


