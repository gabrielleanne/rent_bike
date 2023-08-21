#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


void tela_menu_principal(void);
void tela_sobre(void);


int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    tela_menu_principal();
    tela_sobre();
    return 0;
}

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("*******************RENT A CAR********************\n");
    printf("-------------------------------------------------\n");
    printf(" 1. M�DULO BIKES DISPON�VEIS ------------DIGITE 1\n");
    printf(" 2. M�DULO CLIENTE-----------------------DIGITE 2\n");
    printf(" 3. MÓDULO PROMOÇÕES----------------------DIGITE 3\n");
    printf(" 4. M�DULO SOBRE N�S---------------------DIGITE 4\n");
    printf(" 0. SAIR---------------------------------DIGITE 0\n");
    printf("\n");
    printf("Escolha sua op��o: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Gestão Escolar                      ///\n");
    printf("///             Developed by @flgorgonio -- since Mar, 2020                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Sistema de Gestão Escolar = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa exemplo utilizado na disciplina DCT1106 - Programação, para   ///\n");
    printf("///  fins didáticos de ilustração. O programa contém os principais módulos  ///\n");
    printf("///  e funcionalidades que serão exigidos na avaliação dos projetos a serem ///\n");
    printf("///  desenvolvidos pelos alunos ao longo da disciplina. Serve como um guia  ///\n");
    printf("///  de consulta e referência para o desenvolvidos dos demais projetos.     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}