#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

/*
    Computo Paralelo 2026
    Itzel Berenice Martinez Palacios
    Tarea 1 - Problema 1
*/

int main() {

    // Declaracion de variables
    const int N = 10;
    int x = 1;
    int y[N];

    omp_set_num_threads(5); // Fijamos cuantos hilos vamos a lanzar
    // Paralelizamos un ciclo 'for' con una copia de x para cada hilo
    #pragma omp parallel for firstprivate(x) 
    for(int i = 0; i < N; i++){
        y[i] = x + i;
        x = i;
    }

    // Imprimimos el valor del arreglo y al finalizar el ciclo
    cout << "Valor de y al final: " << endl;
    for(int i = 0; i < N; i++){
        cout << y[i] << " ";
    }
    cout << endl;

    // Imprimimos el valor de la variable x al finalizar el ciclo
    cout << "Valor de x al final: " << endl;
    cout << x << endl;
    return 0;
}