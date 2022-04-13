#include <stdio.h>
#include <stdlib.h>

//Função principal do programa
void main(){

    //Definir Variáveis
    int cont;

    //Tabuada do 5
    for(cont = 1; cont <= 10; cont++){
        printf("5 X %d = %d\n",cont, 5 * cont);
    }

    //Contando de 2 em 2
    for(cont = 0; cont <= 10; cont = cont + 2){
        printf("%d\n",cont);
    }

    //Contagem regressiva
    for(cont = 10; cont > 0; cont--){
        printf("%d\n", cont);
    }

}

