

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"promo.h"


////OP��ES PARA MENU PROMO

void modulo_promo (void) {
   char opcao;
    do {
        opcao = promo();
        switch(opcao) {
            case '1':   listar_promo();
                        break;
            case '2': 	cadastrar_promo();
                        break;
            case '3': 	edit_promo();
                        break;
            case '4': 	excluir_promo();
                        break;
        } 		
    } while (opcao != '0');
}


///MENU PROMO��ES


char promo(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR PROMO��ES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMO��O-------------------DIGITE 2\n");
    printf(" 3. EDITAR PROMO��O----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMO��O---------------------DIGITE 4\n");
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

///OP��O CASE 1 (LISTA TODAS AS PROMO��ES V�LIDAS NO SISTEMA)

void listar_promo(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


///OP��O CASE 2 (CADASTRA NOVA PROMO��O NO SISTEMA)

void cadastrar_promo(void) {

    char anuncio[40];
    char val[12];
    char cod[12];

    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos cadastrar uma promo��o no sistema!");
    printf("\n");
    printf("\n");
    printf("An�ncio:\n");
    scanf("%c",anuncio);
    getchar();
    printf("\n");
    printf("Validade:\n");
    scanf("%c",val);
    getchar();
    printf("\n");
    printf("C�digo gerado da promo��o:\n");
    scanf("%c", cod);
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}


////OP��O CASE 3 (ALTERA DADOS/INFORMA��ES SOBRE PROMO��ES CADASTRADAS)



void edit_promo (void) {
    char opcao;

    do {
        opcao = editar_promo();

        switch (opcao) {
            case '1': 	edit_anuncio();
                        break;
            case '2': 	edit_validade();
                        break;
        } 		
    } while (opcao != '0');
   
}

char editar_promo(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos editar dados de uma promo��o no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR AN�NCIO-----------------------DIGITE 1\n");
    printf(" 2. EDITAR VALIDADE----------------------DIGITE 2\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}



void edit_anuncio(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o c�digo da promo��o:\n");
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


void edit_validade(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o c�digo da promo��o:\n");
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




////OP��O CASE 4 (EXCLUI PROMO��O CADASTRADA NO SISTEMA)


void excluir_promo(void) {
    char cod [10];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("Informe o c�digo da promo��o:");
    scanf("%c", cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

}