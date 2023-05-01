#include "queueExcpt.hh"

const char* queexcpt::QueueOverflow::what() const throw() {
    return "ERRO: Limite da fila excedido";
}

const char* queexcpt::QueueIsEmpty::what() const throw() {
    return "ERRO: A fila ja esta vazia";
}
