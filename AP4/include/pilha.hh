#ifndef PILHA_H_
#define PILHA_H_

#include "fila.hh"
#include "excpt.hh"

class Pilha {
    private:
        FilaCircular _fila;
        int _top;

    public:
        Pilha();

        bool isEmpty();

        void toStack(int item);

        int unstack();

        void emptyStack();

        int getLenght();
};

#endif // PILHA_H_
