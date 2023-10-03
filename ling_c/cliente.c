
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>
#include"cliente.h"
#include"util.h"

/// OPÇÕES PARA MENU CLIENTES 

void modulo_cliente (void) {
   char opcao;
    do {
        opcao = clientes();
        switch(opcao) {
            case '1': 	cadastrar_cliente();
                        break;
            case '2': 	buscar_cliente();
                        break;
            case '3': 	edit_cliente();
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
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Aguarde...\n");
    sleep(1);
    return esc;
}

///OPCÃO CASE 1 (CADASTRA NOVO CLIENTE NO SISTEMA)

void cadastrar_cliente(void) {

    char nome[51];
    char cpf[12];
    char tel[12];
    char end[30];
    char email[40];

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
    verifica_nome(nome);
    printf("\n");
    verifica_cpf (cpf);
    printf("\n");
    verifica_telefone (tel);
    printf("\n");
    printf("Endereço:");
    scanf("%c[A-Z������������ a-z������������]", end);
    getchar();
    printf("\n");
    verifica_email (email);
    printf("\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void verifica_nome (char* nome){
    printf("Nome do cliente: ");
    fgets(nome, 51, stdin);
    while (!valida_nome (nome)) {
        printf("Nome digitado não é válido!\n");
        printf("Informe o nome novamente: ");
        fgets(nome, 51, stdin);
    }
}

void verifica_cpf (char* cpf) {
    printf("CPF:");
    fgets(cpf, 12, stdin);
    while (!valida_cpf (cpf)) {
        printf("CPF inválido!\n");
        printf("Informe o CPF novamente: ");
        fgets(cpf, 12, stdin);
    }
}

void verifica_telefone (char* tel){
    printf("Telefone:");
    fgets(tel, 12, stdin);
    while (!valida_telefone (tel)){
        printf("Telefone inválido!\n");
        printf("Informe o telefone noavamente: ");
        fgets(tel, 12, stdin);
    }
}


void verifica_email (char* email){
    printf("Email:");
    fgets(email, 40, stdin);
    while (!valida_email (email)){
        printf("Email inválido!");
        printf("Informe novamente o email: ");
        fgets(email, 40, stdin);
    }
}
////OPÇÃO CASE 2 (BUSCA CLIENTE CADASTRADO PELO CPF)

void buscar_cliente(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("Informe o cpf do cliente:\n");
    printf("\n");
    printf("\n");
    scanf("%c", &cpf);
    getchar();
    printf("Programa em desenvolvimento\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

////OPÇÃO CASE 3 (EDITA DADOS/INFORMAÇÕES DE CLIENTES CADASTRADOS NO SISTEMA)




void edit_cliente (void) {
    char opcao;

    do {
        opcao = editar_cliente();

        switch (opcao) {
            case '1': 	edit_nome();
                        break;
            case '2': 	edit_cpf();
                        break;
            case '3': 	edit_tel();
                        break;
            case '4': 	edit_end();
                        break;
            case '5':   edit_mail();
                        break;
        } 		
    } while (opcao != '0');
   
}


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
    printf(" 2. EDITAR CPF---------------------------DIGITE 2\n");
    printf(" 3. EDITAR TELEFONE----------------------DIGITE 3\n");
    printf(" 4. EDITAR ENDEREÇO----------------------DIGITE 4\n");
    printf(" 5. EDITAR E-MAIL------------------------DIGITE 5\n");
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



void edit_nome(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o cpf do cliente:\n");
    scanf("%c",&cpf);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void edit_cpf(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o cpf do cliente:\n");
    scanf("%c",&cpf);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void edit_tel(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o cpf do cliente:\n");
    scanf("%c",&cpf);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void edit_end(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o cpf do cliente:\n");
    scanf("%c",&cpf);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void edit_mail(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o cpf do cliente:\n");
    scanf("%c",&cpf);
    getchar();
    printf("\n");
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




///OPÇÃO CASE 4 (EXCLUI CLIENTE CADASTRADO NO SISTEMA)

void excluir_cliente(void) {
    char cpf;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("Informe o cpf do cliente: \n");
    scanf("%c",&cpf);
    printf("\n");
    printf("Programa em desenvolvimento\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


////OPÇÃO CASE 5 (LISTA TODOS OS CLIENTES CADASTRADOS NO SISTEMA)

void listar_clientes(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
