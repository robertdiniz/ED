#include <iostream>

using namespace std;

class No {
    private:
        int valor;
        No* next;
        No* prev;
    public:
        No();
        int get_valor();
        No* get_next();
        No* get_prev();
        void set_valor(int valor);
        void set_next(No* new_next);
        void set_prev(No* new_prev);
};

No::No(){
    valor = 0;
    next = nullptr;
    prev = nullptr;
};

int No::get_valor(){
    return valor;
};

No* No::get_next(){
    return next;
};

No* No::get_prev(){
    return prev;
};

void No::set_next(No* new_next){
    next = new_next;
};

void No::set_prev(No* new_prev){
    prev = new_prev;
};

void No::set_valor(int new_valor){
    valor = new_valor;
};

class Deque {

    private:
        No* first;
        No* last;
        int tamanho;
    public:
        Deque();
        No* get_first();
        No* get_last();
        int get_tamanho();
        void set_first(No* new_elem);
        void set_last(No* new_elem);
        void set_tamanho(int new_tamanho);
        void inicia_deque(Deque* d);
        void insertFirst(Deque* d, int x);
        void insertLast(Deque* d, int x);
};

void Deque::insertFirst(Deque* d, int x){
    if(get_tamanho() == 0){
        No* aux = new No();
        aux->set_valor(x);
        set_first(aux);
        set_last(aux);
        tamanho++;
    } else{
        No* aux = new No();
        aux->set_valor(x);
        aux->set_next(first);
        first->set_prev(aux);
        first = aux;
        tamanho++;
    }
};

void Deque::set_tamanho(int new_tamanho){
    tamanho = new_tamanho;
};

void Deque::set_last(No* new_elem){
    last = new_elem;
};

void Deque::set_first(No* new_elem){
    first = new_elem;
};

int Deque::get_tamanho(){
    return tamanho;
};

No* Deque::get_last(){
    return last;
};

No* Deque::get_first(){
    return first;
};

Deque::Deque(){
    first = nullptr;
    last = nullptr;
    tamanho = 0;
};

int main(){

    Deque* deque = new Deque();
    No* ele1, ele2, ele3;
    cout << "Olá!" << endl;
    cout << deque->get_tamanho() << endl;
    deque->insertFirst(deque, 5);
    cout << "Olá!" << endl;
    cout << deque->get_first()->get_valor() << endl;
    deque->insertFirst(deque, 10);
    cout << "Testando!" << endl;
    cout << deque->get_first()->get_valor() << endl;
    cout << deque->get_last()->get_valor() << endl;
    cout << deque->get_first()->get_next()->get_valor() << endl;

    return 0;
};