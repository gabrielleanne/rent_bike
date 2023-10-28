
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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
    scanf("%c",&esc);
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
    char log[20];
    char num[5];
    char bai[15];
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
    printf("Dados do Endereço:\n");
    printf("\n");
    verifica_logradouro (log);
    printf("\n");
    verifica_numero (num);
    printf("\n");
    verifica_bairro (bai);
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
    getchar();
}

void verifica_cpf (char* cpf) {
    printf("Informe o CPF (apenas números):");
    fgets(cpf, 12, stdin);
    while (!valida_cpf (cpf)) {
        printf("CPF inválido!\n");
        printf("Informe o CPF novamente (apenas números): ");
        fgets(cpf, 12, stdin);
    }
    getchar();
}

void verifica_telefone (char* tel){
    printf("Informe o telefone com DDD (apenas números):");
    fgets(tel, 12, stdin);
    while (!valida_telefone (tel)) {
        printf("Telefone inválido!\n");
        printf("Informe o telefone com DDD novamente: ");
        fgets(tel, 12, stdin);
    }
    getchar();
}


void verifica_logradouro (char* log) {
    printf("Logradouro: ");
    fgets(log, 20, stdin);
    while (!valida_logradouro (log)) {
        printf("Logradouro digitado não é válido!\n");
        printf("Informe o logradouro novamente: ");
        fgets(log, 20, stdin);
    }
    getchar();
}


void verifica_numero (char* num){
    printf("Número: ");
    fgets(num, 5, stdin);
    while (!valida_numero (num)) {
        printf("Número digitado não é válido!\n");
        printf("Informe o número novamente: ");
        fgets(num, 5, stdin);
    }
    getchar();
}

void verifica_bairro (char* bai){
    printf("Bairro: ");
    fgets(bai, 15, stdin);
    while (!valida_bairro (bai)) {
        printf("Bairro digitado não é válido!\n");
        printf("Informe o bairro novamente: ");
        fgets(bai, 15, stdin);
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
    getchar();
}
////OPÇÃO CASE 2 (BUSCA CLIENTE CADASTRADO PELO CPF)

void buscar_cliente(void) {
    char cpf [12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    verifica_cpf (cpf);
    printf("\n");
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
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_cpf (cpf);
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void edit_cpf(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_cpf (cpf);
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void edit_tel(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_cpf (cpf);
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


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
    printf("Vamos editar dados do endereço!");
    printf("\n");
    printf("\n");
    printf(" 1. EDITAR LOGRADOURO--------------------DIGITE 1\n");
    printf(" 2. EDITAR NÚMERO------------------------DIGITE 2\n");
    printf(" 3. EDITAR BAIRRO------------------------DIGITE 3\n");
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


void altera_logradouro(void) {
    char log[20];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_logradouro (log);
    printf("\n");
    printf("\n");
    printf("Logradouro alterado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}


void altera_numero(void) {
    char num[5];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_numero (num);
    printf("\n");
    printf("\n");
    printf("Número alterado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}



void altera_bairro(void) {
    char bai[15];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_bairro (bai);
    printf("\n");
    printf("\n");
    printf("Bairro alterado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



void edit_mail(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    verifica_cpf (cpf);
    printf("\n");
    printf("Programa em desenvolvimento!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




///OPÇÃO CASE 4 (EXCLUI CLIENTE CADASTRADO NO SISTEMA)

void excluir_cliente(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU CLIENTES------------------\n");
    printf("-------------------------------------------------\n");
    printf("\n");
    printf("\n");
    verifica_cpf (cpf);
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
