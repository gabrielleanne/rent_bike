
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<locale.h>
#include"cliente.h"
#include"util.h"

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
                        free(cli);
                        break;                
             //case '3': edit_cliente();
               //        break;
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
    printf("Escolha sua opção: ");
    scanf("%c",&esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

///OPCÃO CASE 1 (CADASTRA NOVO CLIENTE NO SISTEMA)

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
        printf("Nome digitado não é válido!\n");
        printf("Informe o nome novamente: ");
        fgets(cli->nome, 51, stdin);
    }
    printf("\n");
    printf("CPF: ");
    fgets(cli->cpf, 12, stdin);
    while (!valida_cpf (cli->cpf)) {
        printf("Cpf digitado não é válido!\n");
        printf("Informe o cpf novamente: ");
        fgets(cli->cpf, 12, stdin);
    }
    printf("\n");
    printf("Telefone: ");
    fgets(cli->tel, 12, stdin);
    while (!valida_telefone (cli->tel)) {
        printf("Telefone inválido!\n");
        printf("Informe o telefone com DDD novamente: ");
        fgets(cli->tel, 12, stdin);
    }
    printf("\n");
    printf("Dados do Endereço:\n");
    printf("\n");
    printf("Logradouro: ");
    fgets(cli->log, 12, stdin);
    while (!valida_logradouro (cli->log)) {
        printf("Logradouro digitado não é válido!\n");
        printf("Informe o logradouro novamente: ");
        fgets(cli->log, 20, stdin);
    }
    printf("\n");
    printf("Número: ");
    fgets(cli->num, 5, stdin);
    while (!valida_numero (cli->num)) {
        printf("Número digitado não é válido!\n");
        printf("Informe o número novamente: ");
        fgets(cli->num, 5, stdin);
    }
    printf("\n");
    printf("Bairro: ");
    fgets(cli->bai, 15, stdin);
    while (!valida_bairro (cli->bai)) {
        printf("Bairro digitado não é válido!\n");
        printf("Informe o bairro novamente: ");
        fgets(cli->bai, 15, stdin);
    }
    printf("\n");
    printf("Email: ");
    fgets(cli->email, 40, stdin);
    while (!valida_email (cli->email)){
        printf("Email inválido!");
        printf("Informe novamente o email: ");
        fgets(cli->email, 40, stdin);
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


////OPÇÃO CASE 2 (BUSCA CLIENTE CADASTRADO PELO CPF)

Cliente* buscar_cliente(void) {

	Cliente* cli;
	char* cpf;
  cpf=pesquisar_cpf();
	FILE* fp;
	cli = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "rb");
	if (fp == NULL) {
		printf("Não foi possível abrir o arquivo!");
    printf("\n\nTecle ENTER para continuar!\n\n");
	  getchar();
	  exit(1);
	}
	while(fread(cli, sizeof(Cliente), 1, fp)) {
		if ((strcmp(cli->cpf, cpf) == 0) && (cli->status == 'c')) {
			fclose(fp);
			return cli;
		}
	}
	fclose(fp);
	return NULL;
}
	

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
	printf("Digite o CPF:  ");
	fgets(cpf,12,stdin);
  free(cpf);
  return cpf;
}


void print_cliente(Cliente* cli) {
  if ((cli == NULL) || (cli->status == 'x')) {
    printf("\n= = = Aluno Inexistente = = =\n");
  } else {
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Email: %s\n", cli->email);
    printf("Logradouro: %s\n", cli->log);
    printf("Número: %s\n", cli->num);
    printf("Bairro: %s\n", cli->bai);
    printf("Email: %s\n", cli->email);
  }
}




// ////OPÇÃO CASE 3 (EDITA DADOS/INFORMAÇÕES DE CLIENTES CADASTRADOS NO SISTEMA)




// void edit_cliente (void) {

//     Cliente* cli;
//     char opcao;

//     do {
//         opcao = editar_cliente();

//         switch (opcao) {
//             case '1': 	cli=edit_nome();
//                         break;
//             // case '2': 	cli=edit_tel();
//             //             break;
//             // case '3': 	cli=edit_end();
//             //             break;
//             // case '4':   cli=edit_mail();
//             //             break;
//         } 		
//     } while (opcao != '0');
   
// }


// char editar_cliente(void) {
//     char esc;
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("------------------MENU CLIENTES------------------\n");
//     printf("-------------------------------------------------\n");
//     printf("Vamos editar dados de um cliente no sistema!");
//     printf("\n");
//     printf("\n");
//     printf(" 1. EDITAR NOME--------------------------DIGITE 1\n");
//     printf(" 2. EDITAR TELEFONE----------------------DIGITE 2\n");
//     printf(" 3. EDITAR ENDEREÇO----------------------DIGITE 3\n");
//     printf(" 4. EDITAR E-MAIL------------------------DIGITE 4\n");
//     printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
//     printf("\n");
//     printf("Escolha sua opção: \n");
//     scanf("%c", &esc);
//     getchar();
//     printf("\n");
//     printf("\t\t\t>>> Aguarde...\n");
//     sleep(1);
//     return esc;

// }



// Cliente* edit_nome(void) {
//     FILE* fp;
//     Cliente* cli;
//     char cpf_c[12];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//      printf("Informe o CPF: "); 
//     fgets(cpf_c, 12, stdin);
//     while (!valida_cpf (cpf_c)) {
//         printf("Cpf digitado não é válido!\n");
//         printf("Informe o cpf novamente: ");
//         fgets(cpf_c, 12, stdin);
//     }
//     printf("\n");
//     if (cli->cpf == cpf_c) {
//         printf("Digite o nome: \n");
//         fgets(cli->nome, 51, stdin);
//         while (!valida_nome (cli->nome)) {
//             printf("Nome digitado não é válido!\n");
//             printf("Informe o nome novamente: ");
//             fgets(cli->nome, 51, stdin);    
//         }
//     }
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();
// }


// void edit_cpf(void) {
//     char cpf[12];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     verifica_cpf (cpf);
//     printf("\n");
//     printf("Programa em desenvolvimento!\n");
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();
// }

// void edit_tel(void) {
//     char cpf[12];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     verifica_cpf (cpf);
//     printf("\n");
//     printf("Programa em desenvolvimento!\n");
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();
// }


// // void edit_end (void) {
// //     char opcao;

// //     do {
// //         opcao = alterar_end();

// //         switch (opcao) {
// //             case '1': 	altera_logradouro();
// //                         break;
// //             case '2': 	altera_numero();
// //                         break;
// //             case '3': 	altera_bairro();
// //                         break;
// //         } 		
// //     } while (opcao != '0');
   
// // }


// char alterar_end (void) {
//     char esc;
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     printf("\n");
//     printf("Vamos editar dados do endereço!");
//     printf("\n");
//     printf("\n");
//     printf(" 1. EDITAR LOGRADOURO--------------------DIGITE 1\n");
//     printf(" 2. EDITAR NÚMERO------------------------DIGITE 2\n");
//     printf(" 3. EDITAR BAIRRO------------------------DIGITE 3\n");
//     printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
//     printf("\n");
//     printf("Escolha sua opção: \n");
//     scanf("%c", &esc);
//     getchar();
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Aguarde...\n");
//     sleep(1);
//     return esc;
// }


// void altera_logradouro(void) {
//     char log[20];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     //verifica_logradouro (log);
//     printf("\n");
//     printf("\n");
//     printf("Logradouro alterado com sucesso!\n");
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();

// }


// void altera_numero(void) {
//     char num[5];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     //verifica_numero (num);
//     printf("\n");
//     printf("\n");
//     printf("Número alterado com sucesso!\n");
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();
    
// }



// void altera_bairro(void) {
//     char bai[15];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     //verifica_bairro (bai);
//     printf("\n");
//     printf("\n");
//     printf("Bairro alterado com sucesso!\n");
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();
// }



// void edit_mail(void) {
//     char cpf[12];
//     system("clear||cls");
//     printf("\n");
//     printf("-------------------------------------------------\n");
//     printf("*******************RENT A BIKE*******************\n");
//     printf("-------------------------------------------------\n");
//     printf("-------------------MENU BIKES--------------------\n");
//     printf("-------------------------------------------------\n");
//     verifica_cpf (cpf);
//     printf("\n");
//     printf("Programa em desenvolvimento!\n");
//     printf("\n");
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();
// }




// ///OPÇÃO CASE 4 (EXCLUI CLIENTE CADASTRADO NO SISTEMA)




        
Cliente* excluir_cliente(void) {
  
	
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");

    Cliente* cli;
	  char *cpf;
    FILE* fp;
	  cpf = pesquisar_cpf();
	  cli = (Cliente*) malloc(sizeof(Cliente));
	  fp = fopen("alunos.dat", "rb");
	  if (fp == NULL) {
		  printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();
	  }
	  while(fread(cli, sizeof(Cliente), 1, fp)) {
		  if ((strcmp(cli->cpf, cpf) == 0) && (cli->status == 'c')) {
			  fclose(fp);
		return cli;
		  }
	  }
	  fclose(fp);
	  return NULL;
	  if (cli == NULL) {
    	  printf("\n\nCadastro não encontrado!\n\n");
  	  } else {
		      cli->status = 'x';
		      regravar_cliente(cli);
		      free(cli);
	    }
	  free(cpf);
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void regravar_cliente(Cliente* cli) {
	int busca;
	FILE* fp;
	Cliente* ex;

	ex = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "r+b");
	if (fp == NULL) {
		  printf("Não foi possível abrir o arquivo!");
      printf("\n\nTecle ENTER para continuar!\n\n");
	    getchar();;
	}
  while(!feof(fp)) {
	busca = 'x';
  }
	while(fread(ex, sizeof(Cliente), 1, fp) && !busca) {
		fread(ex, sizeof(Cliente), 1, fp);
		if (strcmp(ex->cpf, cli->cpf) == 0) {
			busca = 'c';
			//fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(cli, sizeof(Cliente), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(ex);
}


// ////OPÇÃO CASE 5 (LISTA TODOS OS CLIENTES CADASTRADOS NO SISTEMA)

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
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
