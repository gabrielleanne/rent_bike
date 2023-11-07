

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"promo.h"


////OP합ES PARA MENU PROMO

void modulo_promo (void) {
   Promo* pro;
   char opcao;
    do {
        opcao = promo();
        switch(opcao) {
            case '1':   listar_promo();
                        break;
            case '2': 	pro=cadastrar_promo();
                        gravar_promo(pro);
                        free(pro);
                        break;
            case '3': 	edit_promo();
                        break;
            case '4': 	excluir_promo();
                        break;
        } 		
    } while (opcao != '0');
}


///MENU PROMO합ES


char promo(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR PROMO합ES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMO플O-------------------DIGITE 2\n");
    printf(" 3. EDITAR PROMO플O----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMO플O---------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op豫o: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

///OP플O CASE 1 (LISTA TODAS AS PROMO합ES V홎IDAS NO SISTEMA)

void listar_promo(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO합ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


///OP플O CASE 2 (CADASTRA NOVA PROMO플O NO SISTEMA)

Promo* cadastrar_promo(void) {

    Promo* pro;
    pro = (Promo*) malloc(sizeof(Promo));
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO합ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos cadastrar uma promo豫o no sistema!");
    printf("\n");
    printf("\n");
    printf("An�ncio:\n");
    fgets(pro->anuncio,40,stdin);
    getchar();
    printf("\n");
    printf("Validade (em dias):\n");
    fgets(pro->val,5,stdin);
    getchar();
    printf("\n");
    printf("C�digo gerado da promo豫o:\n");
    fgets(pro->cod,5,stdin);
    getchar();
    pro->status = 'c';
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


/// FUN플O GRAVA PROMO플O NO SISTEMA


void gravar_promo(Promo* pro) {
  FILE* fp;
  fp = fopen("promo.dat", "ab");
  if (fp == NULL) {
    printf("Ocorreu um erro na abertura do arquivo!\n");
    exit(1);
  }
  fwrite(pro, sizeof(Promo), 1, fp);
  fclose(fp);
}



////OP플O CASE 3 (ALTERA DADOS/INFORMA합ES SOBRE PROMO합ES CADASTRADAS)



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
    printf("------------------MENU PROMO합ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos editar dados de uma promo豫o no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR AN�NCIO-----------------------DIGITE 1\n");
    printf(" 2. EDITAR VALIDADE----------------------DIGITE 2\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op豫o: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

/// FUN플O SOLICITA C�DIGO DA BIKE PARA BUSCA

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
	printf("Digite o c�digo: \n");
	fgets(cod,5,stdin);
    getchar();
    return cod;
}


void edit_anuncio(void) {
    char* cod;
    Promo* new = (Promo*) malloc(sizeof(Promo));
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
    fp= fopen("promo.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Promo), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("An�ncio: \n");
                fgets(new->anuncio,40,stdin);
                getchar();
                fseek(fp, -sizeof(Promo), SEEK_CUR);
                fwrite(new, sizeof(Promo), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("C�digo n�o existe!\n");
    }
    else {
      printf("An�ncio editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}

void edit_validade(void) {
    char* cod;
    Promo* new = (Promo*) malloc(sizeof(Promo));
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
    fp= fopen("promo.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Promo), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("Validade: \n");
                fgets(new->val,5,stdin);
                getchar();
                fseek(fp, -sizeof(Promo), SEEK_CUR);
                fwrite(new, sizeof(Promo), 1, fp);
                busca=1;
                break;
            }       
        
        }
      
    }
    if (!busca) {
      printf("C�digo n�o existe!\n");
    }
    else {
      printf("Validade editada com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




////OP플O CASE 4 (EXCLUI PROMO플O CADASTRADA NO SISTEMA)


void excluir_promo(void) {
   
  char* cod;
  Promo* ex = (Promo*) malloc(sizeof(Promo));
  FILE* fp;
  int busca = 0;

  cod = pesquisar_cod();
  fp= fopen("promo.dat", "r+b");
  if (fp==NULL) {
    printf("N�o foi poss�vel abrir o arquivo!");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
  }
  else{
    while (!feof(fp)) {
      fread(ex, sizeof(Promo), 1, fp);    
      if (strcmp(ex->cod, cod)==0) {
        busca=1;
        ex->status='x'; 
        fseek(fp, -sizeof(Promo), SEEK_CUR);
        fwrite(ex, sizeof(Promo), 1, fp);  
        printf("Promo豫o exclu�da com sucesso!\n");
        break;
      }
    }
  } 
  if (!busca) {
    printf("C�digo n�o encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}