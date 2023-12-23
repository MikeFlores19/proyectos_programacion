//
// Created by MAGIC MIKE on 23/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
struct node{
    int placa;
    struct node *next;
};
struct node *head=NULL;

void InsertarFinal(){
    struct node *NewNode,*temp;
    NewNode=(struct node*)malloc(sizeof(struct node));
    printf("\nPLACA: ");
    scanf("%d",&NewNode->placa);
    NewNode->next=NULL;
    if(head==NULL){//LISTA VACIA
        head=NewNode;
    }
    else{//la lista no esta vacia
        temp=head;
        while(temp->next!=NULL){//recorrer hasta el final
            temp=temp->next;
        }
        temp->next=NewNode;//agrrgamos el nuevo elemento al final
    }
}

void imprimir(){

    if(head==NULL){
        printf("\nVACIO");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp!=NULL){
            printf("%d\n",temp->placa);
            temp=temp->next;
        }
    }
}

void contador(){
    if(head==NULL){
        printf("\nVACIO");
    }
    else{
        struct node *temp;
        temp=head;
        int val,c1,c2;
        c1=0;

        printf("\nIngrese la placa a buscar: ");
        scanf("%d",&val);
        while(temp!=NULL){
            c2++;
            if(val==temp->placa){
                c2=0;
                printf("\nHay %d carros antes",c1);
            }
            c1++;
            temp=temp->next;
        }
        printf("\nHay %d carros despues",c2);
    }
}
int main(){

    InsertarFinal();
    InsertarFinal();
    InsertarFinal();
    imprimir();
    contador();




    return 0;
}