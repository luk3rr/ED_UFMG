#include <iostream>
#include <fstream>
#include <getopt.h>

#include "binaryTree.hh"
#include "queue.hh"
#include "utils.hh"

int main(int argc, char *argv[]) {
    int opt, nodes, seed;
    nodes = seed = -1;

    while ((opt = getopt(argc, argv, "n:s:h")) != -1) {
        switch (opt) {
            case 'n':
                nodes = std::stoi(optarg);
                break;

            case 's':
                seed = std::stoi(optarg);
                break;

            case 'h':
                utils::usage();
                break;
        }
    }
    if (nodes <= 0) nodes = 10;
    if (seed == -1) seed = 333;

    BinaryTree<int> tree;
    CircularQueue<int> preorder, inorder, postorder, levelOrder;

    int* array = new int[nodes];

    for (int i = 0; i < nodes; i++) {
        array[i] = i;
    }

    // Embaralhar os numeros no array
    srand(seed);
    int pos, aux;
    for (int i = nodes - 1; i > 0; i--) {
        pos = rand() % (i + 1);

        aux = array[i];
        array[i] = array[pos];
        array[pos] = aux;
    }

    std::cout << "\nARRAY DE CONSTRUCAO:" << std::endl;
    for (int i = 0; i < nodes; i++) {
        tree.insert(array[i]);
        std::cout << array[i] << " ";
    }

    tree.inorderTreeWalk(inorder);
    tree.preorderTreeWalk(preorder);
    tree.postorderTreeWalk(postorder);
    tree.levelOrderTreeWalk(levelOrder);


    std::cout << "\nINORDER:" << std::endl;
    while (!inorder.isEmpty()) {
        std::cout << inorder.pop() << " ";
    }

    std::cout << "\nPREORDER:" << std::endl;
    while (!preorder.isEmpty()) {
        std::cout << preorder.pop() << " ";
    }

    std::cout << "\nPOSORDER:" << std::endl;
    while (!postorder.isEmpty()) {
        std::cout << postorder.pop() << " ";
    }

    std::cout << "\nLEVEL ORDER:" << std::endl;
    tree.levelOrderTreeWalk();

    try {
        std::ofstream output("arvore.txt");
        std::cout << "\n\nImprimindo árvore..." << std::endl;

        tree.dumpTree(output);

        output.close();

        std::cout << "Arvore impressa no arquivo 'arvore.txt'" << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << "ERRO: " << e.what() << std::endl;
    }

    std::cout << "\nFR = Funcao Recursiva\n"
              << "FLO = Funcao que utiliza somente level order\n"
              << "FIPP = Funcao que utiliza inorder, postorder e preorder"
              << std::endl;

    int i, j;
    srand(time(nullptr));
    for (int call = 0; call < nodes; call++) {
        i = array[rand() % nodes];
        j = array[rand() % nodes];

        std::cout << std::endl;
        std::cout << "  FR: ";
        utils::ancestorMsg(i, j, tree.isAncestorRecursive(i,j));
        std::cout << " FLO: ";
        utils::ancestorMsg(i, j, tree.isAncestorLevelOrder(i, j));
        std::cout << "FIPP: ";
        utils::ancestorMsg(i, j, tree.isAncestor(i, j));
    }

    tree.deleteTree();
    delete[] array;

    return 0;
}
