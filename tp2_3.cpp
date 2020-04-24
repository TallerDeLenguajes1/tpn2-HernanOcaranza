#include <stdio.h>
#include <stdlib.h>
#include <ctime>
const int filas = 15;
const int  columnas = rand() % 11 + 5;


void CargarMatriz (int ** matriz);

void MostrarMatriz (int ** matriz);

void FreeMatriz (int ** matriz);

int CantidadParesPorFila (int ** matriz, int fila);

void GenerarVectorPares (int * vector, int ** matriz);

void MostrarVector (int * vector);

int main () {
    
    srand(time(0));
    int ** pMatriz = (int **) malloc(sizeof(int*) * filas);
    int * pVecPares = (int *) malloc(sizeof(int) * filas);
    CargarMatriz(pMatriz);
    MostrarMatriz(pMatriz);
    GenerarVectorPares(pVecPares, pMatriz);
    MostrarVector(pVecPares);
    FreeMatriz(pMatriz);
    free(pVecPares);
    getchar();
    return 0;
}

void CargarMatriz (int ** matriz) {
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = (int *) malloc(sizeof(int) * columnas);
        for (int j = 0; j < columnas; j++)
        {
            //matriz[i][j] = 0;
            matriz[i][j] = rand() % 900 + 100;
        }
    }
}

void MostrarMatriz (int ** matriz) {
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d   ",matriz[i][j]);
        }
        printf("\n");
    }
}

void FreeMatriz (int ** matriz) {
    for (int i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int CantidadParesPorFila (int ** matriz, int fila) {
    int cont = 0;
    for (int j = 0; j < columnas; j++)
    {
        if (matriz[fila][j] % 2 == 0) cont++;
    }
    return cont;
}

void GenerarVectorPares (int * vector, int ** matriz) {
    for (int i = 0; i < filas; i++)
    {
        vector[i] = CantidadParesPorFila(matriz, i);
    }
    
}

void MostrarVector (int * vector) {
    printf("\nEl vector de numeros pares es: ");
    for (int i = 0; i < filas; i++)
    {
        printf("%d  ", vector[i]);
    }
    printf("\n");   
}