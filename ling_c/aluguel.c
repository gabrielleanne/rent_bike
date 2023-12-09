
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"aluguel.h"
#include"bike.h"
#include"cliente.h"
#include<time.h>





////OP��ES PARA MENU ALUGUEL


void modulo_aluguel (void) {

   Aluguel* aluga;
   char opcao;
    do {
        opcao = aluguel();
        switch(opcao) {
            case '1': 	aluga=novo_aluguel();
                        gravar_aluguel(aluga);
                        free(aluga);
                        break;
            case '2': 	aluga=buscar_aluguel();
                        print_aluguel(aluga);
                        printf("\n\nTecle ENTER para continuar!\n\n");
	                      getchar();
                        free(aluga);
                        break;
            case '3': 	excluir_aluguel();
                        break;
            
        } 		
    } while (opcao != '0');
}


////MENU ALUGUEL DE BIKES

char aluguel(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. NOVO ALUGUEL-------------------------DIGITE 1\n");
    printf(" 2. BUSCAR ALUGUEL-----------------------DIGITE 2\n");
    printf(" 3. EXCLUIR ALUGUEL----------------------DIGITE 3\n");
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

//////ESCOLHA DA OP��O CASE 1 (CADASTRA NOVO ALUGUEL NO SISTEMA)

Aluguel* novo_aluguel(void) {

    Aluguel* aluga;
    aluga = (Aluguel*) malloc(sizeof(Aluguel));
    int dd, mm, yy;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("Vamos cadastrar um novo aluguel no sistema!\n");
    printf("\n");
    printf("\n");
    printf("CPF do cliente (somente n�meros):\n");
	  fgets(aluga->cpf,12 ,stdin);
    getchar();
    while (!valida_cpf (aluga->cpf)) {
        printf("Cpf digitado n�o � v�lido!\n");
        printf("Informe o cpf novamente (somente n�meros):\n ");
        fgets(aluga->cpf, 12, stdin);
        getchar();
    }
    printf("C�digo da bike: \n");
    fgets(aluga->cod_bike,4,stdin);
    getchar();
    printf("C�digo do aluguel: \n");
    fgets(aluga->cod_aluguel,4,stdin);
    getchar();
    printf("Tempo de aluguel (em horas): \n");
    scanf("%d", &aluga->tempo);
    getchar();
    printf("Digite a data do aluguel (dd/mm/yyyy): \n");
    fgets(aluga->data,11,stdin);
    getchar();
    sscanf(aluga->data, "%d/%d/%d", &dd, &mm, &yy);
    getchar();
     while (!valida_data (dd, mm, yy)) {
        printf("Data digitada n�o � v�lida!\n");
        printf("Informe a data novamente:\n ");
        fgets(aluga->data, 11, stdin);
        getchar();
    }
    aluga->valor=valor_aluguel();
    aluga->status= 'c';
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return aluga;
}




/// FUN��O GRAVA ALUGUEL NO SISTEMA


void gravar_aluguel(Aluguel* aluga) {
  FILE* fp;
  fp = fopen("aluguel.dat", "ab");
  if (fp == NULL) {
    printf("N�o foi poss�vel abrir o arquivo!\n");
    exit(1);
  }
  fwrite(aluga, sizeof(Aluguel), 1, fp);
  fclose(fp);
}



///ESCOLHA DA OP��O CASE 2 (BUSCAR ALUGUEL DE BIKE PELO CPF DO CLIENTE)

Aluguel* buscar_aluguel(void) {

  Aluguel* aluga;
  char* cpf;
  cpf=ler_cpf();
	FILE* fp;
	aluga = (Aluguel*) malloc(sizeof(Aluguel));
	fp = fopen("aluguel.dat", "rb");
	if (fp == NULL) {
		printf("N�o foi poss�vel abrir o arquivo!");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
	}
	while(fread(aluga, sizeof(Aluguel), 1, fp)) {
		if ((strcmp(aluga->cpf, cpf) == 0) && (aluga->status == 'c')) {
			return aluga;
		}
	}
	fclose(fp);
	return NULL;
  printf("\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  
}


///// FUN��O QUE EXIBE ALUGUEL NA TELA

void print_aluguel(Aluguel* aluga) {
  if ((aluga == NULL) || (aluga->status == 'x')) {
    printf("\nAluguel n�o existe!\n");
  } else {
      printf("C�digo da bike: %s\n", aluga->cod_bike);
      printf("C�digo do aluguel: %s\n", aluga->cod_aluguel);
      printf("Data do aluguel: %s\n", aluga->data);
      printf("Tempo de aluguel: %d\n", aluga->tempo);
      printf("CPF do cliente: %s\n", aluga->cpf);
      printf("Valor: %f\n", aluga->valor);
      printf("Status: %c\n", aluga->status);
  } 
}


//FUN��O QUE L� C�DIGO DO ALUGUEL

char* cod_aluguel(void) {

	char* cod_aluguel;

	cod_aluguel = (char*) malloc(12*sizeof(char));
	printf("\n");
	system("clear||cls");
  printf("\n");
  printf("-------------------------------------------------\n");
  printf("*******************RENT A BIKE*******************\n");
  printf("-------------------------------------------------\n");
  printf("-------------------MENU BIKES--------------------\n");
  printf("-------------------------------------------------\n");
  printf("\n");
  printf("\n");
	printf("Digite o c�digo do aluguel: \n");
  printf("\n");
	fgets(cod_aluguel,4,stdin);
  getchar();
  return cod_aluguel;
}



////ESCOLHA DA OP��O CASE 3 (EXCLUIR ALUGUEL DE BIKE)


        
void excluir_aluguel(void) {

  char* cod;
  Aluguel* ex = (Aluguel*) malloc(sizeof(Aluguel));
  FILE* fp;
  int busca = 0;

  cod = cod_aluguel();
  fp= fopen("aluguel.dat", "r+b");
  if (fp==NULL) {
    printf("N�o foi poss�vel abrir o arquivo!\n");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
  }
  else{  
    while (fread(ex, sizeof(Aluguel), 1, fp)) {
      if (strcmp(ex->cod_aluguel, cod)==0) {
        busca=1;
        ex->status='x'; 
        fseek(fp, (-1L)*sizeof(Aluguel), SEEK_CUR);
        fwrite(ex, sizeof(Aluguel), 1, fp);  
        printf("Aluguel exclu�do com sucesso!\n");
        break;
      }
    }
  } 
  if (!busca) {
    printf("C�digo de aluguel n�o encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}


//FUN��O QUE CALCULA O VALOR DO ALUGUEL

float valor_aluguel (void){

  char bike;
  int tempo;
  float valor;
  
  printf("\n");
  printf("O aluguel ser? por quantas horas?\n");
  scanf("%d", &tempo);
  getchar();
  printf("\n");
  bike=tipo_bike();
  if (bike=='1'){
    valor= 20*tempo;   
  }
  if (bike=='2'){
    valor = 25*tempo;
  }
  if (bike=='3'){
    valor = 30*tempo;
  }
  if (bike=='4'){
    valor= 35*tempo;
  }
  printf("Valor do aluguel: %.2f", valor);
  printf("\n");
  return valor;
}

