#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int cont(int array[],int limit){
    int contador=0;

    for(int j=0;j<limit;j++){
        array[j];
        contador++;
    }
    return contador;
}

void swapp(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partitionn(int array[],int low,int high){
    int pivot=array[high];
    int index=low-1;

    for(int j=low;j<=high-1;j++){
        if(array[j]<=pivot){
            index++;
            swapp(&array[index],&array[j]);
        }
    }
    swapp(&array[index+1],&array[high]);
    return index+1;
}

void quickSort(int array[],int low,int high){
    if(low<=high){
        int pivotindex=partitionn(array,low,high);
        quickSort(array,pivotindex+1,high);
        quickSort(array,low,pivotindex-1);
    }
}

int binSearch(int array[],int start,int end,int vB){
    int mid;
    while(start<=end){
        mid=start+(end-start)/2;
        if(vB==array[mid]){
            return mid+1;
        }
        else if(vB<=array[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return -1;
}

