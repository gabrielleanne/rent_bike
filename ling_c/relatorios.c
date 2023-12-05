

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>
#include "relatorios.h"
#include "aluguel.h"
#include "bike.h"
#include "cliente.h"






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
             case '3':  listar_aluguel();
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
    printf(" 3. LISTAR ALUGUÉIS----------------------DIGITE 4\n");
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
  printf("%-20s", "NOME");
  printf("|");
  printf("%-20s", "CPF");
  printf("|");
  printf("%-20s", "TELEFONE");
  printf("|");
  printf("%-20s", "E-MAIL");
  printf("|");
  printf("\n");
  printf("\n");
  while (fread(cli, sizeof(Cliente), 1, fp)) { 
    if (cli->status != 'x') {
      printf("%-25s", cli->nome);
      printf("%-25s", cli->cpf);
      printf("%-15s", cli->tel);
      printf("%-20s", cli->email);      
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
  printf("%-7s", "TIPO DA BIKE");
  printf("|");
  printf("%-7s", "ARO");
  printf("|");
  printf("%-18f", "VALOR ALUGUEL");
  printf("|");
  printf("%-15s", "MARCA");
  printf("|");
  printf("%-15s", "CÓDIGO BIKE");
  printf("|");
  printf("\n");
  // printf("%8s", "|");
  // printf("%31s", "|");
  printf("\n");
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->status != 'x') {
      printf("%-30s", bike->tipo);
      printf("|");
      printf("%-30s", bike->aro);
      printf("|");
      printf("%-30f", bike->valor_aluguel);
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





// // ////OPÇÃO CASE 3 (LISTA TODAS OS ALUGUÉIS CADASTRADOS NO SISTEMA)

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
     // printf("%-30d", aluga->tempo);
      printf("|");
      printf("%-30s", aluga->cpf);
      printf("|");
      printf("%-30f", aluga->valor);
      printf("|");
      printf("\n");
    }
  }
  fclose(fp);
  free(aluga);
}








