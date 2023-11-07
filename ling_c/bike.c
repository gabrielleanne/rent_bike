
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"bike.h"
#include"util.h"


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
            case '5':   listar_bikes();
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
    printf(" 5. LISTAR BIKES-------------------------DIGITE 5\n");
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
    char tipo;
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
    tipo=tipo_bike();
    scanf("%c",&bike->tipo);
    getchar();
    printf("Aro: \n");
    fgets(bike->aro,3,stdin);
    getchar();
    printf("Valor do aluguel:\n");
	fgets(bike->valor_aluguel, 5,stdin);
    getchar();
    printf("Marca da bike:\n");
	fgets(bike->marca,20 ,stdin);
    getchar();
    printf("Código da bike:\n");
	fgets(bike->cod,2 ,stdin);
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
    return esc;
}

////OPÇÃO CASE 2 (OPÇÕES DE DADOS DAS BIKES PARA EDITAR)

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

/// FUNÇÃO SOLICITA CÓDIGO DA BIKE PARA BUSCA

char* pesquisar_cod(void) {
	char* cod;
	cod = (char*) malloc(2*sizeof(char));
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
	fgets(cod,2,stdin);
    getchar();
    return cod;
}


//FUNÇÃO PARA ALTERAR TIPO DE BIKE CADASTRADA

void altera_tipo(void) {
    char* cod;
    Bike* new = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;
    char tipo;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cod = pesquisar_cod();
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
                tipo=tipo_bike();
                scanf("%c",&new->tipo);
                getchar();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Cpf não existe!\n");
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
    cod = pesquisar_cod();
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
                fgets(new->aro,3,stdin);
                getchar();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Cpf não existe!\n");
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
    cod = pesquisar_cod();
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
                fgets(new->valor_aluguel,5,stdin);
                getchar();
                fseek(fp, -sizeof(Bike), SEEK_CUR);
                fwrite(new, sizeof(Bike), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("Cpf não existe!\n");
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
    cod = pesquisar_cod();
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
      printf("Cpf não existe!\n");
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
    cod=pesquisar_cod();
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
    printf("Tipo: %d\n", bike->tipo);
    printf("Aro: %s\n", bike->aro);
    printf("Valor do aluguel: %s\n", bike->valor_aluguel);
    printf("Marca: %s\n", bike->marca);
    printf("Código: %s\n", bike->cod);   
  } 
}

///  CASE 4 (EXCLUI BIKE CADASTRADA DO SISTEMA ATRAVÉS DO CÓDIGO DA BIKE)

  
void excluir_bike(void) {
    char* cod;
    Bike* ex = (Bike*) malloc(sizeof(Bike));
    FILE* fp;
    int busca = 0;

    cod = pesquisar_cod();
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

////OPÇÃO CASE 5 (LISTA TODAS AS BIKES CADASTRADAS NO SISTEMA)

void listar_bikes(void) {
    FILE* fp;
    Bike* bike;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    bike = (Bike*) malloc(sizeof(Bike));
    fp = fopen("bikes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    while(fread(bike, sizeof(Bike), 1, fp)) {
        if (bike->status != 'x') {
            print_bike(bike);
        }
    }
    fclose(fp);
    free(bike);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
