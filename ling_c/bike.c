
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"bike.h"




void modulo_bike (void) {
   char opcao;
    do {
        opcao = bikes();
        switch(opcao) {
            case '1': 	cadastrar_bike();
                        break;
            case '2': 	editar_bike();
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

void cadastrar_bike(void) {

    char tipo [30];
    char aro[5];
    char quadro[10];
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
    printf("Tipo da bike (Mountain Bike, El�trica, Estrada/speed ou Urbana):\n");
    scanf("%c[A-Z������������ a-z������������]", tipo);
    getchar();
    printf("Aro da bike:\n");
    scanf("%c[0-9]",aro);
    getchar();
    printf("Tamanho de quadro:\n");
    scanf("%c[0-9]", quadro);
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




void editar_bike(void) {
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
    printf(" 3. EDITAR TAMANHO DE QUADRO-------------DIGITE 3\n");
    printf(" 4. EDITAR MARCA-------------------------DIGITE 4\n");
    printf(" 5. EDITAR CÓDIGO------------------------DIGITE 5\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("Tecle <ENTER> para continuar...\n");
    getchar();
    
    
    
}





void buscar_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o c�digo da bike:\n");
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

void excluir_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o c�digo da bike:");
    scanf("%c", &cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

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