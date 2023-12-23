//
// Created by MAGIC MIKE on 02/12/2023.
//
#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
};

struct node* newNode(char data){
    struct node *node= (struct node*) malloc(sizeof (struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int main(){
    struct node *root= newNode('/');
    root->left= newNode('+');
    root->right= newNode('*');
    root->left->left= newNode('a');
    root->left->right= newNode('b');
    root->right->left= newNode('-');
    root->right->right= newNode('e');
    root->right->left->left= newNode('c');
    root->right->left->right= newNode('d');


    int opc;
    printf("1.-ARBOL BINARIO (90 grados)\n2.-ARBOL BINARIO (45 grados)\nElige la opcion: ");
    scanf("%d",&opc);

    switch(opc) {
        case 1:
            printf("\t\t%c <-RAIZ\n", root->data);
            printf("              /  \\\n");
            printf("             %c    %c\n", root->left->data, root->right->data);
            printf("            / \\  / \\\n");
            printf("           %c   %c %c  %c\n", root->left->left->data, root->left->right->data, root->right->left->data,
                   root->right->right->data);
            printf("                / \\\n");
            printf("               %c  %c\n", root->right->left->left->data, root->right->left->right->data);
        break;
        case 2:
            printf("    %c",root->right->right->data);
            printf("  \n   %c",root->right->data);
            printf("    %c",root->right->left->right->data);
            printf("\n     %c\n",root->right->left->data);
            printf("        %c",root->right->left->left->data);
            printf("\n%c\n",root->data);
            printf("     %c\n",root->left->right->data);
            printf("   %c\n",root->left->data);
            printf("     %c",root->left->left->data);

        break;

        default:
            printf("OPCION INVALIDA");
    }



}