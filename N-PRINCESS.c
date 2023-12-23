//MIGUEL ALEJANDRO FLORES SOTELO
//17/10/23
//ANALISIS Y DISEÑO DE ALGORITMOS
//N-PRINCESS

/*Has inventado una nueva pieza de ajedrez, la cual has nombrado princesa. Una princesa puede atacar toda su fila o
 * columna (como la torre) pero sólo puede atacar las celdas diagonales contiguas (como el rey).
 * Escribe un programa que imprima las formas distintas (totales) en que pueden colocarse princesas sin que se ataquen
 * mutuamente en un tablero de ajedrez de  celdas.
*/


#include <stdio.h>
#include <stdbool.h>
#define N 5


bool btNPrincess(int [N][N],int,int *);
//btNQueens(tablero,columna);
bool isSafe(int [N][N],int,int);

int main() {
    //DECLARACION DE VARIABLES
    int board[N][N];
    int cont_soluciones=0;
    int solucion_unicas=0;

    //RELLENO DEL TABLERO CON 0
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=0;
        }
    }


    btNPrincess(board,0,&cont_soluciones);

    if(cont_soluciones==false){
        printf("NO HAY SOLUCION \n");
    }
    else {
        printf("Soluciones totales: %d\n", cont_soluciones);
    }


    return 0;
}

bool btNPrincess(int board[N][N],int col,int *cont_soluciones){

    if(col>=N){ //VERIFICA SI TODAS LAS REINAS SE HAN FIJADO EN TODAS LAS COLUMNAS DEL TABLERO
        printf("SOLUCION #%d\n",++(*cont_soluciones));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]==1){
                    printf("P ");
                }
                else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");
        return true;
    }

    bool solucion_encontrada=false;

    for(int i=0;i<N;i++){
        if(isSafe(board,i,col)){
            board[i][col]=1;
            solucion_encontrada=btNPrincess(board,col+1,cont_soluciones);
            board[i][col]=0;
        }
    }
    return solucion_encontrada;

}


bool isSafe(int board[N][N], int r, int col) {
    int i;//renglones y columnas de otroas princesas

    // Verificar si hay princesas en la fila
    for (i = 0; i < N; i++) {
        if (board[r][i]!=0) {
            return false;
        }
    }
    // Casilla superior izquierda
    if (r > 0 && col > 0 && board[r - 1][col - 1] != 0) {
        return false;
    }

    //Casilla inferior izquierda
    if (r < N - 1 && col > 0 && board[r + 1][col - 1] != 0) {
        return false;
    }

    return true;
}

