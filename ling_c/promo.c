

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"promo.h"


////OPÇÕES PARA MENU PROMO

void modulo_promo (void) {
   char opcao;
    do {
        opcao = promo();
        switch(opcao) {
            case '1':   listar_promo();
                        break;
            case '2': 	cadastrar_promo();
                        break;
            case '3': 	editar_promo();
                        break;
            case '4': 	excluir_promo();
                        break;
        } 		
    } while (opcao != '0');
}


///MENU PROMOÇÕES


char promo(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR PROMOÇÕES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMOÇÃO-------------------DIGITE 2\n");
    printf(" 3. EDITAR PROMOÇÃO----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMOÇÃO---------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

///OPÇÃO CASE 1 (LISTA TODAS AS PROMOÇÕES VÃLIDAS NO SISTEMA)

void listar_promo(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


///OPÇÃO CASE 2 (CADASTRA NOVA PROMOÇÃO NO SISTEMA)

void cadastrar_promo(void) {

    char anuncio[40];
    char val[12];
    char cod[12];

    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos cadastrar uma promoção no sistema!");
    printf("\n");
    printf("\n");
    printf("Anúncio:\n");
    scanf("%c",anuncio);
    getchar();
    printf("\n");
    printf("Validade:\n");
    scanf("%c",val);
    getchar();
    printf("\n");
    printf("Código gerado da promoção:\n");
    scanf("%c", cod);
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}


////OPÇÃO CASE 3 (ALTERA DADOS/INFORMAÇÕES SOBRE PROMOÇÕES CADASTRADAS)

void editar_promo(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos editar dados de uma promoção no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR ANÚNCIO-----------------------DIGITE 1\n");
    printf(" 2. EDITAR VALIDADE----------------------DIGITE 2\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


////OPÇÃO CASE 4 (EXCLUI PROMOÇÃO CADASTRADA NO SISTEMA)


void excluir_promo(void) {
    char cod [10];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("Informe o código da promoção:");
    scanf("%c", cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

}