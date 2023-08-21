#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


void tela_menu_principal(void);
void tela_sobre(void);


int main(void) {
    setlocale(LC_ALL,"Portuguese");
    tela_menu_principal();
    tela_sobre();
    return 0;
}

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A CAR********************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. MÓDULO BIKES DISPONÍVEIS ------------DIGITE 1\n");
    printf(" 2. MÓDULO CLIENTE-----------------------DIGITE 2\n");
    printf(" 3. MÓDULO PROMOÇÕES---------------------DIGITE 3\n");
    printf(" 4. MÓDULO SOBRE NÓS---------------------DIGITE 4\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("            * * * * RENT A CAR * * * *\n");
    printf("\n");
    printf("  Programa desenvolvido na linguagem C para a   \n");
    printf("  disciplina de Programação do curso de Sistemas\n");
    printf("  de Informação. O programa será desenvolvido   \n");
    printf("  para uma empresa de aluguel de bicicletas -   \n");
    printf("  a Rent a Bike.                                \n");
    printf("  Desenvolvedora: Anne Gabrielle!!!!!           \n");                  
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}