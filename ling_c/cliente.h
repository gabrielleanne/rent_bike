


typedef struct cliente Cliente;

struct cliente {
    char nome[51];
    char cpf[12];
    char tel[12];
    char log[20];
    char num[5];
    char bai[15];
    char email[40];
};



void modulo_cliente(void);
char clientes(void);
void cadastrar_cliente(void);
void buscar_cliente(void);
char editar_cliente(void);
void excluir_cliente(void);
void listar_clientes(void);
void edit_nome (void);
void edit_end (void);
void edit_mail (void);
void edit_tel (void);
void edit_cpf (void);
void edit_cliente (void);
char alterar_end (void);
void verifica_nome (char*);
void verifica_cpf (char*);
void verifica_telefone(char*);
void verifica_logradouro(char*);
void verifica_email (char*);
void verifica_numero (char*);
void verifica_bairro (char*);
void altera_logradouro (void);
void altera_numero (void);
void altera_bairro (void);