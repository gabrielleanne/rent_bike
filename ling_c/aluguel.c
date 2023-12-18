
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include<string.h>
#include"aluguel.h"
#include"bike.h"
#include"cliente.h"
#include<time.h>
#include"valid.h"



 
void baixa_aluguel(Bike *bike);



////OPÇÕES PARA MENU ALUGUEL


void modulo_aluguel (void) {

   Aluguel* aluga;
   Bike bike;
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
            case '4': 	baixa_aluguel(&bike);
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
    printf(" 4. BAIXA EM ALUGUEL---------------------DIGITE 4\n");
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

//////ESCOLHA DA OPÇÃO CASE 1 (CADASTRA NOVO ALUGUEL NO SISTEMA)

Aluguel* novo_aluguel(void) {



    Aluguel* aluga;
    aluga = (Aluguel*) malloc(sizeof(Aluguel));
    int dd, mm, yy;
    char y;
    char cod[9];
    int tam;
    char* x;
    
    
    
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
    
    do {
      printf("Código da bike desejada:\n");
      scanf("%s", cod);
      getchar();
      y=check_bike(cod);
     
    } while ((y != 'c')); 
    strcpy(aluga->cod_bike, cod);
    printf("CPF do cliente (somente números):\n");
	  fgets(aluga->cpf,14 ,stdin);
    tam = strlen(aluga->cpf);
    aluga->cpf[tam-1] = '\0';
    getchar();
    while (!valida_cpf (aluga->cpf)) {
      printf("Cpf digitado não é válido!\n");
      printf("Informe o cpf novamente (somente números):\n ");
      fgets(aluga->cpf, 14, stdin);
      tam = strlen(aluga->cpf);
      aluga->cpf[tam-1] = '\0';
      getchar();
    }
    x=codi();
    strcpy(aluga->cod_aluguel, x);
    printf("Código do aluguel: %s\n", aluga->cod_aluguel);
    printf("Tempo de aluguel (em horas): \n");
    scanf("%d",&aluga->tempo);
    getchar();
    printf("Digite a data do aluguel (dd/mm/yyyy): \n");
    fgets(aluga->data,12,stdin);
    tam = strlen(aluga->data);
    aluga->data[tam-1] = '\0';
    getchar();
    sscanf(aluga->data, "%d/%d/%d", &dd, &mm, &yy);
    getchar();
    while (!valida_data (dd, mm, yy)) {
      printf("Data digitada não é válida!\n");
      printf("Informe a data novamente:\n ");
      fgets(aluga->data, 12, stdin);
      tam = strlen(aluga->data);
      aluga->data[tam-1] = '\0';
      getchar();
    }
    aluga->valor = valor_aluguel(aluga->tempo);
    aluga->status= 'c';
    aluga->vigencia= 's';
    disponibilidade_n(aluga->cod_bike); // Marca a bike como indisponível
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return aluga;
}




//FUNÇÃO GERA CÓDIGO DO ALUGUEL BASEADO EM HORA LOCAL

char* codi (void) {

  time_t segundos;
  time(&segundos);
  struct tm *codigo = localtime(&segundos);
  char* tempo = (char*)malloc(9 * sizeof(char)); 
  sprintf(tempo, "%02d%02d%02d", codigo->tm_hour, codigo->tm_min, codigo->tm_sec);
  return tempo; 
  free (tempo);
}


/// FUNÇÃO GRAVA ALUGUEL NO SISTEMA


void gravar_aluguel(Aluguel* aluga) {
  FILE* fp;
  fp = fopen("aluguel.dat", "ab");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    exit(1);
  }
  fwrite(aluga, sizeof(Aluguel), 1, fp);
  fclose(fp);
}



///ESCOLHA DA OPÇÃO CASE 2 (BUSCAR ALUGUEL DE BIKE PELO CPF DO CLIENTE)

Aluguel* buscar_aluguel(void) {

  Aluguel* aluga;
	char* cod;
  cod=cod_aluguel();
	FILE* fp;
	aluga = (Aluguel*) malloc(sizeof(Aluguel));
	fp = fopen("aluguel.dat", "rb");
	if (fp == NULL) {
		printf("Não foi possível abrir o arquivo!");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
	}
	while(fread(aluga, sizeof(Aluguel), 1, fp)) {
		if ((strcmp(aluga->cod_aluguel, cod) == 0)) {
			return aluga;
		}
	}
	fclose(fp);
	return NULL;
  
}


///// FUNÇÃO QUE EXIBE ALUGUEL NA TELA

void print_aluguel(Aluguel* aluga) {
  if ((aluga == NULL)) {
    printf("\nAluguel não existe!\n");
  } else {
      printf("Código da bike: %s\n", aluga->cod_bike);
      printf("Código do aluguel: %s\n", aluga->cod_aluguel);
      printf("Data do aluguel: %s\n", aluga->data);
      printf("Tempo de aluguel: %d horas\n", aluga->tempo);
      printf("CPF do cliente: %s\n", aluga->cpf);
      printf("Valor: %.2f\n", aluga->valor);
      printf("Status: %c\n", aluga->status);
      printf("Aluguel vigente?: %c\n", aluga->vigencia);
  } 
}


//FUNÇÃO QUE LÊ CÓDIGO DO ALUGUEL

char* cod_aluguel(void) {

	char* cod;
  int tam;

	cod = (char*) malloc(9*sizeof(char));
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
	printf("Digite o código do aluguel: \n");
  printf("\n");
	fgets(cod,9,stdin);
  tam = strlen(cod);
  cod[tam-1] = '\0';
  getchar();
  return cod;
}



////ESCOLHA DA OPÇÃO CASE 3 (EXCLUIR ALUGUEL DE BIKE)


        
void excluir_aluguel(void) {

  char* cod;
  Aluguel* ex = (Aluguel*) malloc(sizeof(Aluguel));
  FILE* fp;
  int busca = 0;

  cod = cod_aluguel();
  fp= fopen("aluguel.dat", "r+b");
  if (fp==NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
  }
  else{  
    while (fread(ex, sizeof(Aluguel), 1, fp)) {
      if (strcmp(ex->cod_aluguel, cod)==0) {
        busca=1;
        ex->status='x'; 
        ex->vigencia='n';
        fseek(fp, (-1L)*sizeof(Aluguel), SEEK_CUR);
        fwrite(ex, sizeof(Aluguel), 1, fp);  
        printf("Aluguel excluído com sucesso!\n");
        break;
      }
    }
  } 
  if (!busca) {
    printf("Código de aluguel não encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}


//FUNÇÃO QUE DA BAIXA EM ALUGUEL;
       
void baixa_aluguel(Bike *bike) {


    Aluguel* aluga = (Aluguel*)malloc(sizeof(Aluguel));
    FILE* fp;
    char cod[9];
    int busca = 0;

    printf("Digite o código do aluguel a ser dado baixa:\n");
    scanf("%s", cod);
    getchar();

    fp = fopen("aluguel.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        printf("\n\nTecle ENTER para continuar!\n\n");
        getchar();
        free(aluga);
        return;
    }

    while (fread(aluga, sizeof(Aluguel), 1, fp)) {
        if (strcmp(cod, aluga->cod_aluguel) == 0) {
            busca = 1;
            aluga->vigencia = 'n';
            disponibilidade_s(aluga->cod_bike);
            fseek(fp, -sizeof(Aluguel), SEEK_CUR);
            fwrite(aluga, sizeof(Aluguel), 1, fp);
            printf("Baixa em aluguel com sucesso!\n");
            break;
        }
    }

    if (!busca) {
        printf("Código de aluguel não encontrado!\n");
    }

    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
    fclose(fp);
    free(aluga);
}





//FUNÇÃO QUE CALCULA O VALOR DO ALUGUEL

float valor_aluguel (int tempo){

  char bike;
  float valor;

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
  printf("\n");
  printf("O valor do aluguel será de : %.2f\n", valor);
  return valor;
}




void disponibilidade_n(char* cod) {
    FILE* arquivo = fopen("bikes.dat", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de bicicletas!\n");
        return;
    }

    Bike bike;

    while (fread(&bike, sizeof(Bike), 1, arquivo) == 1) {
        if (strcmp(bike.cod, cod) == 0) {
            bike.dispon = 'n'; // Marca a bike como indisponível
            fseek(arquivo, -sizeof(Bike), SEEK_CUR);
            fwrite(&bike, sizeof(Bike), 1, arquivo);
            fclose(arquivo);
            return;
        }
    }

    fclose(arquivo);
    printf("Bike não encontrada!\n");
    
}


void disponibilidade_s(const char* cod_bike) {
    FILE* fp;
    Bike* bike;

    fp = fopen("bikes.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo de bikes!\n");
        return;
    }

    bike = (Bike*)malloc(sizeof(Bike));
    while (fread(bike, sizeof(Bike), 1, fp) == 1) {
        if (strcmp(bike->cod, cod_bike) == 0) {
            // Atualiza o status da bike para disponível ('s')
            bike->dispon = 's';
            fseek(fp, -sizeof(Bike), SEEK_CUR);
            fwrite(bike, sizeof(Bike), 1, fp);
            break;
        }
    }

    fclose(fp);
    free(bike);
}