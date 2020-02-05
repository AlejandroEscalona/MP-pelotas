
#include "pelotas.h"


using namespace std;

Pelotas::Pelotas() 
{
    util=0;
    capacidad=1;
    v = new Pelota [capacidad];
}

Pelotas::Pelotas(const Pelota &pelota1)
{
    v=new Pelota[1];
    v[0]=pelota1;
    capacidad=1;
    util=1;
}

Pelotas::Pelotas(int numero)
{
  
    v= new Pelota[numero];
    capacidad = numero;
    util = 0;

}

Pelotas::Pelotas(const Pelotas &P)
{
    util = P.util;
    capacidad = P.capacidad;
    v = new Pelota[capacidad];
    
    for(int i=0; i < util; i++)
    {
        v[i]=P.Get_pelota(i);
    }


}



int Pelotas::Get_capacidad() const
{
    return capacidad;
}
    
int Pelotas::Get_util() const
{
    return util;
}

void Pelotas::set_util(int util2)
{
    util = util2;
}


void Pelotas::Aniadir(const Pelota &pelota2)
{
    if(util < capacidad)
    {
        v[util] = pelota2;
        util++;
    }
    
    else
    {
        Pelota *aux;
        capacidad = capacidad * 5;
        aux = new Pelota [capacidad];
        
        for(int i=0; i < util;i++)
        {
            aux[i]=v[i];
        }
        
        aux[util]= pelota2;
        util++;
        
        delete [] v;
        v=aux;
    
    }

}

Pelota Pelotas::Get_pelota(int posicion) const
{
    return v[posicion];
}


Pelota & Pelotas::Get_pelota(int posicion) 
{
    return v[posicion];
}

void Pelotas::Borrar_pelota(int posicion)
{
                util--;

    for(int i=posicion; i < util; i++)
    {
        v[i]=v[i+1];
    }
     
            

}

Pelotas::~Pelotas()
{
    delete [] v;
    v = nullptr;
}

Pelota &Pelotas::operator[](int numero)
{
    if(numero < util && numero >= 0)
      return v[numero];
    else
        cerr << "Error, fuera de rango";
}

const Pelota &Pelotas::operator[](int numero) const
{
     if(numero < util && numero >= 0)
      return v[numero];
    else
        cerr << "Error, fuera de rango";
}

Pelotas &Pelotas::operator=(const Pelotas &p1)
{
    if(p1.util <  capacidad )
    {
        for(int i=0; i < p1.util; i++)
            v[i] = p1[i];
            
        util= p1.util;
    }
    else
    {
        delete  [] v;
        capacidad = p1.capacidad;
        util = p1.util;
        
        v = new Pelota[p1.capacidad];
        
        for(int i=0; i < p1.util; i++)
            v[i] = p1[i];
        
   
    
    }

}

