#include <iostream> 
#include <ctime> 

#include "studente.h"
#include "lavoratore.h"
#include "pensionato.h"
#include "list_dl.h"
#include "cittadinolista.h"


using namespace std;

static void load(ListDL<Cittadino>&list){
    string nomi[30]={"Nino","Lapo","Divo","Lupo","Brando","Giusto","Sante","Elio","Attilio","Erenia","Fosco","Ferruccio","Fermo","Faber","Severo","Vladi","Milo","Ugo","Svevo","Sebastiano","Arturo","Saverio","Pedro","Placido","Edgardo","Ennio","Carlo Maria","Giuditta","Tecla","Arianna"};
    string cognomi[30]={"Ferraro", "Carpenteri", "Muratori", "Moltisanti", "Faro", "Gallo", "Tinè","Stanco", "Bella","Battiato","Morello","Sorge","Franco"," Betto", "Zello", "Gambino","Berlusconi", "Prodi", "Salvini", "Renzi", "Meloni", "Lombardo", "Napolitano", "D'Angelo", "D'Antonio", "Russo", "Tringali","Serra","Caruso","Buono"};
    string cities[30]={"Augusta","Catania","Bolzano","Milano","Enna","Bari","Palermo","Belpasso","Fano","Agira","Piacenza","Portofino","Riccione","Messina","Bologna","Trapani","Mazzara Del Vallo","Taormina","Empoli","Roma","Firenze","Napoli","Torino","Siracusa","Modena","Padova","Ferrara","Sassari","Latina","Pescara"}; 
    
    int n;
    int i=0;
    int ss=1,ll=1,pp=1;

    cout<<endl;
    cout <<"Quanti Cittadini vuoi inserire?"<<endl;
    cin>>n;
    cout<<endl;
    
while (i<n){
    int choice=rand()%3;

    //PUNTO A 
    switch(choice){
        case 0:{
        Studente s(nomi[(rand()%30)],cognomi[(rand()%30)],((rand()%19)+6),cities[(rand()%30)],((rand()%100+1) * 100),"Studente");
        list.insert(s);
        cout<<"Cittadino(Studente) caricato nella lista #"<<ss++<<" :"<<s<<endl;
        i++;
        break;
        }
        case 1:{
        Lavoratore l(nomi[(rand()%30)],cognomi[(rand()%30)],((rand()%52)+18),cities[(rand()%30)],((rand()%100+1) * 100),"Lavoratore");
        list.insert(l);
        cout<<"Cittadino(Lavoratore) caricato nella lista #"<<ll++<<" :"<<l<<endl;
        i++;
        break;}

        case 2:{
        Pensionato p(nomi[(rand()%30)],cognomi[(rand()%30)],((rand()%25)+65),cities[(rand()%30)],((rand()%100+1) * 100),"Pensionato");
        list.insert(p);
        cout<<"Cittadino(Pensionato) caricato nella lista #"<<pp++<<" :"<<p<<endl;
        i++;
        break;  }
    } 




}
}

int main(){
    srand(time(0));
    Cittadinolista a;
    int insertEta;
    
    //PUNTO B)
    load(a);
    cout<<endl;

    cout<<"Punto C) --> Visualizzazione Lista Ordinata per età: "<<endl;
    cout<< endl;

    cout<< a<<endl;
    cout<< endl;

    cout<< "Inserisci un'età per visualizzare tutti i cittadini che hanno minore o uguale età --> ";
    cin>>insertEta;
    a.search(insertEta);
}
