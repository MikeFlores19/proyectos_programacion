#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include "ALGORITMOS.h"
const int RUN=32;
void burbuja(int arr[]){
    int aux;
    double tiempodeEjecucion;
    clock_t tiempoempiezo=clock();
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM-i-1;j++){
            if(arr[j]>arr[j+1]){
                aux=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=aux;
            }
        }
    }
    clock_t tiempofinalizacion=clock();
    tiempodeEjecucion=(double)(tiempofinalizacion-tiempoempiezo)/CLOCKS_PER_SEC;

     for(int i=0;i<TAM;i++){
        printf("%d ",arr[i]);
     }
     printf("\nTiempo de ejecucion %.4lf segundos",tiempodeEjecucion);
}

//DECLARACION COUNTING
void counting(int arr[]){
    //Busca el numero mas grande
    int max=arr[0];
    for(int i=1;i<TAM;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    //METODO COUNTING
    int *out=(int*)malloc(TAM*sizeof(int));
    int count[max+1];
    int num,nindex;
    double tiempodeEjecucion;
    //ARREGLO QUE INICIALIZA AL ARREGLO DE CUENTAS EN 0
    clock_t tiempoempiezo=clock();
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    //CUENTAS LOS NUMEROS REPETIDOS
    for(int i=0;i<TAM;i++){
        num=arr[i];
        count[num]++;
    }

    //SUMA ACUMALATIVA
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    //COPIAR EL NUMERO QUE SE QUIERE ORDENAR A EL ARREGLO AUXILIAR OCN EL NUEVO INDEX
    for(int i=0;i<TAM;i++){
        num=arr[i];
        nindex=count[num]-1;
        out[nindex]=num;
        count[num]=count[num]-1;
    }
    clock_t tiempofinalizacion=clock();
    tiempodeEjecucion=(double)(tiempofinalizacion-tiempoempiezo)/CLOCKS_PER_SEC;
    //SE COPIA EL AUXILIAR AL ARREGLO ORIGINAL PARA ORDENARLO
    for(int i=0;i<TAM;i++){
        arr[i]=out[i];
    }
    //SE IMPRIME EL ARREGLO ORDENADO

    for(int i=0;i<TAM;i++){
        printf("%d ",arr[i]);
    }

    printf("\nTiempo de ejecucion %.4lf segundos",tiempodeEjecucion);

}

//DECLARACION BUCKET SORT
void bucket(int arr[]){
    //Busca el numero mas grande
    int max=arr[0];
    double tiempodeEjecucion;
    for(int i=1;i<TAM;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    //METODO BUCKET, CREAR LOS BUCKETS
    int bucket[max+1];
    //INICIALIZAR LOS BUCKETS A 0
    clock_t tiempoempiezo=clock();
    for(int i=0;i<=max;i++){
        bucket[i]=0;
    }
    //PONER LOS ELEMENTOS EN SU RESPECTIVO BUCKET
    for(int i=0;i<TAM;i++){
        bucket[arr[i]]++;
    }
    //FUSIONAR LOS BUCKETS
    int j=0;
    for(int i=0;i<=max;i++){
        while (bucket[i]>0){
            arr[j++]=i;//COLOCA EL VALOR DE i en el correspondiente arreglo de slaida tantas vece que se hayan repetido en el bucket
            bucket[i]--;//SE RESTA PARA SABER QUE ESE VALOR i ya fue colocado en su lugar
        }
    }
    clock_t tiempofinalizacion=clock();
    tiempodeEjecucion=(double)(tiempofinalizacion-tiempoempiezo)/CLOCKS_PER_SEC;
    //IMPRESION ARREGLO ARREGLADO
    for(int i=0;i<TAM;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTiempo de ejecucion %.4lf segundos",tiempodeEjecucion);
}
// Función auxiliar para intercambiar dos elementos en el arreglo
void intercambiar(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para encontrar el pivote y dividir el arreglo
int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto]; // Tomamos el último elemento como pivote
    int i = (bajo - 1); // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            intercambiar(arr, i, j);
        }
    }
    intercambiar(arr, i + 1, alto);
    return (i + 1);
}

// Función recursiva para implementar Quick Sort
void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        // Encuentra el índice del pivote, arr[p] está en su posición correcta
        int indicePivote = particion(arr, bajo, alto);

        // Ordena los elementos antes y después del pivote
        quickSort(arr, bajo, indicePivote - 1);
        quickSort(arr, indicePivote + 1, alto);
    }
}

// Función pública para llamar a Quick Sort con los mismos parámetros que las demás funciones
void quick(int arr[]) {
    double tiempoDeEjecucion;
    clock_t tiempoInicio = clock();

    quickSort(arr, 0, TAM - 1);

    clock_t tiempoFinalizacion = clock();
    tiempoDeEjecucion = (double)(tiempoFinalizacion - tiempoInicio) / CLOCKS_PER_SEC;

    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTiempo de ejecucion %.4lf segundos", tiempoDeEjecucion);
}

// Función para ordenar el arreglo utilizando Gnome Sort
void gnome(int arr[]) {
    double tiempoDeEjecucion;
    clock_t tiempoInicio = clock();
    int indice = 0;

    while (indice < TAM) {
        if (indice == 0) {
            indice++; // Si estamos al principio del arreglo, avanzamos al siguiente elemento
        }
        if (arr[indice] >= arr[indice - 1]) {
            indice++; // Si el elemento actual es mayor o igual que el anterior, avanzamos al siguiente elemento
        } else {
            // Si el elemento actual es menor que el anterior, los intercambiamos y retrocedemos
            int temp = arr[indice];
            arr[indice] = arr[indice - 1];
            arr[indice - 1] = temp;
            indice--;
        }
    }

    clock_t tiempoFinalizacion = clock();
    tiempoDeEjecucion = (double)(tiempoFinalizacion - tiempoInicio) / CLOCKS_PER_SEC;

    // Impresión del arreglo ordenado
    printf("ORDENAMIENTO GNOMO:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTiempo de ejecucion %.4lf segundos", tiempoDeEjecucion);
}

//Funcion de ordenamiento por selección
void seleccion(int arr[],int num){
    int aux,posi;
    double tiempo_ejecucion=0;
    clock_t begin= clock();
    for(int i=0;i<num;i++){
        posi=0;
        //Busca el numero más grande y guarda su ubicacion
        for(int j=0;j<num-i;j++){
            if(arr[posi]<arr[j]){
                posi=j;
            }
        }
        //Intercambia posición el numero más grande con el último número
        aux=arr[num-1-i];
        arr[num-1-i]=arr[posi];
        arr[posi]=aux;
    }
    clock_t end= clock();
    tiempo_ejecucion += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nEL tiempo de ejecucion es de %.10000f\n\n",tiempo_ejecucion);
}

//Función de ordenamiento por Inserción
void insercion(int arr[],int inicio, int fin){
    int j,aux;
    double tiempo_ejecucion=0;
    clock_t begin=clock();
    for(int i=inicio;i<=fin;i++){
        //Establece un numero fijo para la comparación
        aux=arr[i];
        j=i-1;
        while((j>=0) && (arr[j]>aux)){
            //Mientras cumpla la condición, todos los números se irán recorriendo a la derecha
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=aux;
    }
    clock_t end=clock();
    tiempo_ejecucion += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nEL tiempo de ejecucion es de %.10000f\n\n",tiempo_ejecucion);
}

//Funcion con ordenamiento merge, que complementa a timsort
void merge(int arr[],int ini,int med, int fn){
    int i,j,k;
    int n1=med-ini+1;
    int n2=fn-med;
    int izqarreglo[n1],derarreglo[n2];
    for(int i=0;i<n1;i++){
        izqarreglo[i]=arr[ini+i];
    }
    for(int j=0;j<n2;j++){
        derarreglo[j]=arr[med+1+j];
    }
    i=0;
    j=0;
    k=ini;
    while(i<n1 && j<n2){
        if(izqarreglo[i]<=derarreglo[j]){
            arr[k]=izqarreglo[i];
            i++;
        }else{
            arr[k]=derarreglo[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=izqarreglo[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=derarreglo[j];
        j++;
        k++;
    }
}

//Función de ordenamiento por Timsort
void timsort(int arr[],int num){
    double tiempo_ejecucion=0;
    clock_t begin=clock();
    for(int i=0;i<num;i+=RUN){
        insercion(arr,i,min((i+RUN-1),(num-1)));
    }
    for(int tamanio=RUN;tamanio<num;tamanio*=2){
        for(int inicio=0;inicio<num;inicio+=2*tamanio){
            int medio=inicio+tamanio-1;
            int fin=min((inicio+2*tamanio-1),(num-1));
            if(medio<fin)
                merge(arr,inicio,medio,fin);
        }
    }
    clock_t end=clock();
    tiempo_ejecucion += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nEL tiempo de ejecucion es de %.10000f\n\n",tiempo_ejecucion);
}
//Compara cuál es el menor en un par de numeros, complementa a timsort
int min(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
