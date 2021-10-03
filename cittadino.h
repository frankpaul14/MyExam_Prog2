#ifndef CITTADINO_H
#define CITTADINO_H

#include <iostream>
#include <sstream> 

using namespace std;

class Cittadino{
    protected:
        string nome;
        string cognome;
        string city;
        double stipendio;
        string status;
        
    public: 
        int eta;
    
    Cittadino(string nome, string cognome , int eta, string city, double stipendio,string status):
    nome(nome),cognome(cognome),eta(eta),city(city),stipendio(stipendio),status(status) {}

    string getNome(){
        return nome;
    }

    string getCognome(){
        return cognome;
    }

    int getEta(){
        return eta;
    }

    string getCity(){
        return city;
    }
    

    double getStipendio(){
        return stipendio;
    }

    string getStatus(){
        return status;
    }

    void setNome(string s){
        nome=s;
    }

    void setCognome(string s){
        cognome=s;
    }

    void setEta(int n){
        eta=n;
    }

    void setCity(string s){
        city=s;
    }

    void setStipendio(double d){
        stipendio=d;
    }


    friend ostream& operator<<(ostream& out, const Cittadino& c){
        out << c.nome << ", " << c.cognome << ", " << c.eta << ", " << c.city << ", " << c.stipendio<< ", "<<c.status;
		return out;
    }

    bool operator > (const Cittadino&c)const{
        return this->eta>c.eta;
    }

    bool operator >= (const Cittadino&c)const{
        return this->eta>=c.eta;
    }

    bool operator < (const Cittadino&c)const{
        return this->eta<c.eta;
    }

    bool operator <= (const Cittadino&c)const{
        return this->eta<=c.eta;
    }

    bool operator == (const Cittadino&c)const{
        return this->eta==c.eta;
    }

};

#endif