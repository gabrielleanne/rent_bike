
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include<string.h>
#include"bike.h"
#include"valid.h"


////OP??ES PARA MENU BIKES

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
    printf("Escolha sua op??o: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}


////OP??O CASE 1 (CADASTRA NOVA BIKE NO SISTEMA)

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
    getchar();
    printf("Aro: \n");
    fgets(bike->aro,5,stdin);
    getchar();
    printf("Valor do aluguel:\n");
	scanf("%.2f", &bike->valor_aluguel);
    getchar();
    printf("Marca da bike:\n");
	fgets(bike->marca,20 ,stdin);
    getchar();
    printf("C?digo da bike:\n");
	fgets(bike->cod,6 ,stdin);
    getchar();
    bike->status= 'c';
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return bike;

}


/// FUN??O GRAVA BIKE NO SISTEMA


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

char tipo_bike(void) {
    char esc;
    printf(" 1. MOUNTAIN BIKE------------------------DIGITE 1\n");
    printf(" 2. BIKE EL?TRICA------------------------DIGITE 2\n");
    printf(" 3. BIKE SPEED/ESTRADA-------------------DIGITE 3\n");
    printf(" 4. BIKE URBANA--------------------------DIGITE 4\n");
    printf("\n");
    printf("Escolha sua op??o: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    return esc;
}

////OP??O CASE 2 (OP??ES DE DADOS DAS BIKES PARA EDITAR)

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
    printf("Escolha sua op??o: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

/// FUN??O SOLICITA C?DIGO DA BIKE PARA BUSCA

void ler_cod_bike(char* cod) {
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
	printf("Digite o c?digo: \n");
	fgets(cod,6,stdin);
    getchar();
}


//FUN??O PARA ALTERAR TIPO DE BIKE CADASTRADA

void altera_tipo(void) {
    char cod[6];
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
    ler_cod_bike(cod);
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("N?o foi poss?vel abrir o arquivo!");
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
      printf("C?digo n?o existe!\n");
    }
    else {
      printf("Tipo de bike editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


//FUN??O PARA ALTERAR ARO DE BIKE CADASTRADA

void altera_aro(void) {
    char cod[6];
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
    ler_cod_bike(cod);
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("N?o foi poss?vel abrir o arquivo!");
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
      printf("Cpf n?o existe!\n");
    }
    else {
      printf("Aro da bike editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}


//FUN??O PARA ALTERAR VALOR DO ALUGUEL DE BIKE CADASTRADA


void altera_valor(void) {
    char cod[6];
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
    ler_cod_bike(cod);
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("N?o foi poss?vel abrir o arquivo!");
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
      printf("Cpf n?o existe!\n");
    }
    else {
      printf("Valor do aluguel editado com sucesso!\n");
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


//FUN??O PARA ALTERAR MARCA DE BIKE CADASTRADA


void altera_marca(void) {
    char cod[6];
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
    ler_cod_bike(cod);
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
      printf("N?o foi poss?vel abrir o arquivo!");
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
      printf("Cpf n?o existe!\n");
    }
    else {
      printf("Marca da bike editado com sucesso!\n");
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


/////OP??O CASE 3 (BUSCA BIKE NO SISTEMA ATRAV?S DO C?DIGO DA BIKE)

Bike* buscar_bike(void) {
    Bike* bike;
	char cod[6];
    ler_cod_bike(cod);
	FILE* fp;
	bike = (Bike*) malloc(sizeof(Bike));
	fp = fopen("bikes.dat", "rb");
	if (fp == NULL) {
		printf("N?o foi poss?vel abrir o arquivo!");
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


///// FUN??O QUE EXIBE BIKE NA TELA

void print_bike(Bike* bike) {
  if ((bike == NULL) || (bike->status == 'x')) {
    printf("\nBike n?o existe!\n");
  } else {
    printf("Tipo: %c\n", bike->tipo);
    printf("Aro: %c\n", bike->aro);
    printf("Valor do aluguel: %f\n", bike->valor_aluguel);
    printf("Marca: %c\n", bike->marca);
    printf("C?digo: %c\n", bike->cod);   
  } 
}

///  CASE 4 (EXCLUI BIKE CADASTRADA DO SISTEMA ATRAV?S DO C?DIGO DA BIKE)

  
void excluir_bike(void) {
    char cod[6];
    Bike* ex = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;

    ler_cod_bike(cod);
    fp= fopen("bikes.dat", "r+b");
    if (fp==NULL) {
        printf("N?o foi poss?vel abrir o arquivo!");
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
            printf("Bike exclu?da com sucesso!\n");
            break;
        }
        }
    } 
  if (!busca) {
    printf("C?digo n?o encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}
