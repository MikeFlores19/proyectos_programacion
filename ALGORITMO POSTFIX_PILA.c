//
// Created by MAGIC MIKE on 03/11/2023.
//
#include <stdio.h>
#include <ctype.h>
int stack[50];// para guardar operandos
int top=-1;//la pila esta vacia

void push (int val){
    stack[++top]=val;
}

int  pop(){
    return stack[top--];
}


int main(){
    char exp[20];//guardar toda la expresion abc+*
    char *op;
    int n1,n2,res;
    printf("Escribe la expresion: ");
    fgets(exp,sizeof(exp),stdin);
    op=exp;//exp lo igualas a la variable puntero op

    while(*op!='\0'){ // mientras op no termine, seguira reocrriendo la expresion postfix
        if(isdigit(*op)){// si op es digito (0.9)
           int num=0;
           while(isdigit(*op)){//mientras sea digitos en op
                num=num*10+(*op-48); //se realizar una formula que va despplazando los numeros a la izquierda en caso de ser de mas de dos cifras
                op++;//sigue aumentando caracter por caracter
           }
            push(num);//se pone el numero en la fila
        }
        else if(*op==' '){// si es un espacio, simplemente se ignora(se utilizan los expacios, para diferenciar un valor de otro)
            op++;//aumenta al siguiente caracter ignorando el espacio
        }

        else{//si encuentra un operador
            n1=pop();//operando 1//sacara el numero inmediato adyacente al operador
            n2=pop();//operando 2//sacara el segundo numero inmediato adyacetne al operador
            //realiza las operaciones correspondientes del signo operador
            if(*op=='+'){
                res=n1+n2;
            }
            else if(*op=='-'){
                res=n2-n1;
            }
            else if(*op=='*'){
                res=n2*n1;
            }
            else if(*op=='/'){
                res=n2/n1;
            }
            push(res);//inserta el resultado en la pila , si es el ultimo(llega al caracter nulo) , autamaticamente se imprime , sino ese mismo resultado se seguira evaluando con lo demas
            op++; // solo avanza al siguinte caracter cuando se procesa un operador
        }

    }
    printf("\n El resultado de %s = %d",exp,pop());

    return 0;
}
