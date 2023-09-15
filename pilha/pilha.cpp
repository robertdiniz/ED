#include <iostream>

using namespace std;

/*
Classe Nó

int valor -> valor do elemento
No* proxElem -> aponta para o próximo elemento da lista encadeada

*/
class No {
    public:
    int valor;
    No* proxElem = nullptr;
};


/*
Pilha

No* topo -> aponta para o último elemento da pilha
int tamanho -> tamanho da pilha, serve como var auxiliar
int tamanho_maximo -> define o tamanho máximo da pilha

*/
class Pilha {

public:
    No* topo;
    int tamanho; // tamanho da pilha - contador
    int tamanho_maximo; // tamanho máximo
    bool estavazia();
    bool estacheia();
    void empilhar(No &elemento);
    void desempilhar();
    void mostrar_topo();
    Pilha(int tam_max);
};

void Pilha::mostrar_topo(){
    cout << "O valor do topo da pilha é: " << topo->valor << endl;
};

void Pilha::desempilhar(){

    if(estavazia()){
        cout << "Não tem nenhum elemento!" << endl;
    } else {
        topo = topo->proxElem;
        tamanho--;
    }

};

void Pilha::empilhar(No &elemento){
        if(estavazia()){
            elemento.proxElem = topo;
            topo = &elemento;
            tamanho++;

        } else if(estacheia()){

        } else {
            elemento.proxElem = topo;
            topo = &elemento;
            tamanho++;
        }

};

Pilha::Pilha(int tam_max){
    tamanho_maximo = tam_max;
    tamanho = 0;
    topo = nullptr;
};

bool Pilha::estavazia(){
    if(tamanho == 0){
        return true;
    } else {
        return false;
    }
};

bool Pilha::estacheia(){
    if(tamanho == tamanho_maximo){
        cout << "A pilha está cheia!" << endl;
        return true;
    } else {
        return false;
    }
};

int main(){

    Pilha pilha(3);
    No no1, no2, no3;
    no1.valor = 5;
    no2.valor = 10;
    no3.valor = 15;
    pilha.empilhar(no1);
    pilha.empilhar(no2);
    pilha.empilhar(no3);
    pilha.desempilhar();
    pilha.desempilhar();
    pilha.desempilhar();
    pilha.desempilhar();

return 0;
};
