#ifndef PENSIONATO_H
#define PENSIONATO_H

#include <iostream>
#include <sstream> 
#include <cstdlib>
#include <ctime>

#include "cittadino.h"

using namespace std;

class Pensionato : public Cittadino{
   
    public:
        Pensionato(string nome, string cognome, int eta, string city, double stipendio,string status) : 
        Cittadino(nome, cognome, eta, city,stipendio,"Pensionato"){}
        Pensionato():Cittadino("","",0,"",0.0,"Pensionato"){}

    friend ostream& operator<<(ostream& out, const Pensionato& c){
        out << c.nome << ", " << c.cognome << ", " << c.eta << ", " << c.city << ", " << c.stipendio<< ", "<<c.status;
		return out;
    }
};
#endif