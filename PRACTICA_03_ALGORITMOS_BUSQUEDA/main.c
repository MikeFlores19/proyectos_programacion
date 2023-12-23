#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "ALGORITMOS_BUSQUEDA.h"
LARGE_INTEGER start_time; // Tiempo de inicio
LARGE_INTEGER end_time;   // Tiempo de finalización
double elapsed_time;// Tiempo transcurrido en segundos
double elapsed_time2;
double elapsed_time3;
double elapsed_time4;

int main(){
    const int n=10;
    int A[n];
    int vB=0,vB2=50,vB3=99,vB4,opc,indice,indice2,indice3,indice4; //VALOR A BUSCAR
    srand(time(NULL));
    LARGE_INTEGER frequency; // Variable para almacenar la frecuencia

    //VALORES ALEATORIOS DE 0-99
    printf("Lista de valores: ");
    printf("\n\t[");
    for(int i=0;i<n;i++){
        A[i]=rand()%100;
        printf("%d, ",A[i]);
    }

    //NUMERO ALEATORIO A GENERAR
    vB4=rand()%100;
    printf("\b\b]");

    //IMPRESION DE LOS VALORES A BUSCAR
    printf("\n\nNumeros a buscar: ");
    printf("\t\n1. %d",vB);
    printf("\t\n2. %d",vB2);
    printf("\t\n3. %d",vB3);
    printf("\t\n4. %d",vB4);

    //MENU
    printf("\n\n\t-----------------------");
    printf("\n\t[1]Busqueda lineal.");
    printf("\n\t[2]Busqueda binaria.");
    printf("\n\t[3]Busqueda indexada.");
    printf("\n\t[4]Busqueda interpolada.");
    printf("\n\t[5]Busqueda propuesta.");
    printf("\n\t-----------------------\n");


    //BUSQUEDA LINEAL
    printf("\n\t[1]Busqueda lineal.");

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice=lSearch(A,n,vB);
    QueryPerformanceCounter(&end_time);
    elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time);


    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice2=lSearch(A,n,vB2);
    QueryPerformanceCounter(&end_time);
    elapsed_time2 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time2);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice3=lSearch(A,n,vB3);
    QueryPerformanceCounter(&end_time);
    elapsed_time3 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time3);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice4=lSearch(A,n,vB4);
    QueryPerformanceCounter(&end_time);
    elapsed_time4 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %.8lf segundos\n", elapsed_time4);

    if(indice!=-1){
        printf("\nEl valor 1 esta en: %d",indice+1);
    }
    else{
        printf("\nEl valor 1 no se encuentra en la lista.\n");
    }

    if(indice2!=-1){
        printf("\nEl valor 2 esta en: %d",indice2+1);
    }
    else{
        printf("\nEl valor 2 no se encuentra en la lista.\n");
    }


    if(indice3!=-1){
        printf("\nEl valor 3 esta en: %d",indice3+1);
    }
    else{
        printf("\nEl valor 3 no se encuentra en la lista.\n");
    }


    if(indice4!=-1){
        printf("\nEl valor 4 esta en: %d",indice4+1);
    }
    else{
        printf("\nEl valor 4 no se encuentra en la lista.\n");
    }



    burbujaS(A,n); //SE ORDENA EL VECTOR DEBIDO A QUE LOS OTROS ALGORITMOS DE BUSQUEDA LO REQUIERE
/*
    printf("\n");
    printf("Lista de valores ordenada: ");
    printf("\n\t[");
    for(int i=0;i<n;i++){
                printf("%d, ",A[i]);
    }
    printf("\b\b]");
*/


    //BUSQUEDA BINARIA
    printf("\n\t[2]Busqueda binaria.");
    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice=binSearch(A,0,n-1,vB);
    QueryPerformanceCounter(&end_time);
    elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time);


    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice2=binSearch(A,0,n-1,vB2);
    QueryPerformanceCounter(&end_time);
    elapsed_time2 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time2);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice3=binSearch(A,0,n-1,vB3);
    QueryPerformanceCounter(&end_time);
    elapsed_time3 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time3);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice4=binSearch(A,0,n-1,vB4);
    QueryPerformanceCounter(&end_time);
    elapsed_time4 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %.8lf segundos\n", elapsed_time4);

    if(indice!=-1){
        printf("\nEl valor 1 esta en: %d",indice+1);
    }
    else{
        printf("\nEl valor 1 no se encuentra en la lista.\n");
    }

    if(indice2!=-1){
        printf("\nEl valor 2 esta en: %d",indice2+1);
    }
    else{
        printf("\nEl valor 2 no se encuentra en la lista.\n");
    }


    if(indice3!=-1){
        printf("\nEl valor 3 esta en: %d",indice3+1);
    }
    else{
        printf("\nEl valor 3 no se encuentra en la lista.\n");
    }


    if(indice4!=-1){
        printf("\nEl valor 4 esta en: %d",indice4+1);
    }
    else{
        printf("\nEl valor 4 no se encuentra en la lista.\n");
    }


    //BUSQUEDA INDEXADA
    printf("\n\t[3]Busqueda indexada.");
    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice=indSearch(A,n,vB);
    QueryPerformanceCounter(&end_time);
    elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time);


    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice2=indSearch(A,n,vB2);
    QueryPerformanceCounter(&end_time);
    elapsed_time2 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time2);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice3=indSearch(A,n,vB3);
    QueryPerformanceCounter(&end_time);
    elapsed_time3 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time3);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice4=indSearch(A,n,vB4);
    QueryPerformanceCounter(&end_time);
    elapsed_time4 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %.8lf segundos\n", elapsed_time4);

    if(indice!=-1){
        printf("\nEl valor 1 esta en: %d",indice+1);
    }
    else{
        printf("\nEl valor 1 no se encuentra en la lista.\n");
    }

    if(indice2!=-1){
        printf("\nEl valor 2 esta en: %d",indice2+1);
    }
    else{
        printf("\nEl valor 2 no se encuentra en la lista.\n");
    }


    if(indice3!=-1){
        printf("\nEl valor 3 esta en: %d",indice3+1);
    }
    else{
        printf("\nEl valor 3 no se encuentra en la lista.\n");
    }


    if(indice4!=-1){
        printf("\nEl valor 4 esta en: %d",indice4+1);
    }
    else{
        printf("\nEl valor 4 no se encuentra en la lista.\n");
    }


    //BUSQUEDA INTERPOLADA
    printf("\n\t[4]Busqueda interpolada.");
    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice=intSearch(A,0,n-1,vB);
    QueryPerformanceCounter(&end_time);
    elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time);


    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice2=intSearch(A,0,n-1,vB2);
    QueryPerformanceCounter(&end_time);
    elapsed_time2 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time2);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice3=intSearch(A,0,n-1,vB3);
    QueryPerformanceCounter(&end_time);
    elapsed_time3 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time3);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice4=intSearch(A,0,n-1,vB4);
    QueryPerformanceCounter(&end_time);
    elapsed_time4 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %.8lf segundos\n", elapsed_time4);

    if(indice!=-1){
        printf("\nEl valor 1 esta en: %d",indice+1);
    }
    else{
        printf("\nEl valor 1 no se encuentra en la lista.\n");
    }

    if(indice2!=-1){
        printf("\nEl valor 2 esta en: %d",indice2+1);
    }
    else{
        printf("\nEl valor 2 no se encuentra en la lista.\n");
    }


    if(indice3!=-1){
        printf("\nEl valor 3 esta en: %d",indice3+1);
    }
    else{
        printf("\nEl valor 3 no se encuentra en la lista.\n");
    }


    if(indice4!=-1){
        printf("\nEl valor 4 esta en: %d",indice4+1);
    }
    else{
        printf("\nEl valor 4 no se encuentra en la lista.\n");
    }


    //BUSQUEDA LINEAL ORDENADA
    printf("\n\t[5]Busqueda propuesta: Busqueda lineal ordenada.");
    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice=lmSearch(A,n,vB);
    QueryPerformanceCounter(&end_time);
    elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time);


    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice2=lmSearch(A,n,vB2);
    QueryPerformanceCounter(&end_time);
    elapsed_time2 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time2);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice3=lmSearch(A,n,vB3);
    QueryPerformanceCounter(&end_time);
    elapsed_time3 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %lf segundos\n", elapsed_time3);

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start_time); // Obtiene el tiempo de inicio
    indice4=lmSearch(A,n,vB4);
    QueryPerformanceCounter(&end_time);
    elapsed_time4 = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("\nTiempo transcurrido: %.8lf segundos\n", elapsed_time4);



    if(indice!=-1){
        printf("\nEl valor 1 esta en: %d",indice+1);
    }
    else{
        printf("\nEl valor 1 no se encuentra en la lista.\n");
    }

    if(indice2!=-1){
        printf("\nEl valor 2 esta en: %d",indice2+1);
    }
    else{
        printf("\nEl valor 2 no se encuentra en la lista.\n");
    }


    if(indice3!=-1){
        printf("\nEl valor 3 esta en: %d",indice3+1);
    }
    else{
        printf("\nEl valor 3 no se encuentra en la lista.\n");
    }


    if(indice4!=-1){
        printf("\nEl valor 4 esta en: %d",indice4+1);
    }
    else{
        printf("\nEl valor 4 no se encuentra en la lista.\n");
    }


    return 0;
}
