//
// Created by MAGIC MIKE on 12/09/2023.
//
#include <stdio.h>
#define range 10

void countsort(int [],int,int);
void radixsort(int [],int ,int);
int find_max(int [],int);

int main(){
    int arr[]={13,87,34,25,2345,23,54,93,122,23};
    int n=sizeof(arr)/sizeof(arr[0]);

    int max= find_max(arr,n);

    radixsort(arr, n, max);
    printf("Arreglo ordenado:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}

void countsort(int arr[],int n, int place){
    int frecuencia[range]={0};
    int output[n];

    for(int i=0;i<n;i++){
        frecuencia[(arr[i]/place)%range]++;
    }

    for(int i=1;i<range;i++){//NOTA: VER PORQUE 1
        frecuencia[i]+=frecuencia[i-1];
    }

    for(int i=n-1;i>0;i--){
        output[frecuencia[(arr[i]/place)%range]-1]=arr[i];
        frecuencia[(arr[i]/place)%range]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

}

void radixsort(int arr[],int n,int find_max){
    int mul=1;
    while(find_max>0){
        countsort(arr,n,mul);
        mul*=10;
        find_max/=10;
    }
}

int find_max(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}