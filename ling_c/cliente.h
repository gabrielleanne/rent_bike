


typedef struct cliente Cliente;

struct cliente {
    char nome[51];
    char cpf[12];
    char tel[12];
    char log[20];
    char num[5];
    char bai[15];
    char email[40];
    char status;
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
