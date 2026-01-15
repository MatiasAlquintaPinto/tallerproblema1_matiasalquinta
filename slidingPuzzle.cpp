#include "slidingPuzzle.h"

slidingPuzzle::slidingPuzzle(int f, int c) {
    filas = f;
    columnas = c;
    cabecerasFilas = new Pieza*[filas];
    for (int i = 0; i < filas; i++) {
        cabeceraFilas[i] = nullptr;
        Pieza* actual = nullptr;
        for (int j = 0; j < columnas; j++) {
            Pieza* nuevaPieza = new Pieza(i,j,0);
            if (cabeceraFilas[i] == nullptr) {
                cabeceraFilas[i] = nuevaPieza;
                actual = nuevaPieza;
            } else {
                actual->derecha = nuevaPieza;
                nuevaPieza->izquierda = actual;
                actual = nuevaPieza;
            }

    }
    
}
}
bool slidingPuzzle::moverPieza(int pieza) {
    Pieza* piezaMover = nullptr;
    Pieza* piezaVacia = nullptr;

    for (int i = 0; i < filas; i++) {
        Pieza* actual = cabecerasFilas[i];
        while (actual != nullptr) {
            if (actual->valor == pieza) {
                piezaMover = actual;
            }
            if (actual->valor == 0) {
                piezaVacia = actual;
            }
            actual = actual->siguiente;
        }
    }

    if (piezaMover == nullptr || piezaVacia == nullptr) {
        return false;
    }

    bool adyacente = false;

    if (piezaMover->fila == piezaVacia->fila) {
        if (piezaMover->columna + 1 == piezaVacia->columna ||
            piezaMover->columna - 1 == piezaVacia->columna) {
            adyacente = true;
        }
    }

    if (piezaMover->columna == piezaVacia->columna) {
        if (piezaMover->fila + 1 == piezaVacia->fila ||
            piezaMover->fila - 1 == piezaVacia->fila) {
            adyacente = true;
        }
    }

    if (!adyacente) {
        return false;
    }

    int temp = piezaMover->valor;
    piezaMover->valor = piezaVacia->valor;
    piezaVacia->valor = temp;

    return true;
}
void slidingPuzzle::llenarPuzzle(std::vector<int> valores) {
    if (valores.size() != filas * columnas) return;
    int index = 0;
    for (int i = 0; i < filas; i++) {
        Pieza* actual = cabecerasFilas[i];
        for (int j = 0; j < columnas; j++) {
            actual->valor = valores[index++];
            actual = actual->siguiente; 
        }
    }
}

slidingPuzzle:: imprimirPuzzle() {
    for (int i = 0; i < filas; i++) {
        Pieza* actual = cabecerasFilas[i];
        for (int j = 0; j < columnas; j++) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
}

