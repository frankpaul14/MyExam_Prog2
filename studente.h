#ifndef STUDENDE_H
#define STUDENDE_H

#include <iostream>
#include <sstream> 
#include <cstdlib>

#include "cittadino.h"

using namespace std;

class Studente : public Cittadino{
    
    public:
    Studente(string nome, string cognome, int eta, string city, double stipendio,string status) : 
    Cittadino(nome, cognome, eta, city,0.0,"Studente"){}
    Studente():Cittadino("","",0,"",0.0,"Studente"){}
    
   friend ostream& operator<<(ostream& out, const Studente& c){
        out << c.nome << ", " << c.cognome << ", " << c.eta << ", " << c.city << ", " << c.stipendio<< ", "<<c.status;
		return out;
    }
};
#endif