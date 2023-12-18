
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>
#include"cliente.h"
#include"valid.h"


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


/// OPÇÕES PARA MENU CLIENTES 

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
            
         } 		
   } while (opcao != '0'); 
}


/// CASE 1 (FUNÇÃO CADASTRA NOVO CLIENTE NO SISTEMA)

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
	  printf("Nome:\n ");
	  fgets(cli->nome, 49, stdin);
    getchar();
    while (!valida_nome (cli->nome)) {
        printf("Nome digitado não é válido!\n");
        printf("Informe o nome novamente:\n ");
        fgets(cli->nome, 49, stdin);
        getchar();
    }
    printf("\n");
    printf("CPF (somente números):\n ");
    fgets(cli->cpf, 12, stdin);
    while ((!valida_cpf (cli->cpf)) || (!cpf_repeted (cli->cpf))) {
        printf("Cpf digitado não é válido!\n");
        printf("Informe o cpf novamente (somente números):\n ");
        fgets(cli->cpf, 12, stdin);
        getchar();
    }
    printf("\n");
    printf("Telefone com DDD (somente números):\n ");
    fgets(cli->tel, 12, stdin);
    while (!valida_telefone (cli->tel)) {
        printf("Telefone inválido!\nInforme o telefone com DDD novamente:\n ");
        fgets(cli->tel, 12, stdin);
        getchar();
    }
    printf("\n");
    printf("Dados do Endereço:\n");
    printf("\n");
    printf("Logradouro:\n ");
    fgets(cli->log, 25, stdin);
    getchar();
    printf("\n");
    printf("Número:\n ");
    fgets(cli->num, 5, stdin);
    getchar();
    printf("\n");
    printf("Bairro:\n ");
    fgets(cli->bai, 18, stdin);
    getchar();
    printf("\n");
    printf("Email:\n ");
    fgets(cli->email, 48, stdin);
    getchar();
    while (!valida_email (cli->email)){
        printf("Email inválido!\n");
        printf("Informe novamente o email:\n ");
        fgets(cli->email, 48, stdin);
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

/// FUNÇÃO GRAVA CADASTRO NO SISTEMA


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


//// CASE 2 (FUNÇÃO BUSCA CLIENTE CADASTRADO PELO CPF)

Cliente* buscar_cliente(void) {

	Cliente* cli;
	char* cpf;
  cpf=ler_cpf();
	FILE* fp;
	cli = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "rb");
	if (fp == NULL) {
		printf("Não foi possível abrir o arquivo!");
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

/// FUNÇÃO SOLICITA CPF PARA BUSCA

char* ler_cpf(void) {
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
	printf("Digite o CPF do cliente: \n");
  printf("\n");
	fgets(cpf,12,stdin);
  getchar();
  while ((!valida_cpf (cpf))) {
        printf("Cpf digitado não é válido!\n");
        printf("Informe o cpf novamente (somente números):\n ");
        fgets(cpf, 12, stdin);
        getchar();
 }
  return cpf;
}



int cpf_repeted(char* cpf) {

    FILE* fp = fopen("cli.dat", "rb");

    Cliente cli;
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (strcmp(cli.cpf, cpf) == 0) {
            fclose(fp);
            return 0; // CPF repetido (já cadastrado)
        }
    }

    fclose(fp); // Fecha o arquivo
    return 1; // CPF não repetido
}


///// FUNÇÃO QUE EXIBE CLIENTE NA TELA

void print_cliente(Cliente* cli) {
  if ((cli == NULL) || (cli->status == 'x')) {
    printf("\nCliente não existe!\n");
  } else {
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Email: %s\n", cli->email);
    printf("Telefone: %s\n", cli->tel);
    printf("Logradouro: %s\n", cli->log);
    printf("Número: %s\n", cli->num);
    printf("Bairro: %s\n", cli->bai);
    printf("Email: %s\n", cli->email);
    printf("Status: %c\n", cli->status);
  }
  
}



// CASE 3 (EDITA DADOS/INFORMAÇÕES DE CLIENTES CADASTRADOS NO SISTEMA)

// OPÇÕES DO MENU EDITAR CLIENTE

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
    printf(" 3. EDITAR ENDEREÇO----------------------DIGITE 3\n");
    printf(" 4. EDITAR E-MAIL------------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;

}

//FUNÇÃO EDITA NOME DO CLIENTE

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
    cpf = ler_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Nome: \n");
	        fgets(new->nome, 49, stdin);
          getchar();
          while (!valida_nome (new->nome)) {
            printf("Nome digitado não é válido!\n");
            printf("Informe o nome novamente: \n");
            fgets(new->nome, 49, stdin);
            getchar();
          }       
          fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf não existe!\n");
    }
    else {
      printf("Nome editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// FUNÇÃO EDITA TELEFONE DO CLIENTE


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
    cpf= ler_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Telefone com DDD (somente números): \n");
	        fgets(new->tel, 12, stdin);
          getchar();
          while (!valida_telefone (new->tel)) {
            printf("Telefone inválido!\nInforme o telefone com DDD novamente: \n");
            fgets(new->tel, 12, stdin);
            getchar();
    }
          fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf não existe!\n");
    }
    else {
      printf("Telefone editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


// OPÇÕES PARA ALTERAR DADOS DO ENDEREÇO DO CLIENTE

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

// MENU EDITAR DADOS DE ENDEREÇO

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
    printf("Vamos editar dados do endere?o!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR LOGRADOURO--------------------DIGITE 1\n");
    printf(" 2. EDITAR NÚMERO------------------------DIGITE 2\n");
    printf(" 3. EDITAR BAIRRO------------------------DIGITE 3\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opçãoo: \n");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

//FUNÇÂO EDITA LOGRADOURO DO CLIENTE

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
    cpf= ler_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Logradouro: ");
	        fgets(new->log, 25, stdin);  
          getchar();
          fseek(fp, (-1L)*-sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf não existe!\n");
    }
    else {
      printf("Logradouro editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}


//FUNÇÂO EDITA NÚMERO DO ENDEREÇO DO CLIENTE

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
    cpf= ler_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("NÃo foi possÍvel abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Número: \n");
	        fgets(new->num, 5, stdin);
          getchar();       
          fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf não existe!\n");
    }
    else {
      printf("Número editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}

// FUNÇÂO EDITA BAIRRO DO CLIENTE

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
    cpf= ler_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Bairro: \n");
	        fgets(new->bai, 18, stdin);
          getchar();
          fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf não existe!\n");
    }
    else {
      printf("Cadastro editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


//FUNÇÃO EDITA EMAIL DO CLIENTE

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
    cpf= ler_cpf();
    fp= fopen("clientes.dat", "r+b");
    if (fp==NULL) {
      printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
    }
    else {
      while (fread(new, sizeof(Cliente), 1, fp)==1) {
        if (strcmp(new->cpf, cpf)==0) {
          printf("Email: \n");
	        fgets(new->email,48, stdin);
          getchar();
         while (!valida_email (new->email)){
          printf("Email inválido!\n");
          printf("Informe novamente o email: \n");
          fgets(new->email, 48, stdin);
          getchar();
        }       
          fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
          fwrite(new, sizeof(Cliente), 1, fp);
          busca=1;
          break;
        }
      }
    }
    if (!busca) {
      printf("Cpf não existe!\n");
    }
    else {
      printf("Cadastro editado com sucesso!\n");
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


// ///OPÇÃO CASE 4 (EXCLUI CLIENTE CADASTRADO NO SISTEMA)

        
void excluir_cliente(void) {

  char* cpf;
  Cliente* ex = (Cliente*) malloc(sizeof(Cliente));
  FILE* fp;
  int busca = 0;

  cpf = ler_cpf();
  fp= fopen("clientes.dat", "r+b");
  if (fp==NULL) {
    printf("Não foi possível abrir o arquivo!\n");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
  }
  else{  
    while (fread(ex, sizeof(Cliente), 1, fp)) {
      if (strcmp(ex->cpf, cpf)==0) {
        busca=1;
        ex->status='x'; 
        fseek(fp, (-1L)*sizeof(Cliente), SEEK_CUR);
        fwrite(ex, sizeof(Cliente), 1, fp);  
        printf("Cliente excluído com sucesso!\n");
        break;
      }
    }
  } 
  if (!busca) {
    printf("Cpf não encontrado!\n");  
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(ex);
}
    
