#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ALGORITMOS.h"



int main(){
    //DECLARACION DE VARIABLES Y RAND
    int *arr=(int*)malloc(TAM*sizeof(int));
    long int nume;
    int opc;
    nume=TAM;
    srand(time(NULL));
    //GENERACION DE ARREGLO ALEATORIO
    for(int i=0;i<TAM;i++){
        arr[i]=rand()%10000;
    }
    //IMPRESION DEL ARREGLO DESORDENADO
    printf("ARREGLO DESORDENADO:\n");
    for(int i=0;i<TAM;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    //Menu
    printf("Selecciona el método que deseas utilizar: ");
    printf("\n\t[1]Burbuja.\n\t[2]Seleccion.\n\t[3]Insercion.\n\t[4]Timsort.\n\t[5]Counting.\n\t[6]Bucket.\n\t[7]Quick.\n\t[8]Gnome.\n\n\tOpcion: ");
    fflush(stdin);
    scanf("%d",&opc);
    switch(opc){
        case 1:
            printf("\nBUBBLE SORT:\n");
            burbuja(arr);
            printf("\n\n");
            break;
        case 2:
            printf("\nOrdenamiento por Selección: ");
            seleccion(arr,nume);
            printf("\nEl arreglo ordenado es: \n");
            for(int i=0;i<TAM;i++){
                printf("%d ",arr[i]);
            }
            break;
        case 3:
            printf("\nOrdenamiento por Inserción: ");
            insercion(arr,1,nume);
            printf("\nEl arreglo ordenado es: \n");
            for(int i=0;i<TAM;i++){
                printf("%d ",arr[i]);
            }
            break;
        case 4:
            printf("\nOrdenamiento por Timsort: ");
            timsort(arr,nume);
            printf("\nEl arreglo ordenado es: \n");
            for(int i=0;i<TAM;i++){
                printf("%d ",arr[i]);
            }
            break;
        case 5:
            printf("COOUNTING SORT:\n");
            counting(arr);
            printf("\n\n");
            break;
        case 6:
            printf("BUCKET SORT:\n");
            bucket(arr);
            printf("\n\n");
            break;
        case 7:
            printf("QUICK SORT:\n");
            quick(arr);
            printf("\n\n");
            break;
        case 8:
            printf("GNOME SORT\n");
            gnome(arr);
            printf("\n\n");
            break;
        default:
            printf("\nEsa opcion no existe.");
            break;
    }
    free(arr);
    return 0;
}



