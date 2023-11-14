

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>
#include "relatorios.h"
#include "aluguel.h"
#include "bike.h"
#include "cliente.h"
#include "promo.h"





/// OPÇÕES PARA MENU RELATÓRIOS 

void modulo_relatorio (void) {

   char opcao;
    do {
        opcao = relatorios();
        switch(opcao) {
            case '1': 	listar_clientes();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
             case '2': 	listar_bikes();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;            
             case '3':  listar_promo();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
             case '4':  listar_aluguel();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar(); 
                        break;         
         } 		
   } while (opcao != '0'); 
}




//MENU RELATÓRIOS

char relatorios(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR CLIENTES ---------------------DIGITE 1\n");
    printf(" 2. LISTAR BIKES-------------------------DIGITE 2\n");
    printf(" 3. LISTAR PROMOÇÕES-------- ------------DIGITE 3\n");
    printf(" 4. LISTAR ALUGUÉIS----------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c",&esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}



// // ////OPÇÃO CASE 1 (LISTA TODOS OS CLIENTES CADASTRADOS NO SISTEMA)

void listar_clientes(void) {
  FILE* fp;
  Cliente* cli;
  printf("\n");
  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-50s", "NOME");
  printf("|");
  printf("%-12s", "CPF");
  printf("|");
  printf("%-20s", "LOGRADOURO");
  printf("|");
  printf("%-5s", "NÚMERO");
  printf("|");
  printf("%-15s", "BAIRRO");
  printf("|");
  printf("%-40s", "E-MAIL");
  printf("|");
  printf("\n");
  printf("%51s", "|");
  printf("%13s", "|");
  printf("%21s", "|");
  printf("%6s", "|");
  printf("%16s", "|");
  printf("\n");
  while (fread(cli, sizeof(Cliente), 1, fp)) { 
    if (cli->status != 'x') {
      printf("%-51s", cli->nome);
      printf("|");
      printf("%-12s", cli->cpf);
      printf("|");
      printf("%-20s", cli->log);
      printf("|");
      printf("%-5s", cli->num);
      printf("|");
      printf("%-15s", cli->bai);
      printf("|");
      printf("%-40s", cli->email);
      printf("|");
      printf("\n");
    }
  }
  fclose(fp);
  free(cli);
}



// // ////OPÇÃO CASE 2 (LISTA TODAS AS BIKES CADASTRADOS NO SISTEMA)

void listar_bikes(void) {
  FILE* fp;
  Bike* bike;
  printf("\n");
  bike = (Bike*) malloc(sizeof(Bike));
  fp = fopen("bikes.dat", "rb");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-50s", "TIPO DA BIKE");
  printf("|");
  printf("%-12s", "ARO DA BIKE");
  printf("|");
  printf("%-20s", "VALOR DO ALUGUEL");
  printf("|");
  printf("%-5s", "MARCA DA BIKE");
  printf("|");
  printf("%-15s", "CÓDIGO DA BIKE");
  printf("|");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->status != 'x') {
      printf("%-30s", bike->tipo);
      printf("|");
      printf("%-30s", bike->aro);
      printf("|");
      printf("%-30s", bike->valor_aluguel);
      printf("|");
      printf("%-30s", bike->marca);
      printf("|");
      printf("%-30s", bike->cod);
      printf("|");
      printf("\n");
    }
  }
  fclose(fp);
  free(bike);
}



// // ////OPÇÃO CASE 3 (LISTA TODAS AS PROMOÇÕES CADASTRADAS NO SISTEMA)

void listar_promo(void) {
  FILE* fp;
  Promo* promo;
  printf("\n");
  promo = (Promo*) malloc(sizeof(Promo));
  fp = fopen("promo.dat", "rb");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-40s", "ANÚNCIO");
  printf("|");
  printf("%-5s", "VALIDADE");
  printf("|");
  printf("%-5s", "CÓDIGO");
  printf("|");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(promo, sizeof(Promo), 1, fp)) { 
    if (promo->status != 'x') {
      printf("%-30s", promo->anuncio);
      printf("|");
      printf("%-30s", promo->val);
      printf("|");
      printf("%-30s", promo->cod);
      printf("|");
      printf("\n");
    }
  }
  fclose(fp);
  free(promo);
}




// // ////OPÇÃO CASE 4 (LISTA TODAS OS ALUGUÉIS CADASTRADOS NO SISTEMA)

void listar_aluguel(void) {
  FILE* fp;
  Aluguel* aluga;
  printf("\n");
  aluga = (Aluguel*) malloc(sizeof(Aluguel));
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-40s", "CÓDIGO DO ALUGUEL");
  printf("|");
  printf("%-5s", "CÓDIGO DA BIKE");
  printf("|");
  printf("%-5s", "TEMPO DE ALUGUEL");
  printf("|");
  printf("%-5s", "CPF DO CLIENTE");
  printf("|");
  printf("%-5s", "VALOR");
  printf("|");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(aluga, sizeof(Aluguel), 1, fp)) { 
    if (aluga->status != 'x') {
      printf("%-30s", aluga->cod_aluguel);
      printf("|");
      printf("%-30s", aluga->cod_bike);
      printf("|");
      printf("%-30s", aluga->tempo);
      printf("|");
      printf("%-30s", aluga->cpf);
      printf("|");
      printf("%-30s", aluga->valor);
      printf("|");
      printf("\n");
    }
  }
  fclose(fp);
  free(aluga);
}








