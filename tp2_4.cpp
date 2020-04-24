#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>

// Declaracion de estructuras

typedef struct 
{
    int velocidad;
    int anio;
    int cantidad;
    char * tipoCpu;
}compu;

// Declaracion de Funciones

compu DevuelvePc (compu pc);

void CargarArregloDeCompus (compu * array, int cant);

void MostrarCaracteristicas (compu pc);

void ListarPc (compu * array, int cant);

void PcMasVieja (compu * array, int cant);

void PcMasRapida (compu * array, int cant);

void FreeCompleto (compu * array, int cant);

// Funcion principal

int main() {
    srand(time(0));
    int cantidad;
    printf("Ingrese la cantidad de pc: ");
    scanf(" %d", &cantidad);

    compu * pArrayDeCompus = (compu *) malloc(sizeof(compu) * cantidad);

    CargarArregloDeCompus(pArrayDeCompus, cantidad);

    ListarPc(pArrayDeCompus, cantidad);

    PcMasVieja(pArrayDeCompus, cantidad);

    PcMasRapida(pArrayDeCompus, cantidad);

    FreeCompleto(pArrayDeCompus, cantidad);
    
    getchar();
    getchar();
    return 0;
}


// Desarrollo de funciones

compu DevuelvePc (compu pc) {
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    pc.velocidad = rand() % 3 + 1;
    pc.anio = rand() % 18 + 2000;
    pc.cantidad = rand() % 4 + 1;
    pc.tipoCpu = (char *) malloc(sizeof(char) * 10);
    strcpy(pc.tipoCpu, tipos[rand() % 6]);

    return pc;
}

void CargarArregloDeCompus (compu * array, int cant) {
    for (int i = 0; i < cant; i++)
    {
        array[i] = DevuelvePc(array[i]);
    }
}

void MostrarCaracteristicas (compu pc) {
    printf("\nPC: %s",pc.tipoCpu);
    printf("\nAnio: %d", pc.anio);
    printf("\nVelocidad: %d GHz", pc.velocidad);
    printf("\nNucleos: %d\n", pc.cantidad); 
}

void ListarPc (compu * array,int cant) {
    for (int i = 0; i < cant; i++)
    {
        MostrarCaracteristicas(array[i]);
    }
    
}

void PcMasVieja (compu * array, int cant) {
    int pcVieja = 2018, ind;
    printf("\nLa pc mas vieja es:");
    for (int i = 0; i < cant; i++)
    {
        if (array[i].anio < pcVieja) {
            pcVieja = array[i].anio;
            ind = i;
        }
    }
    MostrarCaracteristicas(array[ind]);
}

void PcMasRapida (compu * array, int cant) {
    int pcRapida = 0, ind;
    printf("\nLa pc de mayor velocidad es:");
    for (int i = 0; i < cant; i++)
    {
        if (array[i].velocidad > pcRapida) {
            pcRapida = array[i].velocidad;
            ind = i;
        }
    }
    MostrarCaracteristicas(array[ind]);
}

void FreeCompleto (compu * array, int cant) {
    for (int i = 0; i < cont; i++)
    {
        free(array[i].tipoCpu);
    }
    free(array);
}