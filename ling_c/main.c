#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"cliente.h"
#include"bike.h"
#include"aluguel.h"
#include"sobre.h"
#include"valid.h"
#include"relatorios.h"




//ASSINATURA MENU PRINCIPAL

char menu_principal(void);


////FUN��O PRINCIPAL

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
          case '4': modulo_sobre();
                    break;
          case '5': modulo_relatorio();
        } 	
    } while (opcao != '0');
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


///JANELA MENU PRINCIPAL

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
    printf(" 4. SOBRE N�S----------------------------DIGITE 5\n");
    printf(" 5. RELAT�RIOS---------------------------DIGITE 6\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>>Aguarde\n");
    sleep(1);
    return esc;
}

