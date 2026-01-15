#ifndef SLIDINGPUZZLE_H
#define SLIDINGPUZZLE_H

#include "nodo.h"

class SlidingPuzzle {
public:
    int filas;
    int columnas;
    Nodo* cabeceraFilas;

    SlidingPuzzle(int f, int c);
    ~SlidingPuzzle();
    bool moverPieza(int pieza);
    void llenarPuzzle();
    void imprimirPuzzle();

};
#endif 