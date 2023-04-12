#include "fila.hh"

FilaCircular::FilaCircular() {
    this->_lenght = 0;
    this->_front = 0;
    this->_back = 0;
}

int FilaCircular::getLength() {
    return this->_lenght;
}

bool FilaCircular::isEmpty() {
    if (this->_lenght == 0) return true;
    else return false;
}

// Adiciona um item ao fim da fila
void FilaCircular::toQueue(int item) {
    if (this->_lenght == MAXTAM) throw excpt("ERRO: Maximo tamanho da lista atingido");

    this->_fila[this->_back] = item;
    this->_back = (this->_back + 1) % MAXTAM;
    this->_lenght++;
}

// Remove o primeiro item da fila
int FilaCircular::unqueue() {
    if (this->_lenght == 0) throw excpt("ERRO: A fila já está vazia");

    int element = this->_fila[this->_front];
    this->_front = (this->_front + 1) % MAXTAM;
    this->_lenght--;
    return element;
}

// Limpa a fila
void FilaCircular::emptyQueue() {
    this->_lenght = 0;
    this->_front = 0;
    this->_back = 0;
}
