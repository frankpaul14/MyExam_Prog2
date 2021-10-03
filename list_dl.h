#ifndef LISTDL_H
#define LISTDL_H

#include <iostream> 
#include <sstream>

#include "nodedl.h"

using namespace std;

template<class T> 
class ListDL{
    protected:
    NodeDL<T> *head, *tail;
    int length;
    bool ascend;

    void insertAscending(T value){
        NodeDL<T> * temp=new NodeDL<T>(value);
        if( head== NULL && tail == NULL){
            this-> insertHead(value);
            return;
        }

        if ( head -> getValue()> value){
            this-> insertHead(value);
            return;
        }

        if ( tail -> getValue()<=value){
            this->insertTail(value);
            return;
        }

        NodeDL<T> * current = head;

        while ( current->getValue()<= value){
            current = current->getNext();
        }
        temp->setPrev(current->getPrev());
        temp->setNext(current);
        if (current->getPrev()) current->getPrev()->setNext(temp);
        current->setPrev(temp);

        length++;
    }




    void insertDiscending(T value){
         NodeDL<T> * temp=new NodeDL<T>(value);
        if( head== NULL && tail == NULL){
            this-> insertHead(value);
            return;
        }

        if ( head -> getValue()<= value){
            this-> insertHead(value);
            return;
        }

        if ( tail -> getValue()>value){
            this->insertTail(value);
            return;
        }

      NodeDL<T> * current = tail;

        while ( current->getValue()<= value){
            current = current->getPrev();
        }
        temp->setNext(current->getNext());
        temp->setPrev(current);
        if (current->getNext()) current->getNext()->setPrev(temp);
        current->setNext(temp);

        length++;
    }





    

    public:
    ListDL() : ListDL(true){}
    ListDL(bool ascend):head(NULL), tail(NULL), length(0),ascend(ascend){}

    void setAscendingOrder(){ascend =true;}
    void setDescendingOrder(){ascend = false;}

    NodeDL<T> * getHead() const {return this-> head;}
    NodeDL<T> * getTail() const {return this-> tail;}
    bool isAscending() const{return this-> ascend;}
    int getLength() const {return this-> length;}

    void insertHead(T value){
        
        NodeDL<T> *temp = new NodeDL<T>(value);
        if(head== NULL && tail== NULL){
            head=temp;
            tail=temp;
        }
        else{
            temp->setNext(head);
            head->setPrev(temp);
            head=temp; 
        }
        length++;
    }

    void insertTail(T value){
        
        NodeDL<T> *temp = new NodeDL<T>(value);
        if(head== NULL && tail == NULL){
            head=temp;
            tail=temp;
        }
        else{
            temp->setPrev(tail);  
            tail->setNext(temp); 
            tail=temp;  
        }
        length++;
    }

    void insert(T value){
        if(this-> isAscending())
            this->insertAscending(value);
        else
            this->insertDiscending(value);
        return;
    }

    void deleteValue(T value){
        NodeDL<T> * cur = head;
        while(cur!=NULL && cur->getValue()!=value){
            cur = cur->getNext();
        }
        if( cur== NULL){
            cout<<"ERRORE value : "<<value << "  NOT FOUND !!"<<endl;
            return;
        }

        this->deleteNode(cur);
    }

    void deleteNode(NodeDL<T> *cur){
        if (cur!= head)
            cur->getPrev()->setNext(cur->getNext());
        if(cur!= tail)
            cur->getNext()->setPrev(cur->getPrev());
        length--;

        if(cur==head) head = head->getNext();
        if(cur==tail) tail= tail->getPrev();

        delete cur;
    }

    friend ostream& operator<<(ostream& out,const ListDL<T> list){
        out<< " List di lunghezza "<<list.length<<", head= "<< list.head<<", tail= "<<list.tail<<endl;
        NodeDL<T> * cur = list.head;
        while(cur != NULL){
            out<< *cur<< endl;
            cur= cur-> getNext();
        }
        return out; 
    }

    bool isEmpty(){
        return (length==0);
    }

    

};

#endif 