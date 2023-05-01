#ifndef QUEUE_H_
#define QUEUE_H_

#include "queueExcpt.hh"

#define MAXTAM 1000

template <typename typeT>
class CircularQueue {
    private:
        int _lenght, _front, _back;
        typeT _fila[MAXTAM];

    public:
        CircularQueue();

        int getLength();

        void push(typeT item);

        typeT pop();

        bool isEmpty();

        void clean();
};

template <typename typeT>
CircularQueue<typeT>::CircularQueue() {
    this->_lenght = 0;
    this->_front = 0;
    this->_back = 0;
}

template <typename typeT>
int CircularQueue<typeT>::getLength() {
    return this->_lenght;
}

template <typename typeT>
bool CircularQueue<typeT>::isEmpty() {
    if (this->_lenght == 0) return true;
    else return false;
}

// Adiciona um item ao fim da fila
template <typename typeT>
void CircularQueue<typeT>::push(typeT item) {
    if (this->_lenght == MAXTAM) throw queexcpt::QueueOverflow();

    this->_fila[this->_back] = item;
    this->_back = (this->_back + 1) % MAXTAM;
    this->_lenght++;
}

// Remove o primeiro item da fila
template <typename typeT>
typeT CircularQueue<typeT>::pop() {
    if (this->_lenght == 0) throw queexcpt::QueueIsEmpty();

    typeT element = this->_fila[this->_front];
    this->_front = (this->_front + 1) % MAXTAM;
    this->_lenght--;
    return element;
}

// Limpa a fila
template <typename typeT>
void CircularQueue<typeT>::clean() {
    this->_lenght = 0;
    this->_front = 0;
    this->_back = 0;
}

#endif // QUEUE_H_
