#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"cliente.h"
#include"bike.h"
#include"promo.h"
#include"aluguel.h"
#include"sobre.h"




//MENU PRINCIPAL
char menu_principal(void);




int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char opcao;

    do {
        opcao = menu_principal();
        switch(opcao) {
          case '1': modulo_bike();
                    break;
          case '2': modulo_cliente();
                    break;
          case '3': modulo_aluguel();
                    break;
          case '4': modulo_promo();
                    break;
          case '5': modulo_sobre();
                    break;
        } 	
    } while (opcao != '0');
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

char menu_principal(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. BIKES--------------------------------DIGITE 1\n");
    printf(" 2. CLIENTES-----------------------------DIGITE 2\n");
    printf(" 3. ALUGUEL------------------------------DIGITE 3\n");
    printf(" 4. PROMOÇOES----------------------------DIGITE 4\n");
    printf(" 5. SOBRE NÓS----------------------------DIGITE 5\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>>Aguarde\n");
    return esc;
}

