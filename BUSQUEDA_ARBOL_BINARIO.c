//
// Created by MAGIC MIKE on 06/12/2023.
//
#include <stdio.h>
#include <stdlib.h>
//creacion plantilla
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *NuevoNodo(int k){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=k;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct node *search(struct node *root,int k){//busqueda de algun elemento :D
    if(root==NULL || root->data==k){
        return root;
    }
    else if(k<root->data){//nos vamos a la izquiera
        return search(root->left,k);
    }
    else{//nos vamos a la derecha
        return search(root->right,k);
    }
}

struct node *insert(struct node *root,int k){
    if(root==NULL){
        return NuevoNodo(k); //termina la recursion e insertalo o saber si esta vacio
    }
    else if(k>=root->data){
        root->right=insert(root->right,k);
    }
    else{
        root->left=insert(root->left,k);
    }
    return root; //se regresa para saber quese ha modificado
}

struct node *finMin(struct node *root){
    if(root==NULL){
        return NULL; //sirve para saber si no esta vacio
    }
    else if(root->left!=NULL){//saber que no hay mas elementos la izquiersa
        return finMin(root->left);
    }
    return root;
}

struct node *delete(struct node *root,int k){
    //etapa de busqueda
    if(root==NULL){//no esta el elemtno que eliminaremos
        return NULL;
    }
    if(k>root->data){
        root->right=delete(root->right,k);// ayuda a buscar el elemento y crear ligas
    }
    else if(k<root->data){
        root->left=delete(root->left,k);
    }
    else{//vamos a eliminar
        //eliminar root soltero(sin hijos o hojas)
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //eliminar un root con UN SOLO HIJO
        else if(root->left==NULL || root->right==NULL){
            struct node *temp;
            if (root->left==NULL){
                temp=root->right;
            }
            else{
                temp=root->left;
            }
            free(root);
            return (temp);
        }
        //eliminar cuando hay mas d eun hijito o tenga muchos nietos
        else{
            struct node *temp= finMin(root->right);//encuentra el elemento mas pequeño ,el menor de todos del subarbol derecho
            root->data=temp->data;//respaldo o duplicado
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

int sum_nodes(struct node *root,int k1,int k2){
    struct node *dat1,*dat2;
    int result;
    dat1=search(root,k1);
    dat2= search(root,k2);

    if(dat1==NULL || dat2==NULL) {
        printf("NO EXISTE AL MENOS ALGUNO DE LOS ELEMENTOS PARA SUMAR\n");
        return 0;
    }

    result = dat1->data + dat2->data;
    return result;
}

int cont_nodes(struct node *root){
    int cont=1;
    if(root==NULL) {
        return 0;
    }
    else{
        cont+= cont_nodes(root->left);
        cont+=cont_nodes(root->right);
        return cont;
    }
}

int cont_hojas(struct node *root){
    int hjs_izq,hjs_der;
    if (root==NULL){
        return 0;
    }
    else if(root->right==NULL && root->left==NULL){
        return 1;
    }
    else{
        hjs_izq= cont_hojas(root->right);
        hjs_der= cont_hojas(root->left);
        return hjs_izq+hjs_der;
    }
}

int cont_niv(struct node *root){
    int profundidad_izq,profundidad_der,profundidad_max;
    if(root== NULL){
        return 0;
    }
    else{
           profundidad_izq=cont_niv(root->left);
           profundidad_der=cont_niv(root->right);

           if(profundidad_der>profundidad_izq){
               profundidad_max=profundidad_der;
           }
           else{
               profundidad_max=profundidad_izq;
           }
            return profundidad_max+1;
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}

int main(){
    struct node *root=NULL;
    int opc,dato,dato2,result;

    do{
        printf("\nMENU\n");
        printf("1.-INSERTAR ELEMENTO\n");
        printf("2.-BUSCAR ELEMENTO\n");
        printf("3.-BORRAR ELEMENTO\n");
        printf("4.-IMPRIMIR ARBOL INORDER\n");
        printf("5.-SUMAR NODOS\n");
        printf("6.-CONTEO DE NODOS\n");
        printf("7.-CONTEO DE HOJAS\n");
        printf("8.-PROFUNDIAD DEL ARBOL\n");
        printf("9.-SALIR\n");


        printf("ELIGA SU OPCION: ");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc){
            case 1:
                printf("Ingrese elemento a insertar: ");
                scanf("%d",&dato);
                root=insert(root,dato);
                break;
            case 2:
                printf("Ingrese elemento a buscar: ");
                scanf("%d",&dato);
                root=search(root,dato);
                break;
            case 3:
                printf("Ingrese elemento a eliminar: ");
                scanf("%d",&dato);
                root=delete(root,dato);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                printf("Ingrese el primer elemento a sumar: ");
                scanf("%d",&dato);
                printf("Ingrese el segundo elemento a sumar: ");
                scanf("%d",&dato2);
                result= sum_nodes(root,dato,dato2);
                printf("La suma es %d",result);
                break;
            case 6:
                result= cont_nodes(root);
                printf("Los nodos totales son %d",result);
                break;

            case 7:
                result= cont_hojas(root);
                printf("Las hojas totales son %d",result);
            case 8:
                result= cont_niv(root);
                printf("Los niveles del arbol son %d",result);
                break;
            default:
                printf("OPCION INVALIDA");
                break;
        }
    }while(opc!=9);
    printf("GRACIAS,HASTA LUEGO");


    return 0;

}