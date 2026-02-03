#include <iostream>
#include <vector>
#include <time.h>
#include <omp.h>
#define N 100000000 // 100 millones
using namespace std;

/*
    Computo Paralelo 2026
    Itzel Berenice Martinez Palacios
    Tarea 1 - Problema 2
*/

int main(){

    // Variables iniciales
    long long suma_sec = 0;
    long long suma_par = 0;

    vector <int> vec(N,0);
    for(int i = 0; i < N; i++)
        vec[i] = rand() % 10 + 1;
    // ------- Forma Secuencial -------
    double sec_t_i = clock();
    for(int i = 0; i < N; i++)
        suma_sec += vec[i];
    double sec_t_f = clock();
    double time_sec = (sec_t_f - sec_t_i) / CLOCKS_PER_SEC;

    // ------- Forma Paralela -------
    double par_t_i = clock();
    #pragma omp parallel for reduction(+:suma_par) // Paralelización
    for(int i = 0; i < N; i++)
        suma_par += vec[i];
    double par_t_f = clock();
    double time_par = (par_t_f - par_t_i) / CLOCKS_PER_SEC;

    // ------- Imprimir Resultados -------

    cout << "Suma por la Forma Secuencial: " << suma_sec << endl;
    cout << "Suma por la Forma Paralela: " << suma_par << endl;

    cout << "Tiempo Secuencial: " << time_sec << endl;
    cout << "Tiempo Paralelo: " << time_par << endl;
    return 0;
}