#include <iostream>
#include <vector>
#include <time.h>
#include <omp.h>
#define N 200
using namespace std;

/*
    Computo Paralelo 2026
    Itzel Berenice Martinez Palacios
    Tarea 1 - Problema 3
*/

void fill_mat(int mat[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++){
            mat[i][j] = rand() % 10 + 1;
        }
    }
}

int main (){
    int A[N][N];
    int B[N][N];

    long long AxB_sec[N][N];
    long long AxB_par[N][N];

    fill_mat(A);
    fill_mat(B);

    // ------- Forma Secuencial -------
    double sec_t_i = clock();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            AxB_sec[i][j] = 0;
            for(int k = 0; k < N; k++){
                AxB_sec[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double sec_t_f = clock();
    double time_sec = (sec_t_f - sec_t_i) / CLOCKS_PER_SEC;

    // ------- Forma Paralela -------
    double par_t_i = clock();
    #pragma omp parallel for shared(A,B,AxB_par)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            AxB_par[i][j] = 0;
            for(int k = 0; k < N; k++){
                AxB_par[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double par_t_f = clock();
    double time_par = (par_t_f - par_t_i) / CLOCKS_PER_SEC;

    // ------- Imprimir Resultados -------
    /*
    cout << "Multiplicacion por la Forma Secuencial: "  << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << AxB_sec[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Multiplicacion por la Forma Paralela: " << endl;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << AxB_par[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    */
    cout << "Tiempo Secuencial: " << time_sec << endl;
    cout << "Tiempo Paralelo: " << time_par << endl;

    return 0;
}