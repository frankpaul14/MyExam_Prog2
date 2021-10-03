#ifndef LAVORATORE_H
#define LAVORATORE_H

#include <iostream>
#include <sstream> 
#include <cstdlib>

#include "cittadino.h"

using namespace std;

class Lavoratore : public Cittadino{
  
    public:
        Lavoratore(string nome, string cognome, int eta, string city, double stipendio,string status) : 
        Cittadino(nome, cognome, eta, city,stipendio,"Lavoratore"){}
        Lavoratore():Cittadino("","",0,"",0.0,"Lavoratore"){}

    friend ostream& operator<<(ostream& out, const Lavoratore& c){
        out << c.nome << ", " << c.cognome << ", " << c.eta << ", " << c.city << ", " << c.stipendio<< ", "<<c.status;
		return out;
    }
};
#endif