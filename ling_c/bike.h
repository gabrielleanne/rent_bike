

typedef struct bike Bike;

struct bike {
    //char tipo [14];
    char aro[3];
    char valor_aluguel[5];
    char marca[20];
    char cod[10];
 
};





void modulo_bike(void);
char bikes(void);
void cadastrar_bike(void);
char editar_bike(void);
void buscar_bike(void);
void excluir_bike(void);
void listar_bikes(void);
void opcao_editar (void);
void altera_tipo (void);
void altera_aro (void);
void altera_marca (void);
void altera_valor (void);
void verifica_aro (char*);
char tipo_bike (void);


