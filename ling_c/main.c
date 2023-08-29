#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


void tela_menu_principal(void);
void tela_sobre(void);
void tela_bikes(void);
void tela_promocoes(void);

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    tela_menu_principal();
    tela_sobre();
    tela_bikes();
    tela_promocoes();
    return 0;
}


void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A CAR********************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. M�DULO BIKES DISPON�VEIS ------------DIGITE 1\n");
    printf(" 2. M�DULO CLIENTE-----------------------DIGITE 2\n");
    printf(" 3. M�DULO PROMO��ES---------------------DIGITE 3\n");
    printf(" 4. M�DULO SOBRE N�S---------------------DIGITE 4\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
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
    printf("  disciplina de Programa��o do curso de Sistemas\n");
    printf("  de Informa��o. O programa ser� desenvolvido   \n");
    printf("  para uma empresa de aluguel de bicicletas -   \n");
    printf("  a Rent a Bike.                                \n");
    printf("  Desenvolvedora: Anne Gabrielle!!!!!           \n");                  
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_bikes(void) {

    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A CAR********************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. VER BIKES----------------------------DIGITE 1\n");
    printf(" 2. ALUGUEL BIKE-------------------------DIGITE 2\n");
    printf(" 3. DICAS--------------------------------DIGITE 3\n");
    printf(" 4. CADASTRAR BIKE-----------------------DIGITE 4\n");
    printf(" 5. EDITAR BIKE--------------------------DIGITE 5\n");
    printf(" 6. EXCLUIR BIKE-------------------------DIGITE 6\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

    
void tela_clientes(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A CAR********************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. CADASTRAR CLIENTE -------------------DIGITE 1\n");
    printf(" 2. BUSCAR CLIENTE-----------------------DIGITE 2\n");
    printf(" 3. EDITAR CADASTRO----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR CADASTRO---------------------DIGITE 4\n");
    printf(" 5. LISTAR TODOS-------------------------DIGITE 5\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_promocoes(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A CAR********************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR PROMO��ES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMO��O----=--------------DIGITE 2\n");
    printf(" 3. EDITAR PROMO��O----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMO��O---------------------DIGITE 4\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



