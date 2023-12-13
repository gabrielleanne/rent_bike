

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>
#include "relatorios.h"
#include "aluguel.h"
#include "bike.h"
#include "cliente.h"


void aluguel_cpf(Aluguel*);

/// OPÇÕES PARA MENU RELATÓRIOS 

void modulo_relatorio (void) {

  char opcao1;
  char opcao2;
  Aluguel* aluga;

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
                  case '3': clientes_ord();
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
                  case '3': bikes_dispon();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                  case '4': bikes_alug();
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
                  case '1': aluguel_vigente();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                  case '2': aluguel_ex();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                  case '3': aluguel_cpf(aluga);
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                  case '4': aluguel_term();
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
    printf(" 3. LISTAR ALUGUÉIS----------------------DIGITE 3\n");
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



// // ////OPÇÃO CASE 1 (RELATÓRIOS DO MÓDULO CLIENTES)


char listar_clientes(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. CLIENTES CADASTRADOS ----------------DIGITE 1\n");
    printf(" 2. CLIENTES EXCLUÍDOS-------------------DIGITE 2\n");
    printf(" 3. CLIENTES EM ORDEM--------------------DIGITE 2\n");
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




// // ////OPÇÃO CASE 2 (RELATÓRIOS DO MÓDULO BIKES)

char listar_bikes(void) {
  setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. BIKES CADASTRADAS -------------------DIGITE 1\n");
    printf(" 2. BIKES EXCLUÍDAS----------------------DIGITE 2\n");
    printf(" 3. BIKES DISPONIVEIS -------------------DIGITE 3\n");
    printf(" 4. BIKES ALUGADAS ----------------------DIGITE 4\n");
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





// // ////OPÇÃO CASE 3 (RELATÓRIOS DO MÓDULO ALUGUEL)

char listar_aluguel(void) {
   setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. ALUGUEIS VIGENTES--------------------DIGITE 1\n");
    printf(" 2. ALUGUEIS EXCLUIDOS-------------------DIGITE 2\n");
    printf(" 3. ALUGUEIS POR CPF---------------------DIGITE 3\n");
    printf(" 4. ALUGUEIS TERMINADOS------------------DIGITE 1\n");
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


// RELATÓRIO DE CLIENTES CADASTRADOS

void clientes_cadastrados (void) {

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
  
  while (fread(cli, sizeof(Cliente), 1, fp)) { 
    if (cli->status != 'x') {
      printf("Nome: %s\n", cli->nome);
      printf("CPF: %s\n", cli->cpf);
      printf("Email: %s\n", cli->email);
      printf("Logradouro: %s\n", cli->log);
      printf("Número: %s\n", cli->num);
      printf("Bairro: %s\n", cli->bai);
      printf("Email: %s\n", cli->email);
      printf("Status: %c\n", cli->status);

    }
  }
  fclose(fp);
  free(cli);
}


//RELATÓRIO DE CLIENTES EXCLUÍDOS

void clientes_ex (void) {

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
  while (fread(cli, sizeof(Cliente), 1, fp)) { 
    if (cli->status == 'x') {
      printf("Nome: %s\n", cli->nome);
      printf("CPF: %s\n", cli->cpf);
      printf("Email: %s\n", cli->email);
      printf("Logradouro: %s\n", cli->log);
      printf("Número: %s\n", cli->num);
      printf("Bairro: %s\n", cli->bai);
      printf("Email: %s\n", cli->email);
      printf("Status: %c\n", cli->status);
    }
  }  
  fclose(fp);
  free(cli);

}

// RELATÓRIO DE CLIENTES EM ORDEM ALFABÉTICA

void clientes_ord(void) {
  system("clear||cls");
  FILE* fp = fopen("clientes.dat", "rb");
  Cliente* prox_cli;
  Cliente* lista;

  if (fp == NULL) {
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  lista = NULL;
  prox_cli = (Cliente*)malloc(sizeof(Cliente));

  if (prox_cli == NULL) {
    printf("\t\t\t>>> Houve um erro ao alocar a memória!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }

  while(fread(prox_cli, sizeof(Cliente), 1, fp) == 1) {
    prox_cli->prox = NULL;

    if ((lista == NULL) || (strcmp(prox_cli->nome, lista->nome) < 0)) {
      prox_cli->prox = lista;
      lista = prox_cli;
    } else {
      Cliente* antigo = lista;
      Cliente* atual = lista->prox;
      while ((atual != NULL) && strcmp(atual->nome, prox_cli->nome) < 0) {
        antigo = atual;
        atual = atual->prox;
      }
      antigo->prox = prox_cli;
      prox_cli->prox = atual;
    }
    prox_cli = (Cliente*)malloc(sizeof(Cliente));
    if(prox_cli == NULL) {
      printf("\t\t\t>>> Houve um erro ao alocar a memória!\n");
      printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
      getchar();
    }
  }
  fclose(fp);
  prox_cli = lista;
  while(prox_cli != NULL) {
    printf("Nome: %s\n", prox_cli->nome);
    printf("CPF: %s\n", prox_cli->cpf);
    printf("Email: %s\n", prox_cli->email);
    printf("Logradouro: %s\n", prox_cli->log);
    printf("Número: %s\n", prox_cli->num);
    printf("Bairro: %s\n", prox_cli->bai);
    printf("Email: %s\n", prox_cli->email);
    printf("Status: %c\n", prox_cli->status);
    prox_cli = prox_cli->prox;
  }
  prox_cli = lista;
  while (lista != NULL) {
    lista = lista->prox;
    free(prox_cli);
    prox_cli = lista;
  }
}



//RELATÓRIO DE BIKES CADASTRADAS

void bikes_cadastradas (void){

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
 
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->status != 'x') {
    printf("Tipo: %c\n", bike->tipo);
    printf("Aro: %s\n", bike->aro);
    printf("Valor do aluguel: %.2f\n", bike->valor_aluguel);
    printf("Marca: %s\n", bike->marca);
    printf("Código: %s\n", bike->cod);  
    printf("Disponível? %c\n", bike->dispon);
    }
  }  

  fclose(fp);
  free(bike);
}


//RELATÓRIO DE BIKES EXCLUÍDAS

void bikes_ex (void){

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
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->status == 'x') {
    printf("Tipo: %c\n", bike->tipo);
    printf("Aro: %s\n", bike->aro);
    printf("Valor do aluguel: %.2f\n", bike->valor_aluguel);
    printf("Marca: %s\n", bike->marca);
    printf("Código: %s\n", bike->cod);  
    printf("Disponível? %c\n", bike->dispon);
    }
  } 

  fclose(fp);
  free(bike);
}


void bikes_dispon (void){

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
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->dispon == 's') {
    printf("Tipo: %c\n", bike->tipo);
    printf("Aro: %s\n", bike->aro);
    printf("Valor do aluguel: %.2f\n", bike->valor_aluguel);
    printf("Marca: %s\n", bike->marca);
    printf("Código: %s\n", bike->cod);  
    printf("Disponível? %c\n", bike->dispon);
    }
  } 

  fclose(fp);
  free(bike);
}



void bikes_alug (void){

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
  while (fread(bike, sizeof(Bike), 1, fp)) { 
    if (bike->dispon == 'n') {
    printf("Tipo: %c\n", bike->tipo);
    printf("Aro: %s\n", bike->aro);
    printf("Valor do aluguel: %.2f\n", bike->valor_aluguel);
    printf("Marca: %s\n", bike->marca);
    printf("Código: %s\n", bike->cod);  
    printf("Disponível? %c\n", bike->dispon);
    }
  } 

  fclose(fp);
  free(bike);
}


//RELATÓRIO DE ALUGUÉIS CADASTRADOS

void aluguel_vigente (void){

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
  while (fread(aluga, sizeof(Aluguel), 1, fp)) { 
    if ((aluga->status != 'x')&&(aluga->vigencia=='s')) {
      printf("Código da bike: %s\n", aluga->cod_bike);
      printf("Código do aluguel: %s\n", aluga->cod_aluguel);
      printf("Cpf do cliente: %s\n", aluga->cpf);
      //printf("Valor do lauguel: %.2f\n", aluga->valor);
      printf("Data: %s\n", aluga->data);
      printf("Status: %c\n", aluga->status);
      printf("\n");
    }
  }
  fclose(fp);
  free(aluga);
}


//RELATÓRIO DE ALUGUEIS TERMINADOS

void aluguel_term (void){

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
  while (fread(aluga, sizeof(Aluguel), 1, fp)) { 
    if ((aluga->status != 'x')&&(aluga->vigencia=='n')) {
      printf("Código da bike: %s\n", aluga->cod_bike);
      printf("Código do aluguel: %s\n", aluga->cod_aluguel);
      printf("Cpf do cliente: %s\n", aluga->cpf);
      printf("Valor do aluguel: %.2f\n", aluga->valor);
      printf("Data: %s\n", aluga->data);
      printf("Status: %c\n", aluga->status);
      printf("\n");
    }
  }
  fclose(fp);
  free(aluga);
}



//RELATÓRIO DE ALUGUÉIS EXCLUÍDOS

void aluguel_ex (void){

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
   while (fread(aluga, sizeof(Aluguel), 1, fp)) { 
    if ((aluga->status != 'x')&&(aluga->vigencia=='n')) {
      printf("Código da bike: %s\n", aluga->cod_bike);
      printf("Código do aluguel: %s\n", aluga->cod_aluguel);
      printf("Cpf do cliente: %s\n", aluga->cpf);
      //printf("Valor do lauguel: %.2f\n", aluga->valor);
      printf("Data: %s\n", aluga->data);
      printf("Status: %c\n", aluga->status);
      printf("\n");
    }
  }

  fclose(fp);
  free(aluga);
}


//RELATÓRIO DE ALUGUEIS POR CPF

void aluguel_cpf(Aluguel* aluga) {

  char *nome_cli;
  char qual_bike;
  char* cpf;
  FILE* fp;
  system("clear||cls");
  cpf=ler_cpf();
  fgets (cpf, 12, stdin);
  getchar();
  aluga = (Aluguel*) malloc(sizeof(Aluguel));
  printf("\n");
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while(fread(aluga, sizeof(Aluguel), 1, fp) == 1) {
    if (strcmp(aluga->cpf, cpf) == 0) {
      nome_cli = nome_pull(cpf);
      qual_bike = bike_pull();
      printf("Nome do cliente: %s\n",nome_cli);
      printf("CPF: %s\n",aluga->cpf);
      printf("Tipo da bike: \n", qual_bike);
      printf("Data do aluguel: %s\n",aluga->data);
      printf("Valor do aluguel: %.2f\n", aluga->valor);
      printf("Tempo de locação: %d\n",aluga->tempo);

    }
  }
  fclose(fp);
  free(aluga);
}



//FUNÇÃO QUE CAPTURA NOME DO CLIENTE

char *nome_pull(const char *cpf) {
  Cliente cli;
  FILE* fp = fopen("clientes.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(&cli, sizeof(cli), 1, fp) == 1) {
    if(strcmp(cli.cpf, cpf) == 0) {
      char *x = (char *)malloc(strlen(cli.nome) + 1);
      if (x == NULL) {
        printf("Ocorreu um erro.\n");
        fclose(fp);
        return NULL;
      }
      strcpy(x, cli.nome);
      fclose(fp);
      return x;
    }
  }
  fclose(fp);
  return NULL;
}


//FUNÇÃO QUE CAPTURA TIPO DE BIKE

char bike_pull(void) {
  Bike* bike;
  char tipo;
  FILE* fp = fopen("bikes.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  bike = (Bike*) malloc(sizeof(Bike));
  while (fread(bike, sizeof(Bike), 1, fp) == 1) {
    if (bike->tipo == tipo) {
      tipo = bike->tipo;
      fclose(fp);
      free(bike);
      return tipo;
    }
  }
  fclose(fp);
  free(bike);
  return 0;
}
