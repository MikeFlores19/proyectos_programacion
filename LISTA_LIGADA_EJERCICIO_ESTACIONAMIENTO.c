#include <stdio.h>
#include <stdlib.h>


struct node{
    int placa;
    char marca[20];
    struct node *next;
};
struct node *head=NULL;

void insertarFinal(int cant){
    for(int i=0;i<cant;i++){
        struct node *Newnode,*temp;
        Newnode=(struct node *)malloc(sizeof(struct node));
        Newnode->next=NULL;
        printf("\nIngrese la placa: ");
        scanf("%d",&Newnode->placa);
        printf("\nIngrese la marca: ");
        fflush(stdin);
        gets(Newnode->marca);

        if(head==NULL){
            head=Newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=Newnode;
        }
    }
}

void insertarInicio(int cant){
    for(int i=0;i<cant;i++){
        struct node *Newnode;
        Newnode=(struct node *)malloc(sizeof(struct node));
        Newnode->next=NULL;
        printf("\nIngrese la placa: ");
        scanf("%d",&Newnode->placa);
        printf("Ingrese la marca: ");
        fflush(stdin);
        gets(Newnode->marca);
        if(head==NULL){
            head=Newnode;
        }
        else{
            Newnode->next=head;
            head=Newnode;
        }
    }
}

void insertarPos(int cant){
    for(int i=0;i<cant;i++){
        int pos;
        struct node *Newnode,*temp;
        Newnode=(struct node *)malloc(sizeof (struct node));
        printf("\nEscriba la posicion donde quiere insertar: ");
        scanf("%d",&pos);
        printf("\nIngrese la placa: ");
        scanf("%d",&Newnode->placa);
        printf("\nIngrese la marca: ");
        fflush(stdin);
        gets(Newnode->marca);
        Newnode->next=NULL;
        if (pos==0){
            Newnode->next=head;
            head=Newnode;
        }
        else{
            temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
                if(temp==NULL){
                    printf("\nLa posicion no existe");
                    return;
                }
            }
            Newnode->next=temp->next;
            temp->next=Newnode;
        }
    }
}

void deletePos(){
    struct node *Newnode,*temp;
    int pos;
    if(head==NULL){
        printf("\nVACIO");
        return;
    }
    else{
        printf("\nIngrese la posicion del auto a quitar: ");
        scanf("%d",&pos);
        if(pos==0){
            temp=head;
            head=head->next;
            printf("\nSe elimino el elemento %d",temp->placa);
            free(temp);
        }
        else{
            temp=head;
            for(int i=0;i<pos;i++){
                Newnode=temp;
                temp=temp->next;
                if(temp==NULL){
                    printf("\nEl indice no existe");
                    return;
                }
            }
            Newnode->next=temp->next;
            printf("\nSe eleimino la placa %d",temp->placa);
            free(temp);
        }
    }

}

void imprimir() {
    if (head == NULL) {
        printf("\nVACIO");
    } else {
        struct node *temp;
        temp = head;
        while (temp != NULL) {
            printf("\nPLACA: %d MARCA: %s", temp->placa, temp->marca);
            temp = temp->next;
        }
    }
}


void cont(){
    struct node *temp;
    int cont1=0,cont2=0,placa;

    printf("Introduzca el numero de placa: ");
    scanf("%d",&placa);
    if(head==NULL){
        printf("\nVACIO");
    }
    else{
        temp=head;
        while(temp!=NULL){
            cont1++;
            if(temp->placa==placa){
                cont1=0;
                printf("\nHay %d carros antes",cont2);
            }
            cont2++;
            temp=temp->next;
        }
        printf("\nHay %d carros despues",cont1);
    }
}

int main(){
    int num,opc;
    do{
        printf("\nESTACIONAMIENTO DE AUTOS\n\n1.-ESTACIONAR AL PRINCIPIO\n2.-ESTACIONAR AL FINAL\n3.-ESTACIONAR EN UNA POSICION EN ESPECEFICO\n4.-ELIMINAR UN AUTO DEL ESTACIONAMIENTO\n5.-VER LA LISTA DE AUTOS\n6.-CONTADOR\n7.-SALIR\nEliga su opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                printf("\nIngrese cuantos carros desea estacionar: ");
                scanf("%d",&num);
                insertarInicio(num);
                break;
            case 2:
                printf("\nIngrese cuantos carros desea estacionar: ");
                scanf("%d",&num);
                insertarFinal(num);
                break;
            case 3:
                printf("\nIngrese cuantos carros desea estacionar: ");
                scanf("%d",&num);
                insertarPos(num);
                break;
            case 4:
                deletePos();
                break;
            case 5:
                imprimir();
                break;
            case 6:
                cont();
                break;
            default:
                printf("\nOPCION NO VALIDA");
      }

    }while(opc!=7);

    return 0;

}


