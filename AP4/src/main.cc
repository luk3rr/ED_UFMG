#include <iostream>
#include <cstdlib>
#include <ctime>

#include "excpt.hh"
#include "pilha.hh"

int main() {
    Pilha stack;
    int randomNumber;

    // Inicializa o gerador de números pseudo-aleatórios com base no tempo atual
    std::srand(std::time(nullptr));

    try {
        std::cout << "Empilhar:" << std::endl;
        for (int i = 0; i < MAXTAM; i++) {
            // Gera um número pseudo-aleatório no intervalo [0,9] e o empilha
            randomNumber = std::rand() % 10;
            stack.toStack(randomNumber);
            std::cout << randomNumber << " ";
        }

        std::cout << "\nDesempilhar:" << std::endl;
        for (int i = 0; i < MAXTAM; i++) {
            std::cout << stack.unstack() << " ";
        }

    } catch (excpt &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
