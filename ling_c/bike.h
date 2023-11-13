

typedef struct bike Bike;

struct bike {
    char tipo;
    char aro[3];
    float valor_aluguel;
    char marca[20];
    char cod[2];
    char status;
};





void modulo_bike(void);
char bikes(void);
Bike* cadastrar_bike(void);
void gravar_bike(Bike* bike);
char editar_bike(void);
Bike* buscar_bike(void);
void excluir_bike(void);
void opcao_editar (void);
void altera_tipo (void);
void altera_aro (void);
void altera_marca (void);
void altera_valor (void);
char tipo_bike (void);
void ler_cod_bike (char* cod);
void print_bike(Bike* bike);


