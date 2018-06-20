#ifndef FILA_HPP
#define FILA_HPP
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T info;
    Node<T>* next;
    Node(): next(nullptr){};
};

template <typename T>
class Fila {
    
private:
    Node<T> *primeiro;
    Node<T> *ultimo;
    int cont;

public:
    Fila();
    ~Fila();
    bool Vazia() const;
    void Insere(const T info);
    T Retira();
    void Deleta();
    void Print();
    
};

template <typename T>
Fila<T>::Fila(){
    primeiro = ultimo = nullptr;
    cont = 0;
}

template <typename T>
Fila<T>::~Fila(){
    Node<T> *temp;
    while(primeiro != nullptr){
     temp = primeiro->next;
     delete primeiro;
     primeiro = temp;
    }
}
    
template <typename T>
bool Fila<T>::Vazia() const{
    return primeiro == nullptr && ultimo == nullptr;
}

template <typename T>
void Fila<T>::Insere(const T vinfo){
    Node<T> *aux = new Node<T>;
    aux->info = vinfo;
    aux->next = nullptr;
    cont++;
        
    if(this->Vazia()){
        primeiro = aux;
        ultimo = primeiro;
        ultimo->next = primeiro;
    }
    else{
        ultimo->next = aux;
        ultimo = aux;
    }
}

template <typename T>
T Fila<T>::Retira(){
    T info;
    Node<T> *temp = new Node<T>;

    if(!this->Vazia()){
        info = primeiro->info;
        temp = primeiro;
        primeiro = primeiro->next;
        cont--;
        delete temp;
        return info;
    }
    else
       return 0;
}

template <typename T>
void Fila<T>::Print(){
    T aux;
    
    for(int i=0; i<cont; i++){
        aux = this->Retira();
        cout << aux << endl;
        Insere(aux);
    }
}
#endif
