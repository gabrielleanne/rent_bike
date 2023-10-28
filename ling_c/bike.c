
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"bike.h"
#include"util.h"


////OPÇÕES PARA MENU BIKES

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
    char tipo;
    char aro[3];
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
    tipo = tipo_bike(); printf("|%c|\n",tipo);
    verifica_aro (aro);
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


char tipo_bike(void) {
    
    char esc;

    printf(" 1. MOUNTAIN BIKE------------------------DIGITE 1\n");
    printf(" 2. BIKE ELÉTRICA------------------------DIGITE 2\n");
    printf(" 3. BIKE SPEED/ESTRADA-------------------DIGITE 3\n");
    printf(" 4. BIKE URBANA--------------------------DIGITE 4\n");
    printf("\n");
    printf("Escolha sua opçãoo: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    return esc;



    // if (esc==1){
    //     tipo=1;
    //     scanf("%c", &tipo);
    //     getchar();
    //     //strcpy(tipo, "Mountain Bike");
    // }
    // else if (esc==2){
    //     tipo =2;
    //     scanf("%c", &tipo);
    //     getchar();
    // }
    // else if (esc==3){
    //     tipo= 3;
    //     scanf("%c", &tipo);
    //     getchar();
    // }
    // else if (esc==4){
    //   tipo= 4;
    //   scanf("%c", &tipo);
    //   getchar();
    // }
    // printf("\t\t\t>>> Tecle <ENTER> para  continuar...\n");
    // getchar();
   
    
  
}





void verifica_aro (char* aro){
    printf("Aro da bike: ");
    fgets(aro, 3, stdin);
    while (!valida_aro (aro)) {
        printf("Aro informado não é válido!\n");
        printf("Informe o aro novamente: ");
        fgets(aro, 3, stdin);
    }
}



////OPÇÃO CASE 2 (ESCOLHA DE DADOS/INFORMAÇÕES PARA EDITAR)



void opcao_editar (void) {
    char opcao;

    do {
        opcao = editar_bike();

        switch (opcao) {
            case '1': 	altera_tipo();
                        break;
            case '2': 	altera_aro();
                        break;
            case '3': 	altera_valor();
                        break;
            case '4': 	altera_marca();
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

//FUNÇÃO PARA ALTERAR TIPO DE BIKE CADASTRADA

void altera_tipo(void) {
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

//FUNÇÃO PARA ALTERAR ARO DE BIKE CADASTRADA

void altera_aro(void) {
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


//FUNÇÃO PARA ALTERAR VALOR DO ALUGUEL DE BIKE CADASTRADA


void altera_valor(void) {
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


//FUNÇÃO PARA ALTERAR MARCA DE BIKE CADASTRADA


void altera_marca(void) {
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



/// OPÇÃO CASE 4 (EXCLUI BIKE CADASTRADA DO SISTEMA ATRAVÉS DO CÓDIGO DA BIKE)

  
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