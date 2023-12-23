#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCIONES.h"

struct nodo {
    int letra, ocurrencia;
    struct nodo* next, *left, *right;
};
struct nodo* head = NULL;

void leerArch(char*);
void conteo(char*,int[][2]);
void insercion(int[][2]);
void listaligada(int,int);
void display();
void arbol_bin();
void generar_codigo(struct nodo*,int[],int,int*,int[][50]);
void imprimirArreglo(int[],int,int*,int[][50]);
void crear_archivo_binario(char*,int[][50],int);
char decodificar_caracter(int[][50],int,char*,int*);
void decodificar_e_imprimir(char*,int[][50],int);
void tasa_compres();

int main() {
    char nombreArch[20];
    char nombreArchBin[20];
    int tabla[27][2] = {0},diccionario[27][50]={0};
    int fila=0;
    printf("Ingrese el nombre del archivo a leer:");
    scanf("%s", nombreArch);

    printf("\nEl texto del archivo original es:\n");
    leerArch(nombreArch);
    printf("\n");

    conteo(nombreArch, tabla);//conteo de caracteres del archivo
    insercion(tabla);//ordenamiento de la tabla de menor a mayor
    for (int i = 0; i < 27; i++) {
        listaligada(tabla[i][0], tabla[i][1]);
    }

    display();
    arbol_bin();
    int arr[100], top = 0;
    printf("\nEl dicionario queda:\n");
    generar_codigo(head, arr, top,&fila,diccionario);
    /*for(int i=0;i<fila;i++){
        printf("\n%c: ",diccionario[i][0]+'a');
        for(int j=1;diccionario[i][j]!=2;j++){
            printf("%d",diccionario[i][j]);
        }
    }*/
    crear_archivo_binario(nombreArch,diccionario,fila);
    printf("\n  Ingrese el nombre del archivo a decodificar: ");
    scanf("%s",nombreArchBin);
    printf("\nEl archivo decodificado es: \n");
    decodificar_e_imprimir(nombreArchBin,diccionario,fila);
    tasa_compres();
    return 0;
}

void leerArch(char* nombreArch) {
    char texto[10000];
    FILE* archivo;
    archivo = fopen(nombreArch, "r");

    if (archivo == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO DE TEXTO");
    }
    else {
        while (fgets(texto, sizeof(texto), archivo) != NULL) {
            printf("%s", texto);
        }
    }
    fclose(archivo);
}

void conteo(char* nombreArch, int tabla[][2]) {
    char caracter;

    FILE* archivo;
    archivo = fopen(nombreArch, "r");

    if (archivo == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO");
    }
    while ((caracter = fgetc(archivo)) != EOF) {
        if ('a' <= caracter && 'z' >= caracter) {
            tabla[caracter - 'a'][0] = caracter - 'a';
            tabla[caracter - 'a'][1]++;
        } else if (caracter == ' ') {
            tabla[26][0] = caracter - 'a';
            tabla[26][1]++;
        }
    }

    fclose(archivo);

    /*for (int i = 0; i < 27; i++) {
        if (i < 26) {
            printf("LETRA:%c, CONTEO:%d\n", 97 + i, tabla[i][1]);
        }
        else {
            printf("ESPACIO: %d\n", tabla[i][1]);
        }
    }*/
}

void insercion(int arr[][2]) {
    int j, aux, letr;
    for (int i = 0; i < 27; i++) {
        aux = arr[i][1];
        letr = arr[i][0];
        j = i - 1;
        while ((j >= 0) && (arr[j][1] > aux)) {
            arr[j + 1][1] = arr[j][1];
            arr[j + 1][0] = arr[j][0];
            j--;
        }
        arr[j + 1][1] = aux;
        arr[j + 1][0] = letr;
    }
}

void listaligada(int i, int oc) {
    if (oc != 0) {
        struct nodo* nuevo, *temp;
        nuevo = (struct nodo*)malloc(sizeof(struct nodo));
        nuevo->letra = i;
        nuevo->ocurrencia = oc;
        nuevo->next = NULL;
        nuevo->left = NULL;
        nuevo->right = NULL;
        if (head == NULL) {
            head = nuevo;
            return;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nuevo;
        }
    } else {
        return;
    }
}

void display() {
    struct nodo* temp;
    if (head == NULL) {
        printf("\nLa lista esta vacia\n");
        return;
    } else {
        temp = head;
        printf("\nLos elementos de la lista son: \n");
        while (temp != NULL) {
            printf("(%c = %d)->\t", temp->letra + 'a', temp->ocurrencia);
            temp = temp->next;
        }
        printf("Null\n");
    }
}

void arbol_bin() {
    while (head->next != NULL) {
        struct nodo* neww = (struct nodo*)malloc(sizeof(struct nodo));
        neww->ocurrencia = head->ocurrencia + head->next->ocurrencia;
        neww->left = head;
        neww->right = head->next;
        head = head->next->next;
        neww->next = NULL;

        if (head == NULL || head->ocurrencia >= neww->ocurrencia) {
            neww->next = head;
            head = neww;
        }
        else {
            struct nodo* current = head;
            while (current->next != NULL && current->next->ocurrencia < neww->ocurrencia) {
                current = current->next;
            }
            neww->next = current->next;
            current->next = neww;
        }
    }
}

void generar_codigo(struct nodo* raiz, int arr[], int top,int* num,int dicc[][50]) {
    if (raiz->left) {
        arr[top] = 0;
        generar_codigo(raiz->left, arr, top + 1,num,dicc);
    }

    if (raiz->right) {
        arr[top] = 1;
        generar_codigo(raiz->right, arr, top + 1,num,dicc);
    }

    if (raiz->left==NULL && raiz->right==NULL) {
        printf("%c: ", raiz->letra + 'a');
        dicc[(*num)][0]=raiz->letra;
        imprimirArreglo(arr, top,num,dicc);
        (*num)++;
    }
}

void imprimirArreglo(int arr[], int n,int* fil,int dic[][50]) {
    for (int i = 0; i < n; ++i){
        printf("%d", arr[i]);
        dic[(*fil)][i+1]=arr[i];
    }
    dic[(*fil)][n+1]=2;
    printf("\n");
}


void crear_archivo_binario(char* nombreArch, int dicc[][50], int num) {
    char texto[10000];
    FILE* archivo;
    archivo = fopen(nombreArch, "r");

    if (archivo == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO DE TEXTO");
    } else {
        FILE *file_comprimido;
        file_comprimido= fopen("archivo_compres.txt", "w");
        if (file_comprimido == NULL) {
            printf("No se pudo abrir el archivo\n");
            return;
        }

        while (fgets(texto, sizeof(texto), archivo) != NULL) {
            for (int i = 0; i < strlen(texto); ++i) {
                char c = texto[i];
                for (int j = 0; j < num; ++j) {
                    if (dicc[j][0] == c - 'a') {
                        int k = 1;
                        while(dicc[j][k] != 2) {
                            fprintf(file_comprimido, "%d", dicc[j][k]);
                            ++k;
                        }
                        fprintf(file_comprimido, " ");  // Agrega un espacio en blanco después de cada código binario
                        break;
                    }
                }
            }
        }

        fclose(file_comprimido);
    }
    fclose(archivo);
}


char decodificar_caracter(int dicc[][50], int num, char* binario, int* i) {
    int max_j = -1; // indice del elemento del diccionario que coincide con el código binario
    int max_k = -1; // longitud del código binario que coincide
    for (int j = 0; j < num; ++j) { // para cada elemento en el diccionario
        int k = 1; // indice para recorrer el elemento del diccionario
        // mientras el elemento del diccionario coincida con el código binario
        while(dicc[j][k] != 2 && (*i) + k - 1 < strlen(binario) && dicc[j][k] == binario[(*i) + k - 1] - '0') {
            ++k; // avanza al siguiente elemento del diccionario
        }
        // si se ha encontrado un código binario que coincide y es más largo que el anterior
        if (dicc[j][k] == 2 && (max_j == -1 || k > max_k)) {
            max_j = j; // almacena el índice del elemento del diccionario
            max_k = k; // almacena la longitud del código binario
        }
    }
    if (max_j != -1) { // si se ha encontrado un código binario que coincide
        (*i) += max_k - 1; // avanza el índice del código binario
        return dicc[max_j][0] + 'a'; // devuelve el carácter correspondiente al código binario
    }
    ++(*i); // avanza al siguiente carácter del código binario
    return '\0'; // devuelve el carácter nulo si no se encontró un código binario que coincida
}

void decodificar_e_imprimir(char* nombreArchBin, int dicc[][50], int num) {
    char caracter; // carácter decodificado
    FILE* archivo = fopen(nombreArchBin, "r"); // abre el archivo en modo de lectura
    if (archivo == NULL) { // si no se pudo abrir el archivo
        printf("ERROR AL ABRIR EL ARCHIVO DE TEXTO"); // imprime un mensaje de error
        return; // sale de la función
    }

    char binario[10000]; // buffer para almacenar el código binario del archivo
    while (fscanf(archivo, "%s", binario) != EOF) { // mientras haya códigos binarios en el archivo
        int i = 0; // indice para recorrer el código binario
        while (i < strlen(binario)) { // mientras no se haya recorrido todo el código binario
            caracter = decodificar_caracter(dicc, num, binario, &i); // decodifica el carácter correspondiente al código binario actual
            if (caracter != '\0') { // si el carácter decodificado no es el carácter nulo
                printf("%c", caracter); // imprime el carácter decodificado
            }
        }
    }
    printf("\n"); // imprime una nueva línea al final del texto decodificado

    fclose(archivo); // cierra el archivo
}

void tasa_compres(){
    FILE *arch_org;
    FILE *arch_bin;
    char c;
    float num_caracteres=0,num_bits=0,tasa_de_compresion;

    arch_org=fopen("compres.txt","r");
    if(arch_org==NULL){
        printf("El archivo original no puede abrirse");
    }
    arch_bin=fopen("archivo_compres.txt","r");
    if(arch_bin==NULL){
        printf("El archivo binario no puede abrirse");
    }

    while((c=fgetc(arch_org))!=EOF){
        ++num_caracteres;
    }

    while((c=fgetc(arch_bin))!=EOF){
        if(c=='1' || c=='0'){
            ++num_bits;
        }
    }

    fclose(arch_org);
    fclose(arch_bin);

    tasa_de_compresion=(num_bits*100)/(num_caracteres*8);
    printf("\nLa tasa total de compresion fue de %.2f%%\n",tasa_de_compresion);
}





