//MIGUEL ALEJANDRO FLORES SOTELO
//17/10/23
//ANALISIS Y DISEÑO DE ALGORITMOS
//N-QUEENS

#include <stdio.h>
#include <stdbool.h>
#define N 5


bool btNQueens(int [N][N],int,int *);
//btNQueens(tablero,columna);
bool isSafe(int [N][N],int,int);

int main() {
    //DECLARACION DE VARIABLES
    int board[N][N];
    int cont_soluciones=0;

    //RELLENO DEL TABLERO CON 0
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=0;
        }
    }


    btNQueens(board,0,&cont_soluciones);

    if(cont_soluciones==false){
        printf("NO HAY SOLUCION \n");
    }
    else{
        printf("Soluciones totales: %d\n",cont_soluciones);
        printf("Soluciones unicas: %d\n",cont_soluciones/2);
    }


    return 0;
}

bool btNQueens(int board[N][N],int col,int *cont_soluciones){

    if(col>=N){ //VERIFICA SI TODAS LAS REINAS SE HAN FIJADO EN TODAS LAS COLUMNAS DEL TABLERO
        printf("SOLUCION #%d\n",++(*cont_soluciones));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if (board[i][j]==1){
                    printf("Q ");
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
            solucion_encontrada=btNQueens(board,col+1,cont_soluciones);
            board[i][col]=0;
        }
    }
    return solucion_encontrada;

}


bool isSafe(int board[N][N],int r,int col){

    int i,j; //Renglones y columnas de otras reinas

    //verificar si hay reinas en el renglon del lado izquierdo
    for(i=0;i<col;i++){
        if(board[r][i]!=0){
            return false;
        }
    }


    //verificar si hay reinas en la diagonal izquierda superior
    for(i=r-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]!=0){
            return false;
        }
    }

    //verificar si hay reinas en la diagonal izquierda inferior
    for(i=r+1,j=col-1;i<N && j>=0; i++, j--){
        if(board[i][j]!=0){
            return false;
        }
    }
    return true;
}
