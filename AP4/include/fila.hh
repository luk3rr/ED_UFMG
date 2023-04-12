#ifndef FILA_H_
#define FILA_H_

#include "excpt.hh"

#define MAXTAM 10

class FilaCircular {
    private:
        int _lenght, _front, _back;
        int _fila[MAXTAM];

    public:
        FilaCircular();

        int getLength();

        void toQueue(int item);

        int unqueue();

        bool isEmpty();

        void emptyQueue();
};

#endif // FILA_H_
