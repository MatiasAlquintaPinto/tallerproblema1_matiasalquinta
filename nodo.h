#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    int fila;
    int columna;
    int valor;
    Pieza* sig;
    Pieza(int f, int c, int v) : fila(f), columna(c), valor(v), sig(nullptr) {}   
};
#endif 