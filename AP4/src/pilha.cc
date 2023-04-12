#include "pilha.hh"

Pilha::Pilha() {
    this->_top = -1;
}

bool Pilha::isEmpty() {
    if (this->_top == -1) return true;
    else return false;
}

void Pilha::toStack(int item) {
    // Como a operação de empilhar adiciona o elemento ao fim (topo da pilha), podemos apenas chamar a função de enfileirar,
    // a qual também adiciona o elemento ao fim (da fila)
    this->_fila.toQueue(item);
    this->_top++;
}

int Pilha::unstack() {
    if (this->_top == -1) throw excpt("ERRO: Pilha vazia");

    FilaCircular aux;

    // Enquanto não chegar no último elemento da pilha '_fila', desenfileira os elementos e armazena
    // na fila aux
    while (this->_fila.getLength() > 1) {
        aux.toQueue(this->_fila.unqueue());
    }

    // Pega o item que deve sem desempilhado
    int item = _fila.unqueue();

    // Passa todos os elementos restantes a fila original
    while (!aux.isEmpty()) {
        this->_fila.toQueue(aux.unqueue());
    }

    this->_top--;

    return item;
}

int Pilha::getLenght() {
    return this->_top + 1;
}

// Limpa a pilha
void Pilha::emptyStack() {
    this->_top = -1;
    this->_fila.emptyQueue();
}
