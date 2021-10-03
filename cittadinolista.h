#ifndef CITTADINOLISTA_H
#define CITTADINOLISTA_H

#include "list_dl.h"
#include "cittadino.h"

#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

class Cittadinolista:public ListDL<Cittadino>{
    public:
    Cittadinolista():ListDL<Cittadino>(true){}
    Cittadinolista(bool ascend):ListDL<Cittadino>(ascend){}

    void search(int e){
        NodeDL<Cittadino> *cur= this->head;
        int s1=0,l1=0,p1=0;
        while(cur!=NULL && cur->getValue().getEta()<=e){
           cout<<"Cittadino Trovato!"<< " ";
           cout<<*cur<<endl;
           if(cur->getValue().getStatus()=="Lavoratore"){
               l1++;
           }
           else if(cur->getValue().getStatus()=="Studente"){
               s1++;
           }
           else if (cur->getValue().getStatus()=="Pensionato"){
               p1++;
           }
            cur=cur->getNext();
        }
        cout<<"Totale-->  Studenti: "<<s1<<" Lavoratori: "<<l1<<" Pensionati: "<<p1<<endl;

        }
        

   
};


#endif