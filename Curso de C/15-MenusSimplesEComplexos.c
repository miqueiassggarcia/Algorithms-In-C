#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Função principal do programa
void main(){
    setlocale(LC_ALL, "");
    //Definindo Variáveis
    int opcao;

    //Confere e valida a opção
    while(opcao < 1 || opcao > 3){

         //Interface de Menu
        printf("Escolha uma opção:");
        printf("\n1-opção 1");
        printf("\n2-opção 2");
        printf("\n3-opção 3\n");

        //Lendo a opção
        scanf("%d", &opcao);

        //Resultado de acordo com a opção escolhida
        switch(opcao){
             case 1:
                printf("Opção 1 foi escolhida\n");
                break;
             case 2:
                printf("Opção 2 foi escolhida\n");
                break;
             case 3:
                printf("Opção 3 foi escolhida\n");
                break;
            default:
                printf("Opção Inválida\n\n");
                break;
        }
    }
}

