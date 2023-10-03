
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"bike.h"


////OPÇÕES PARA MENU BIKES)

void modulo_bike (void) {
   char opcao;
    do {
        opcao = bikes();
        switch(opcao) {
            case '1': 	cadastrar_bike();
                        break;
            case '2': 	opcao_editar();
                        break;
            case '3': 	buscar_bike();
                        break;
            case '4': 	excluir_bike();
                        break;
            case '5':   listar_bikes();
                        break;
        } 		
    } while (opcao != '0');
}

////MENU BIKES

char bikes(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf(" 1. CADASTRAR BIKE-----------------------DIGITE 1\n");
    printf(" 2. EDITAR BIKE--------------------------DIGITE 2\n");
    printf(" 3. BUSCAR BIKE--------------------------DIGITE 3\n");
    printf(" 4. EXCLUIR BIKE-------------------------DIGITE 4\n");
    printf(" 5. LISTAR BIKES-------------------------DIGITE 5\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opçãoo: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}


////OPÇÃO CASE 1 (CADASTRA NOVA BIKE NO SISTEMA)

void cadastrar_bike(void) {

    char tipo [30];
    char aro[5];
    char valor_aluguel[5];
    char marca[20];
    char cod[10];

    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("Vamos cadastrar uma bike no sistema!\n");
    printf("\n");
    printf("\n");
    printf("Tipo da bike (Mountain Bike, Elétrica, Estrada/speed ou Urbana):\n");
    scanf("%c[A-Z������������ a-z������������]", tipo);
    getchar();
    printf("Aro da bike:\n");
    scanf("%c[0-9]",aro);
    getchar();
    printf("Valor do aluguel:\n");
    scanf("%c[0-9]", valor_aluguel);
    getchar();
    printf("Marca da bike:\n");
    scanf("%c[A-Z������������ a-z������������]", marca);
    getchar();
    printf("Código gerado da bike:\n");
    scanf("%c[0-9]", cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}


////OPÇÃO CASE 2 (ESCOLHA DE DADOS/INFORMAÇÕES PARA EDITAR)



void opcao_editar (void) {
    char opcao;

    do {
        opcao = editar_bike();

        switch (opcao) {
            case '1': 	tipo_bike();
                        break;
            case '2': 	aro_bike();
                        break;
            case '3': 	valor_aluguel();
                        break;
            case '4': 	marca_bike();
                        break;
            case '5':   codigo_bike();
                        break;
        } 		
    } while (opcao != '0');
   
}

char editar_bike(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("Vamos editar dados de uma bike no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR TIPO DE BIKE------------------DIGITE 1\n");
    printf(" 2. EDITAR ARO---------------------------DIGITE 2\n");
    printf(" 3. EDITAR VALOR DO ALUGUEL--------------DIGITE 3\n");
    printf(" 4. EDITAR MARCA-------------------------DIGITE 4\n");
    printf(" 5. EDITAR CÓDIGO------------------------DIGITE 5\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}



void tipo_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:\n");
    scanf("%c",&cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void aro_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:\n");
    scanf("%c",&cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void valor_aluguel(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:\n");
    scanf("%c",&cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void marca_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:\n");
    scanf("%c",&cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void codigo_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:\n");
    scanf("%c",&cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




/////OPÇÃO CASE 3 (BUSCA BIKE NO SISTEMA ATRAVÉS DO CÓDIGO DA BIKE)

void buscar_bike(void) {
    char cod [10];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("Informe o código da bike:\n");
    scanf("%c",cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



/// OPÇÃO CASE 4 (EXCLUI BIKE CADASTRADA DO SISTEMA)

  
void excluir_bike(void) {
    char cod [10];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("Informe o código da bike:");
    scanf("%c", cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

////OPÇÃO CASE 5 (LISTA TODAS AS BIKES CADASTRADAS NO SISTEMA)

void listar_bikes(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}