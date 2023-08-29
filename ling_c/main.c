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
    printf("Escolha sua opção: ");
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
    printf("Escolha sua opção: ");
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
    printf(" 1. LISTAR PROMOÇÕES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMOÇÃO----=--------------DIGITE 2\n");
    printf(" 3. EDITAR PROMOÇÃO----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMOÇÃO---------------------DIGITE 4\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



