


typedef struct cliente Cliente;

struct cliente {
    char nome[51];
    char cpf[14];
    char tel[14];
    char log[27];
    char num[7];
    char bai[20];
    char email[50];
    char status;
    Cliente* prox;
};



void modulo_cliente(void);
char clientes(void);
Cliente* cadastrar_cliente(void);
void gravar_cliente(Cliente* cli);
Cliente* buscar_cliente(void);
char* ler_cpf(void);
void print_cliente(Cliente* cli);
char editar_cliente(void);
void excluir_cliente(void);
void regravar_cliente(Cliente*);
void edit_nome (void);
void edit_end (void);
void edit_mail (void);
void edit_tel (void);
void edit_cliente (void);
char alterar_end (void);
void altera_logradouro (void);
void altera_numero (void);
void altera_bairro (void);
int cpf_repeted(char* cpf);
