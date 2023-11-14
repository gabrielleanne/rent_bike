

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include<locale.h>
#include"promo.h"


////OPÇÕES PARA MENU PROMO

void modulo_promo (void) {
   Promo* pro;
   char opcao;
    do {
        opcao = promo();
        switch(opcao) {
            
            case '1': 	pro=cadastrar_promo();
                        gravar_promo(pro);
                        free(pro);
                        break;
            case '2': 	edit_promo();
                        break;
            case '3': 	excluir_promo();
                        break;
        } 		
    } while (opcao != '0');
}


///MENU PROMOÇÕES


char promo(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. CADASTRAR PROMOÇÃO-------------------DIGITE 1\n");
    printf(" 2. EDITAR PROMOÇÃO----------------------DIGITE 2\n");
    printf(" 3. EXCLUIR PROMOÇÃO---------------------DIGITE 3\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}



///OPÇÃO CASE 1 (CADASTRA NOVA PROMOÇÃO NO SISTEMA)

Promo* cadastrar_promo(void) {

    Promo* pro;
    pro = (Promo*) malloc(sizeof(Promo));
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos cadastrar uma promoção no sistema!");
    printf("\n");
    printf("\n");
    printf("Anúncio:\n");
    fgets(pro->anuncio,40,stdin);
    getchar();
    printf("\n");
    printf("Validade (em dias):\n");
    fgets(pro->val,5,stdin);
    getchar();
    printf("\n");
    printf("Código gerado da promoção:\n");
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


/// FUNÇÃO GRAVA PROMOÇÃO NO SISTEMA


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



////OPÇÃO CASE 2 (ALTERA DADOS/INFORMAÇÕES SOBRE PROMOÇÕES CADASTRADAS)



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
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos editar dados de uma promoção no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR ANÚNCIO-----------------------DIGITE 1\n");
    printf(" 2. EDITAR VALIDADE----------------------DIGITE 2\n");
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
  printf("Digite o código: \n");
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
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
    }
    else {
        while (fread(new, sizeof(Promo), 1, fp)==1) {
            if (strcmp(new->cod, cod)==0) {
                printf("Anúncio: \n");
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
      printf("Código não existe!\n");
    }
    else {
      printf("Anúncio editado com sucesso!\n");
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
      printf("Não foi possível abrir o arquivo!");
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
      printf("Código não existe!\n");
    }
    else {
      printf("Validade editada com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




////OPÇÃO CASE 3 (EXCLUI PROMOÇÃO CADASTRADA NO SISTEMA)


void excluir_promo(void) {
   
  char cod[5];
  Promo* ex = (Promo*) malloc(sizeof(Promo));
  FILE* fp;
  int busca = 0;

  ler_cod(cod);
  fp= fopen("promo.dat", "r+b");
  if (fp==NULL) {
    printf("Não foi possível abrir o arquivo!");
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
        printf("Promoção excluída com sucesso!\n");
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