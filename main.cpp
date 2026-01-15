#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "slidingPuzzle.h"

int main() {
    int n = 3;
    slidingPuzzle puzzle(n, n);

    std::vector<int> valores;
    for (int i = 1; i <= n*n - 1; i++) {
        valores.push_back(i);
    }
    valores.push_back(0);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(valores.begin(), valores.end(), std::default_random_engine(seed));

    puzzle.llenarPuzzle(valores);
    puzzle.imprimirPuzzle();

    int piezaAMover;
    std::cout << "Ingresa el ID de la pieza a mover: ";
    std::cin >> piezaAMover;

    if (puzzle.moverPieza(piezaAMover)) {
        std::cout << "Movimiento realizado!\n";
    } else {
        std::cout << "Movimiento invalido!\n";
    }

    puzzle.imprimirPuzzle();

    return 0;
}
