#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<locale.h>

///////////////////////////////////////////////////////////////
//MENU PRINCIPAL
char menu_principal(void);
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// MÓDULOS GERAIS
void modulo_bike(void);

void modulo_aluguel(void);
void modulo_promo(void);
void modulo_sobre(void);
//////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//MÓDULO BIKES
char bikes(void);
void cadastrar_bike(void);
void editar_bike(void);
void buscar_bike(void);
void excluir_bike(void);
void listar_bikes(void);
////////////////////////////////////////////////////////////

//MÓDULO CLIENTES

//////////////////////////////////////////////////////////////


//MÓDULO PROMOÇÕES

char promo(void);
void listar_promo(void);
void cadastrar_promo(void);
void editar_promo(void);
void excluir_promo(void);

///////////////////////////////////////////////////////////////////

// MÓDULO ALUGUEL

char aluguel(void);
void bike_disponivel(void);
void alugar_bike(void);
void buscar_aluguel(void);
void excluir_aluguel(void);
void listar_aluguel (void);

///////////////////////////////////////////////////////////////////



int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    char opcao;

    do {
        opcao = menu_principal();
        switch(opcao) {
          case '1': modulo_bike();
                    break;
          case '2': modulo_cliente();
                    break;
          case '3': modulo_aluguel();
                    break;
          case '4': modulo_promo();
                    break;
          case '5': modulo_sobre();
                    break;
        } 	
    } while (opcao != '0');
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

char menu_principal(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. BIKES--------------------------------DIGITE 1\n");
    printf(" 2. CLIENTES-----------------------------DIGITE 2\n");
    printf(" 3. ALUGUEL------------------------------DIGITE 3\n");
    printf(" 4. PROMOÇOES----------------------------DIGITE 4\n");
    printf(" 5. SOBRE NÓS----------------------------DIGITE 5\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>>Aguarde\n");
    return esc;
}

////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////



void modulo_bike (void) {
   char opcao;
    do {
        opcao = bikes();
        switch(opcao) {
            case '1': 	cadastrar_bike();
                        break;
            case '2': 	editar_bike();
                        break;
            case '3': 	buscar_bike();
                        break;
            case '4': 	excluir_bike();
                        break;
            case '5':   listar_bikes();
                        break;
        } 		
    } while (opcao != '0');
}



char bikes(void) {

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

void cadastrar_bike(void) {

    char tipo[30];
    char aro[25];
    char quadro[22];
    char marca[20];
    char cod[15];

    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Vamos cadastrar uma bike no sistema!\n");
    printf("\n");
    printf("\n");
    printf("Tipo da bike (Mountain Bike, Elétrica, Estrada/speed ou Urbana):\n");
    scanf("%c", tipo);
    getchar();
    printf("Aro da bike:\n");
    scanf("%c",aro);
    getchar();
    printf("Tamanho de quadro:\n");
    scanf("%c", quadro);
    getchar();
    printf("Marca da bike:\n");
    scanf("%c", marca);
    getchar();
    printf("Código gerado da bike:\n");
    scanf("%c", cod);
    getchar();
    printf("\n");
    printf("\n");
     printf("Cadastro realizado com sucesso!\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void editar_bike(void) {
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
    printf(" 3. EDITAR TAMANHO DE QUADRO-------------DIGITE 3\n");
    printf(" 4. EDITAR MARCA-------------------------DIGITE 4\n");
    printf(" 5. EDITAR CÓDIGO------------------------DIGITE 5\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void buscar_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:");
    scanf("%c",&cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_bike(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da bike:");
    scanf("%c", &cod);
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listar_bikes(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------MENU BIKES--------------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void modulo_promo (void) {
   char opcao;
    do {
        opcao = promo();
        switch(opcao) {
            case '1': listar_promo();
                        break;
            case '2': 	cadastrar_promo();
                        break;
            case '3': 	editar_promo();
                        break;
            case '4': 	excluir_promo();
                        break;
        } 		
    } while (opcao != '0');
}


char promo(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. LISTAR PROMOÇÕES --------------------DIGITE 1\n");
    printf(" 2. CADASTRAR PROMOÇÃO-------------------DIGITE 2\n");
    printf(" 3. EDITAR PROMOÇÃO----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR PROMOÇÃO---------------------DIGITE 4\n");
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

void listar_promo(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void cadastrar_promo(void) {

    char anuncio[40];
    char val[12];
    char cod[12];

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
    scanf("%c",anuncio);
    getchar();
    printf("\n");
    printf("Validade:\n");
    scanf("%c",val);
    getchar();
    printf("\n");
    printf("Código gerado da promoção:\n");
    scanf("%c", cod);
    printf("\n");
    printf("\n");
    printf("Cadastro realizado com sucesso!");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

void editar_promo(void) {
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
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_promo(void) {
    char cod;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU PROMOÇÕES-----------------\n");
    printf("-------------------------------------------------\n");
    printf("Informe o código da promoção:");
    scanf("%c", &cod);
    getchar();
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void modulo_aluguel (void) {
   char opcao;
    do {
        opcao = aluguel();
        switch(opcao) {
            case '1': 	bike_disponivel();
                        break;
            case '2': 	alugar_bike();
                        break;
            case '3': 	buscar_aluguel();
                        break;
            case '4': 	excluir_aluguel();
                        break;
            case '5':   listar_aluguel();
                        break;
        } 		
    } while (opcao != '0');
}

char aluguel(void) {
    char esc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. BIKES DISPONÍVEIS--------------------DIGITE 1\n");
    printf(" 2. ALUGAR BIKE--------------------------DIGITE 2\n");
    printf(" 3. BUSCAR ALUGUEL-----------------------DIGITE 3\n");
    printf(" 4. EXCLUIR ALUGUEL----------------------DIGITE 4\n");
    printf(" 0. VOLTAR-------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &esc);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}


void bike_disponivel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void alugar_bike(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  
}

void buscar_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  
}

void excluir_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  
}

void listar_aluguel(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A BIKE*******************\n");
    printf("-------------------------------------------------\n");
    printf("------------------MENU ALUGUEL-------------------\n");
    printf("-------------------------------------------------\n");
    printf("programa em desenvolvimento...");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  
}


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void modulo_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("            * * * * RENT A BIKE * * * *\n");
    printf("\n");
    printf("  Programa desenvolvido na linguagem C para a   \n");
    printf("  disciplina de Programação do curso de Sistemas\n");
    printf("  de Informação. O programa será desenvolvido   \n");
    printf("  para uma empresa de aluguel de bicicletas -   \n");
    printf("  a Rent a Bike.                                \n");
    printf("  Desenvolvedora: Anne Gabrielle!!!!!           \n");                  
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
