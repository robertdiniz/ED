#include <iostream>

using namespace std;

/* Node */
class No {
    private:
        int valor;
        No* proxElem;
    public:
        No();
        int get_valor();
        No* get_proxElem();
        void set_valor(int novo_valor);
        void set_proxElem(No* proxElemento);
};

No::No(){
    valor = 0;
    proxElem = nullptr;
};

No* No::get_proxElem(){
    return proxElem;
};

void No::set_proxElem(No* proxElemento){
    proxElem = proxElemento;
};

int No::get_valor(){
    return valor;
};

void No::set_valor(int novo_valor){
    valor = novo_valor;
};

class Fila {
    private:
        No* primeiro;
        No* ultimo;
        int tamanho;
    public:
        Fila();
        No* get_primeiro();
        No* get_ultimo();
        void set_primeiro(No* elem);
        void set_ultimo(No* elem);
        void inserir_elemento(No* elemento);
        void retirar_elemento();
        void primeiro_fila();
        void ultimo_fila();
        int tamanho_fila();
};

Fila::Fila(){
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

No* Fila::get_primeiro(){
    return primeiro;
};

void Fila::set_primeiro(No* elem){
    primeiro = elem;
};

No* Fila::get_ultimo(){
    return ultimo;
};

void Fila::set_ultimo(No* elem){
    ultimo = elem;
};

void Fila::inserir_elemento(No* elemento){
    if(primeiro == nullptr){ // Não tem nenhum elemento / primeiro elemento
        primeiro = elemento;
        ultimo = elemento;
        elemento->set_proxElem(nullptr);
        tamanho++;
    } else {
        ultimo->set_proxElem(elemento);
        ultimo = elemento;
        tamanho++;
    }
};

void Fila::retirar_elemento(){
    if(tamanho == 0){
        cout << "Não tem nenhum elemento na fila!" << endl;
    } else {
        No* aux = primeiro;
        primeiro = primeiro->get_proxElem();
        if(primeiro == nullptr) {
            ultimo = nullptr;
        }
        delete aux;
        tamanho--;
    }
};

void Fila::primeiro_fila(){
    cout << primeiro->get_valor() << endl;
};

void Fila::ultimo_fila(){
    cout << ultimo->get_valor() << endl;
};

int Fila::tamanho_fila(){
    return tamanho;
};

int main(){

    Fila* fila = new Fila;
    No ele1, ele2, ele3;
    ele1.set_valor(10);
    ele2.set_valor(20);
    ele3.set_valor(30);
    cout << "Inserindo 1 elemento" << endl;
    fila->inserir_elemento(&ele1);
    fila->primeiro_fila();
    cout << fila->tamanho_fila() << endl;
    cout << "Inserindo 2° elemento" << endl;
    fila->inserir_elemento(&ele2);
    fila->primeiro_fila();
    fila->ultimo_fila();
    cout << fila->tamanho_fila() << endl;
    cout << ele1.get_proxElem()->get_valor() << endl;
    cout << "Inserindo 3° elemento" << endl;
    fila->inserir_elemento(&ele3);
    fila->primeiro_fila();
    fila->ultimo_fila();
    cout << fila->tamanho_fila() << endl;
    cout << "Apagando elementos 1" << endl;
    fila->retirar_elemento();
    fila->primeiro_fila();
    fila->ultimo_fila();
    cout << fila->tamanho_fila() << endl;
    cout << "Apagando elementos 2" << endl;
    fila->retirar_elemento();
    fila->primeiro_fila();
    fila->ultimo_fila();
    cout << fila->tamanho_fila() << endl;
    cout << "Apagando elementos 3" << endl;
    fila->retirar_elemento();
    fila->primeiro_fila();
    fila->ultimo_fila();
    cout << fila->tamanho_fila() << endl;

    delete fila;

    return 0;
};
