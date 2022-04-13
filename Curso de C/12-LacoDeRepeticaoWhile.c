#include <stdio.h>
#include <stdlib.h>

//Função principal do programa
void main(){

    //Definindo Variáveis
    int a = 1, b = 10;

    //Contando até 10
    while(a <= 10){

        //Imprimindo 'a' na tela
        printf("%d\n", a);

        //Incremento
        a++;     //a = a + 1;

    }

    //Contagem Regressiva
    while(b >= 1){

        //Imprimindo 'b' na tela
        printf("%d\n", b);

        //Incremento
        b--;    //b = b - 1;

    }

    //Pausa o programa após executar
    system("read -p 'Press any key to continue' var");

}

