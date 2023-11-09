
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>
#include"cliente.h"
#include"util.h"


/// OP��ES PARA MENU CLIENTES 

void modulo_cliente (void) {
   Cliente* cli;
   char opcao;
    do {
        opcao = clientes();
        switch(opcao) {
            case '1': 	cli=cadastrar_cliente();
                        gravar_cliente(cli);
                        free(cli);                   
                        break;
            case '2': 	cli= buscar_cliente();
                        print_cliente(cli);
                        printf("\n\nTecle ENTER para continuar!\n\n");
	                      getchar();
                        free(cli);
                        break;                
            case '3':   edit_cliente();
                        break;
            case '4': 	excluir_cliente();
                        break;
            case '5':   listar_clientes();
                        break;
         } 		
   } while (opcao != '0'); 
}


//MENU CLIENTES

char clientes(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. CADASTRAR CLIENTE -------------------DIGITE 1\n");
    printf(" 2. BUSCAR CLIENTE-----------------------DIGITE 2\n");
    printf(" 3. EDITAR CADASTRO----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR CADASTRO---------------------DIGITE 4\n");
    printf(" 5. LISTAR TODOS-------------------------DIGITE 5\n");
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

/// CASE 1 (FUN��O CADASTRA NOVO CLIENTE NO SISTEMA)

Cliente* cadastrar_cliente(void) {

    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("Vamos cadastrar um cliente no sistema!");
    printf("\n");
    printf("\n");
	  printf("Nome: ");
	  fgets(cli->nome, 51, stdin);
    while (!valida_nome (cli->nome)) {
        printf("Nome digitado n�o � v�lido!\n");
        printf("Informe o nome novamente: ");
        fgets(cli->nome, 51, stdin);
        getchar();
    }
    printf("\n");
    printf("CPF (somente n�meros): ");
    fgets(cli->cpf, 12, stdin);
    while (!valida_cpf (cli->cpf)) {
        printf("Cpf digitado n�o � v�lido!\n");
        printf("Informe o cpf novamente (somente n�meros): ");
        fgets(cli->cpf, 12, stdin);
        getchar();
    }
    printf("\n");
    printf("Telefone com DDD (somente n�meros): ");
    fgets(cli->tel, 12, stdin);
    while (!valida_telefone (cli->tel)) {
        printf("Telefone inv�lido!\nInforme o telefone com DDD novamente: ");
        fgets(cli->tel, 12, stdin);
        getchar();
    }
    printf("\n");
    printf("Dados do Endere�o:\n");
    printf("\n");
    printf("Logradouro: ");
    fgets(cli->log, 12, stdin);
    while (!valida_logradouro (cli->log)) {
        printf("Logradouro digitado n�o � v�lido!\n");
        printf("Informe o logradouro novamente: ");
        fgets(cli->log, 20, stdin);
        getchar();
    }
    printf("\n");
    printf("N�mero: ");
    fgets(cli->num, 5, stdin);
    getchar();
    printf("\n");
    printf("Bairro: ");
    fgets(cli->bai, 15, stdin);
    while (!valida_bairro (cli->bai)) {
        printf("Bairro digitado n�o � v�lido!\n");
        printf("Informe o bairro novamente: ");
        fgets(cli->bai, 15, stdin);
        getchar();
    }
    printf("\n");
    printf("Email: ");
    fgets(cli->email, 40, stdin);
    while (!valida_email (cli->email)){
        printf("Email inv�lido!");
        printf("Informe novamente o email: ");
        fgets(cli->email, 40, stdin);
        getchar();
    }
    cli->status = 'c';
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cli;
}

/// FUN��O GRAVA CADASTRO NO SISTEMA


void gravar_cliente(Cliente* cli) {
  FILE* fp;
  fp = fopen("clientes.dat", "ab");
  if (fp == NULL) {
    printf("Ocorreu um erro na abertura do arquivo!\n");
    exit(1);
  }
  fwrite(cli, sizeof(Cliente), 1, fp);
  fclose(fp);
}


//// CASE 2 (FUN��O BUSCA CLIENTE CADASTRADO PELO CPF)

Cliente* buscar_cliente(void) {

	Cliente* cli;
	char* cpf;
  cpf=pesquisar_cpf();
	FILE* fp;
	cli = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "rb");
	if (fp == NULL) {
		printf("N�o foi poss�vel abrir o arquivo!");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
	}
	while(fread(cli, sizeof(Cliente), 1, fp)) {
		if ((strcmp(cli->cpf, cpf) == 0) && (cli->status == 'c')) {
			return cli;
		}
	}
	fclose(fp);
	return NULL;

}

/// FUN��O SOLICITA CPF PARA BUSCA

char* pesquisar_cpf(void) {
	char* cpf;

	cpf = (char*) malloc(12*sizeof(char));
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
	printf("Digite o CPF: \n");
	fgets(cpf,12,stdin);
  getchar();
  return cpf;
}


///// FUN��O QUE EXIBE CLIENTE NA TELA

void print_cliente(Cliente* cli) {
  if ((cli == NULL) || (cli->status == 'x')) {
    printf("\nCliente n�o existe!\n");
  } else {
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Email: %s\n", cli->email);
    printf("Logradouro: %s\n", cli->log);
    printf("N�mero: %s\n", cli->num);
    printf("Bairro: %s\n", cli->bai);
    printf("Email: %s\n", cli->email);
    printf("Status: %c\n", cli->status);
  }
  
}




// CASE 3 (EDITA DADOS/INFORMA��ES DE CLIENTES CADASTRADOS NO SISTEMA)

// OP��ES DO MENU EDITAR CLIENTE

void edit_cliente (void) {

    char opcao;

    do {
        opcao = editar_cliente();

        switch (opcao) {
            case '1': 	  edit_nome();
                          break;
             case '2': 	  edit_tel();
                          break;
             case '3': 	  edit_end();
                          break;
             case '4':    edit_mail();
                          break;
        } 		
    } while (opcao != '0');
   
}

// MENU EDITAR CLIENTES

char editar_cliente(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos editar dados de um cliente no sistema!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR NOME--------------------------DIGITE 1\n");
    printf(" 2. EDITAR TELEFONE----------------------DIGITE 2\n");
    printf(" 3. EDITAR ENDERE�O----------------------DIGITE 3\n");
    printf(" 4. EDITAR E-MAIL------------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;

}

//FUN��O EDITA NOME DO CLIENTE

void edit_nome(void) {

    char* cpf;
    Cliente* new = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    int busca = 0;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    cpf = pesquisar_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Nome: ");
	        fgets(new->nome, 51, stdin);
          while (!valida_nome (new->nome)) {
            printf("Nome digitado n�o � v�lido!\n");
            printf("Informe o nome novamente: ");
            fgets(new->nome, 51, stdin);
            getchar();
          }       
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf n�o existe!\n");
    }
    else {
      printf("Nome editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// FUN��O EDITA TELEFONE DO CLIENTE


void edit_tel(void) {

    char* cpf;
    Cliente* new = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    int busca = 0;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cpf= pesquisar_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Telefone com DDD (somente n�meros): ");
	        fgets(new->tel, 12, stdin);
          while (!valida_telefone (new->tel)) {
          printf("Telefone inv�lido!\nInforme o telefone com DDD novamente: ");
          fgets(new->tel, 12, stdin);
          getchar();
    }
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf n�o existe!\n");
    }
    else {
      printf("Telefone editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


// OP��OES PARA ALTERAR DADOS DO ENDERE�O DO CLIENTE

void edit_end (void) {
    char opcao;

    do {
        opcao = alterar_end();

        switch (opcao) {
            case '1': 	altera_logradouro();
                        break;
            case '2': 	altera_numero();
                        break;
            case '3': 	altera_bairro();
                        break;
        } 		
    } while (opcao != '0');
   
}

// MENU EDITAR DADOS DE ENDERE�O

char alterar_end (void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("Vamos editar dados do endere�o!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR LOGRADOURO--------------------DIGITE 1\n");
    printf(" 2. EDITAR N�MERO------------------------DIGITE 2\n");
    printf(" 3. EDITAR BAIRRO------------------------DIGITE 3\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��oo: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

//FUN��O EDITA LOGRADOURO DO CLIENTE

void altera_logradouro(void) {

    char* cpf;
    Cliente* new = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    int busca = 0;  
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    cpf= pesquisar_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Logradouro: ");
	        fgets(new->log, 20, stdin);
          while (!valida_logradouro (new->log)) {
            printf("Nome digitado n�o � v�lido!\n");
            printf("Informe o nome novamente: ");
            fgets(new->log, 20, stdin);
            getchar();
          }       
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf n�o existe!\n");
    }
    else {
      printf("Logradouro editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}


//FUN��O EDITA N�MERO DO ENDERE�O DO CLIENTE

void altera_numero(void) {
    
    char* cpf;
    Cliente* new = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    int busca = 0;  
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cpf= pesquisar_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("N�mero: ");
	        fgets(new->num, 5, stdin);
          getchar();       
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf n�o existe!\n");
    }
    else {
      printf("N�mero editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}

// FUN��O EDITA BAIRRO DO CLIENTE

void altera_bairro(void) {
    char* cpf;
    Cliente* new = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    int busca = 0; 
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    cpf= pesquisar_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Bairro: ");
	        fgets(new->bai, 15, stdin);
          while (!valida_nome (new->bai)) {
            printf("Bairro digitado n�o � v�lido!\n");
            printf("Informe o bairro novamente: ");
            fgets(new->bai, 15, stdin);
            getchar();
          }       
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf n�o existe!\n");
    }
    else {
      printf("Cadastro editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


//FUN��O EDITA EMAIL CO CLIENTE

void edit_mail(void) {
    
    char* cpf;
    Cliente* new = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    int busca = 0; 
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    cpf= pesquisar_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("N�o foi poss�vel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Email: ");
	        fgets(new->email,40, stdin);
         while (!valida_email (new->email)){
          printf("Email inv�lido!");
          printf("Informe novamente o email: ");
          fgets(new->email, 40, stdin);
          getchar();
        }       
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf n�o existe!\n");
    }
    else {
      printf("Cadastro editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


// ///OP��O CASE 4 (EXCLUI CLIENTE CADASTRADO NO SISTEMA)

        
void excluir_cliente(void) {

  char* cpf;
  Cliente* ex = (Cliente*) malloc(sizeof(Cliente));
  FILE* fp;
  int busca = 0;

  cpf = pesquisar_cpf();
  fp= fopen("clientes.dat", "r+b");
  if (fp==NULL) {
    printf("N�o foi poss�vel abrir o arquivo!");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
  }
  else{
    // while (!feof(fp)) {
    //   fread(ex, sizeof(Cliente), 1, fp);    
    while (fread(ex, sizeof(Cliente), 1, fp)) {
      if (strcmp(ex->cpf, cpf)==0) {
        busca=1;
        ex->status='x'; 
        fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
        fwrite(ex, sizeof(Cliente), 1, fp);  
        printf("Cliente exclu�do com sucesso!\n");
        break;
      }
    }
  } 
  if (!busca) {
    printf("Cpf n�o encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}
    

// ////OP��O CASE 5 (LISTA TODOS OS CLIENTES CADASTRADOS NO SISTEMA)

 void listar_clientes(void) {
    FILE* fp;
    Cliente* cli;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    while(fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status != 'x') {
            print_cliente(cli);
        }
    }
    fclose(fp);
    free(cli);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




