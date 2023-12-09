

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>
#include "relatorios.h"
#include "aluguel.h"
#include "bike.h"
#include "cliente.h"






/// OP��ES PARA MENU RELAT�RIOS 

void modulo_relatorio (void) {

  char opcao1;
  char opcao2;
  do {
      opcao1 = relatorios();
      switch(opcao1) {
            case '1':  
              do{
                opcao2 = listar_clientes();
                switch (opcao2){
                  case '1': clientes_cadastrados();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                  case '2': clientes_ex();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                } 
              } while (opcao2 != '0');
              break;
            case '2':
              do{
                opcao2 = listar_bikes();
                switch (opcao2){
                  case '1': bikes_cadastradas();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                  case '2': bikes_ex();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();

                }
              } while (opcao2 != '0');
              break;

          
            case '3': 
              do {
                opcao2 = listar_aluguel();
                switch (opcao2){
                  case '1': aluguel_cadastrado();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                  case '2': aluguel_ex();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;

                }
                      
    
              }while (opcao2 !='0');
              break;

    } 
  } while (opcao1 != '0');
}

//MENU RELAT�RIOS

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
    printf(" 3. LISTAR ALUGU�IS----------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c",&esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}







// // ////OP��O CASE 1 (RELAT�RIOS DO M�DULO CLIENTES)


char listar_clientes(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. CLIENTES CADASTRADOS ----------------DIGITE 1\n");
    printf(" 2. CLIENTES EXCLU�DOS--------------------DIGITE 2\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c",&esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}




// // ////OP??O CASE 2 (RELAT�RIOS DO M�DULO BIKES)

char listar_bikes(void) {
  setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. BIKES CADASTRADAS -------------------DIGITE 1\n");
    printf(" 2. BIKES EXCLU�DAS----------------------DIGITE 2\n");
    // printf(" 3. EDITAR CADASTRO----------------------DIGITE 3\n");
    // printf(" 4. EXCLUIR CADASTRO---------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op??o: ");
    scanf("%c",&esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
 
}





// // ////OP??O CASE 3 (RELAT�RIOS DO M�DULO ALUGUEL)

char listar_aluguel(void) {
   setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. ALUGUEIS CADASTRADOS ----------------DIGITE 1\n");
    printf(" 2. ALUGUEIS EXCLUIDOS-------------------DIGITE 2\n");
    // printf(" 3. EDITAR CADASTRO----------------------DIGITE 3\n");
    // printf(" 4. EXCLUIR CADASTRO---------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op??o: ");
    scanf("%c",&esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
 
}


// RELAT�RIO DE CLIENTES CADASTRADOS

void clientes_cadastrados (void) {

  FILE* fp;
  Cliente* cli;
  printf("\n");
  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    printf("N?o foi poss?vel abrir o arquivo!\n");
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


//RELAT�RIO DE CLIENTES EXCLU�DOS

void clientes_ex (void) {

  FILE* fp;
  Cliente* cli;
  printf("\n");
  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    printf("N?o foi poss?vel abrir o arquivo!\n");
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
    if (cli->status == 'x') {
      printf("%-25s", cli->nome);
      printf("%-25s", cli->cpf);
      printf("%-15s", cli->tel);
      printf("%-20s", cli->email);      
    }
  }
  fclose(fp);
  free(cli);
}



//RELAT�RIO DE BIKES CADASTRADAS

void bikes_cadastradas (void){

 FILE* fp;
  Bike* bike;
  printf("\n");
  bike = (Bike*) malloc(sizeof(Bike));
  fp = fopen("bikes.dat", "rb");
  if (fp == NULL) {
    printf("N?o foi poss?vel abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-10s", "TIPO");
  printf("|");
  printf("%-10s", "ARO");
  printf("|");
  printf("%-15s", "VALOR");
  printf("|");
  printf("%-20s", "MARCA");
  printf("|");
  printf("%-10s", "C?DIGO");
  printf("|");
  printf("\n");
  printf("\n");
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->status != 'x') {
      printf("%-10d", bike->tipo);
      printf("%-10s", bike->aro);
      printf("%20.2f", bike->valor_aluguel);
      printf("%17s", bike->marca);
      printf("%64s", bike->cod);
      printf("\n");
    }
  }
  fclose(fp);
  free(bike);
}


//RELAT�RIO DE BIKES EXCLU�DAS

void bikes_ex (void){

 FILE* fp;
  Bike* bike;
  printf("\n");
  bike = (Bike*) malloc(sizeof(Bike));
  fp = fopen("bikes.dat", "rb");
  if (fp == NULL) {
    printf("N?o foi poss?vel abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-10s", "TIPO");
  printf("|");
  printf("%-10s", "ARO");
  printf("|");
  printf("%-15s", "VALOR");
  printf("|");
  printf("%-20s", "MARCA");
  printf("|");
  printf("%-10s", "C?DIGO");
  printf("|");
  printf("\n");
  printf("\n");
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->status == 'x') {
      printf("%-10d", bike->tipo);
      printf("%-10s", bike->aro);
      printf("%20.2f", bike->valor_aluguel);
      printf("%17s", bike->marca);
      printf("%64s", bike->cod);
      printf("\n");
    }
  }
  fclose(fp);
  free(bike);
}



//RELAT�RIO DE ALUGU�IS CADASTRADOS

void aluguel_cadastrado (void){

FILE* fp;
  Aluguel* aluga;
  printf("\n");
  aluga = (Aluguel*) malloc(sizeof(Aluguel));
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
    printf("N?o foi poss?vel abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-40s", "C?DIGO DO ALUGUEL");
  printf("|");
  printf("%-5s", "C?DIGO DA BIKE");
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


//RELAT�RIO DE ALUGU�IS EXCLU�DOS

void aluguel_ex (void){

FILE* fp;
  Aluguel* aluga;
  printf("\n");
  aluga = (Aluguel*) malloc(sizeof(Aluguel));
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
    printf("N?o foi poss?vel abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-40s", "C?DIGO DO ALUGUEL");
  printf("|");
  printf("%-5s", "C?DIGO DA BIKE");
  printf("|");
  printf("%-5s", "VALOR");
  printf("|");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(aluga, sizeof(Aluguel), 1, fp)) { 
    if (aluga->status == 'x') {
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
