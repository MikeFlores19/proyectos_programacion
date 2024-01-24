#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(){
    char nombr_archivo[20];
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", nombr_archivo);
    char texto[100000];
    int array[1000], i = 0,vB;
    FILE *f;
    f = fopen(nombr_archivo, "r");

    if (f == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO\n");
    }
    else {
        while (fgets(texto, sizeof(texto), f) != NULL) {
            int len=strlen(texto);
            if(len>0 && texto[len-1]=='\n'){
                texto[len-1]='\0';
            }
            char *token = strtok(texto, ",");
            while (token != NULL) {
                array[i] = atoi(token);
                i++;
                token = strtok(NULL, ",");
            }
        }
    }
    fclose(f);

    printf("Los numeros del texto son:\n");
    for(int j=0;j<i;j++){
        printf("%d ",array[j]);
    }

    printf("\n\nExisten %d datos en el archivo",cont(array,i));

    quickSort(array,0,i-1);

    printf("\n\nLos numeros ordenados por QUICK SORT son:\n");
    for(int k=0;k<i;k++){
        printf("%d ",array[k]);
    }

    printf("\n\nIngrese el numero a buscar: ");
    scanf("%d",&vB);

    int indice= binSearch(array,0,i-1,vB);
    if(indice!=-1){
        printf("El valor %d esta en la posicion %d \n",vB,indice);
    }
    else{
        printf("El valor %d no se encuentra en los datos",vB);
    }

    return 0;
}
