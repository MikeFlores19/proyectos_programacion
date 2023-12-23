#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ALGORITMOS_BUSQUEDA.h"

//BUSQUEDA LINEAL
int lSearch(int A[],int n,int vB){
    int contador=0;
    for(int i=0;i<n;i++){
        if(A[i]==vB){
            printf("\nVeces evaluado: %d\n",contador+1);
            return i;
        }
        contador++;
    }
    printf("\nVeces evaluado: %d\n",contador);
    return -1;
}

//ORDENAMIENTO BURBUJA
void burbujaS(int A[],int n){
    int swap;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
            if(A[j]>A[j+1])
            {
                swap=A[j];
                A[j]=A[j+1];
                A[j+1]=swap;
            }
}

//BUSQUEDA BINARIA
int binSearch(int A[],int inicio,int fin,int vB){
    int contador=0;
    while(inicio<=fin){
        int mid=inicio+(fin-inicio)/2;//int mid=(inicio+fin)/2;
        if(A[mid]==vB){ //si el valor es mid
            contador++;
            printf("\nVeces evaluado: %d\n",contador);
            return mid;
        }
        else if(vB>A[mid]) //buscar del lado derecho
            inicio=mid+1;
        else
            fin=mid-1;
        contador++;
    }
    printf("\nVeces evaluado: %d\n",contador);
    return -1;
}

//BUSQUEDA INDEXADA
int indSearch(int A[],int n, int vB){
    int indices[n],elementos[n],i,set=0,contador=0;
    int inicio, fin,ind=0;   // inicio y fin de rango de busqueda, ind es indices deindices y elementos

    //crear los limites
    for(i=0;i<n;i+=3){
        indices[ind]=i;
        elementos[ind]=A[i];
        ind++;
    }
    //verificar si el valor buscado
    //esta dentro del arreglo
    if(vB<A[0] || vB>A[n-1]){
        printf("\nVeces evaluado: %d\n",contador);
        return -1;
    }else{
        for(i=1;i<=ind;i++){
            if(vB<=elementos[i]){
                //generamos rango de busqueda
                inicio=indices[i-1]; //indice anterior
                fin=indices[i]; //inide actual
                set=1;
                break;
            }
        }
    }
    if(set==0){
        inicio=indices[i];
        fin=n-1;
    }


    for(i=inicio;i<fin;i++){
        if(vB==A[i]){
            contador++;
            printf("\nVeces evaluado: %d\n",contador);
            return i;
        }
        contador++;
    }
    printf("\nVeces evaluado: %d\n",contador);

    return -1;
}
//BUSQUEDA INTERPOLADA
int intSearch(int A[],int inicio,int fin,int vB){
    int pos,contador=0; //posición aproximada del valor
    while(inicio<=fin && vB>=A[inicio] && vB<=A[fin]){
        pos=inicio+((vB-A[inicio])*(fin-inicio)/(A[fin]-A[inicio]));
        if(vB==A[pos]){
            contador++;
            printf("\nVeces evaluado: %d\n",contador);
            return pos;
        }else if (vB<A[pos])
            fin=pos-1;
        else
            inicio=pos+1;
        contador++;
    }
    printf("\nVeces evaluado: %d\n",contador);
    return -1;
}

//Busqueda lineal con arreglo ordenado
int lmSearch(int A[],int n,int vB){
    int contador=0;
    if(vB<A[0] || vB>A[n-1]){
        printf("\nVeces evaluado: %d\n",contador);
        return -1;
    }else{
        for(int i=0;i<n;i++){
            if(A[i]==vB){
                printf("\nVeces evaluado: %d\n",contador+1);
                return i;
            }
            contador++;
        }
        printf("\nVeces evaluado: %d\n",contador);
        return -1;
    }
}
