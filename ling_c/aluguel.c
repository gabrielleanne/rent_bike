
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"aluguel.h"


////OP��ES PARA MENU ALUGUEL


void modulo_aluguel (void) {
   char opcao;
    do {
        opcao = aluguel();
        switch(opcao) {
            case '1': 	bike_disponivel();
                        break;
            case '2': 	alugar_bike();
                        break;
            case '3': 	buscar_aluguel();
                        break;
            case '4': 	excluir_aluguel();
                        break;
            case '5':   listar_aluguel();
                        break;
        } 		
    } while (opcao != '0');
}


////MENU ALUGUEL DE BIKES

char aluguel(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. BIKES DISPON�VEIS--------------------DIGITE 1\n");
    printf(" 2. ALUGAR BIKE--------------------------DIGITE 2\n");
    printf(" 3. BUSCAR ALUGUEL-----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR ALUGUEL----------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

//////ESCOLHA DA OP��O CASE 1 (VISUALIZA BIKES DISPON�VEIS PARA ALUGAR)

void bike_disponivel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


/////ESCOLHA DA OP��O CASE 2 (REALIZAR ALUGUEL DE BIKE)

void alugar_bike(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  
}


///ESCOLHA DA OP��O CASE 3 (BUSCAR ALUGUEL DE BIKE)

void buscar_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  
}


////ESCOLHA DA OP��O CASE 4 (EXCLUIR ALUGUEL DE BIKE)

void excluir_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  
}

//// OP��O CASE 5 (RELAT�RIO DE TODOS OS ALUGU�IS VIGENTES)

void listar_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  
}