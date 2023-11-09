

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include<locale.h>
#include"promo.h"


////OP��ES PARA MENU PROMO

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


///MENU PROMO��ES


char promo(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR PROMO��ES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMO��O-------------------DIGITE 2\n");
    printf(" 3. EDITAR PROMO��O----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMO��O---------------------DIGITE 4\n");
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

///OP��O CASE 1 (LISTA TODAS AS PROMO��ES V�LIDAS NO SISTEMA)

void listar_promo(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


///OP��O CASE 2 (CADASTRA NOVA PROMO��O NO SISTEMA)

Promo* cadastrar_promo(void) {

    Promo* pro;
    pro = (Promo*) malloc(sizeof(Promo));
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos cadastrar uma promo��o no sistema!");
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
    printf("C�digo gerado da promo��o:\n");
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
    return pro;
}


/// FUN��O GRAVA PROMO��O NO SISTEMA


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



////OP��O CASE 3 (ALTERA DADOS/INFORMA��ES SOBRE PROMO��ES CADASTRADAS)



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
    printf("------------------MENU PROMO��ES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos editar dados de uma promo��o no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR AN�NCIO-----------------------DIGITE 1\n");
    printf(" 2. EDITAR VALIDADE----------------------DIGITE 2\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

/// FUN��O SOLICITA C�DIGO DA BIKE PARA BUSCA

void ler_cod(char* cod) {
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
  fgets(cod,3,stdin);
  getchar();
}


void edit_anuncio(void) {
    char cod[5];
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
    ler_cod(cod);
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
    char cod[5];
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
    ler_cod(cod);
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




////OP��O CASE 4 (EXCLUI PROMO��O CADASTRADA NO SISTEMA)


void excluir_promo(void) {
   
  char cod[5];
  Promo* ex = (Promo*) malloc(sizeof(Promo));
  FILE* fp;
  int busca = 0;

  ler_cod(cod);
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
        printf("Promo��o exclu�da com sucesso!\n");
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