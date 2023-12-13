
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include<string.h>
#include"bike.h"
#include"valid.h"
#include"aluguel.h"


////OPÇÕES PARA MENU BIKES

void modulo_bike (void) {

   Bike* bike;
   char opcao;
    do {
        opcao = bikes();
        switch(opcao) {
            case '1': 	bike=cadastrar_bike();
                        gravar_bike(bike);
                        free(bike);
                        break;
            case '2': 	opcao_editar();
                        break;
            case '3': 	bike=buscar_bike();
                        print_bike(bike);
                        printf("\n\nTecle ENTER para continuar!\n\n");
	                    getchar();
                        free(bike);
                        break;
            case '4': 	excluir_bike();
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


////OPÇÃO CASE 1 (CADASTRA NOVA BIKE NO SISTEMA)

Bike* cadastrar_bike(void) {
    
    Bike* bike;
    bike = (Bike*) malloc(sizeof(Bike));
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
    printf("Tipo: \n");
    bike->tipo = tipo_bike();
    printf("Aro: \n");
    fgets(bike->aro,5,stdin);
    getchar();
    printf("Valor do aluguel:\n");
	scanf("%f", &bike->valor_aluguel);
    getchar();
    printf("Marca da bike:\n");
	fgets(bike->marca,20 ,stdin);
    getchar();
    printf("Código da bike:\n");
	fgets(bike->cod,6 ,stdin);
    getchar();
    bike->status= 'c';
    bike->dispon= 's';
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return bike;

}


/// FUNÇÃO GRAVA BIKE NO SISTEMA


void gravar_bike(Bike* bike) {
  FILE* fp;
  fp = fopen("bikes.dat", "ab");
  if (fp == NULL) {
    printf("Ocorreu um erro na abertura do arquivo!\n");
    exit(1);
  }
  fwrite(bike, sizeof(Bike), 1, fp);
  fclose(fp);
}


//FUNÇÃO LÊ O TIPO DE BIKE PARA CADASTRO

char tipo_bike(void) {
    char esc;
    printf(" 1. MOUNTAIN BIKE------------------------DIGITE 1\n");
    printf(" 2. BIKE ELÉTRICA------------------------DIGITE 2\n");
    printf(" 3. BIKE SPEED/ESTRADA-------------------DIGITE 3\n");
    printf(" 4. BIKE URBANA--------------------------DIGITE 4\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    if (esc ==1){
        printf("Mountain BIke");
    if (esc ==2){
        printf("Bike elétrica");
    if (esc==3){
        printf("Bike speed");
    if (esc==4){
        printf("Bike urbana");
    }
    }
    }
    }
    return esc;
}

////OPÇ~SO CASE 2 (OPÇÕES DE DADOS DAS BIKES PARA EDITAR)

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

// MENU EDITAR BIKE

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

/// FUNÇÃO LÊ CÓDIGO DA BIKE 

char* ler_cod_bike(void){
    char* cod;
    cod = (char*) malloc(6*sizeof(char));
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
	printf("Digite o código: \n");
	fgets(cod,6,stdin);
    getchar();
    return cod;
}


//FUNÇÃO PARA ALTERAR TIPO DE BIKE CADASTRADA

void altera_tipo(void) {
    char* cod;
    Bike* new = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;

    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cod=ler_cod_bike();
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Bike), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("Tipo: ");
                new->tipo=tipo_bike();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Código não existe!\n");
    }
    else {
      printf("Tipo de bike editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


//FUNÇÃO PARA ALTERAR ARO DE BIKE CADASTRADA

void altera_aro(void) {
    char* cod;
    Bike* new = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cod= ler_cod_bike();
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Bike), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("Aro: ");
                fgets(new->aro,5,stdin);
                getchar();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Código não existe!\n");
    }
    else {
      printf("Aro da bike editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}


//FUNÇÃO PARA ALTERAR VALOR DO ALUGUEL DE BIKE CADASTRADA


void altera_valor(void) {
    char* cod;
    Bike* new = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cod=ler_cod_bike();
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Bike), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("Valor do aluguel: \n");
                scanf("%f", &new->valor_aluguel);
                getchar();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Código não existe!\n");
    }
    else {
      printf("Valor do aluguel editado com sucesso!\n");
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


//FUNÇÃO PARA ALTERAR MARCA DE BIKE CADASTRADA


void altera_marca(void) {
    char* cod;
    Bike* new = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cod=ler_cod_bike();
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Bike), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("Marca: ");
                fgets(new->marca,20,stdin);
                getchar();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Código não existe!\n");
    }
    else {
      printf("Marca da bike editado com sucesso!\n");
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


/////OPÇÃO CASE 3 (BUSCA BIKE NO SISTEMA ATRAVÉS DO CÓDIGO DA BIKE)

Bike* buscar_bike(void) {
    Bike* bike;
	char* cod;
    cod=ler_cod_bike();
	FILE* fp;
	bike = (Bike*) malloc(sizeof(Bike));
	fp = fopen("bikes.dat", "rb");
	if (fp == NULL) {
		printf("Não foi possível abrir o arquivo!");
        printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
	}
	while(fread(bike, sizeof(Bike), 1, fp)) {
		if ((strcmp(bike->cod, cod) == 0) && (bike->status == 'c')) {
			return bike;
		}
	}
	fclose(fp);
	return NULL;
}


///// FUNÇÃO QUE EXIBE BIKE NA TELA

void print_bike(Bike* bike) {
  if ((bike == NULL) || (bike->status == 'x')) {
    printf("\nBike não existe!\n");
  } else {
    printf("Tipo: %c\n", bike->tipo);
    printf("Aro: %s\n", bike->aro);
    printf("Valor do aluguel: %.2f\n", bike->valor_aluguel);
    printf("Marca: %s\n", bike->marca);
    printf("Código: %s\n", bike->cod); 
    printf("Disponível? %c\n", bike->dispon);  
  } 
}

///  CASE 4 (EXCLUI BIKE CADASTRADA DO SISTEMA ATRAVÉS DO CÓDIGO DA BIKE)

  
void excluir_bike(void) {
    char* cod;
    Bike* ex = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;

    cod=ler_cod_bike();
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
        printf("Não foi possível abrir o arquivo!");
        printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else{
        while (!feof(fp)) {
        fread(ex, sizeof(Bike), 1, fp);    
        if (strcmp(ex->cod, cod)==0) {
            busca=1;
            ex->status='x'; 
            fseek(fp, -sizeof(Bike), SEEK_CUR);
            fwrite(ex, sizeof(Bike), 1, fp);  
            printf("Bike excluída com sucesso!\n");
            break;
        }
        }
    } 
  if (!busca) {
    printf("Código não encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}


char disponibilidade (char* cod) {
  Aluguel* aluga;
  char disp;
  FILE* fp = fopen("aluguel.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  aluga = (Aluguel*) malloc(sizeof(Aluguel));
  while (fread(aluga, sizeof(Aluguel), 1, fp) == 1) {
    if (strcmp(aluga->cod_bike, cod)==0){
      disp = 'n';
      fclose(fp);
      free(aluga);
      return disp;
    }
    else{
      disp='s';
      fclose(fp);
      free(aluga);
      return disp;
    }
  }
  fclose(fp);
  free(aluga);
  return 'n';
}