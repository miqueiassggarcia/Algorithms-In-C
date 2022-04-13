#include <stdio.h>
#include <stdlib.h>

void main(){

    //Definindo uma variável
    int a = 5, b;

    //Imprimindo a variável "a"
    printf("%d", a);

    //Concatenando
    printf("\nO valor da var a eh: %d", a);

    //Mudando o valor de "a"
    a = 15;

    //Concatenando
    printf("\nO valor da var a eh: %d \n", a);

    //Lendo valores
    scanf("%d", &b);

    //Concatenando
    printf("O valor da var b eh: %d", b);

    //Pula linhas
    printf("\n");

    //Imprimindo
    printf("Uhuu");

    //Pausando
    system("read -p 'Press any key to continue...' var");

}
