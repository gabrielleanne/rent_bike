

typedef struct bike Bike;

struct bike {
    char tipo;
    char aro[7];
    float valor_aluguel;
    char marca[22];
    char cod[9];
    char status;
    char dispon;
};





void modulo_bike(void);
char bikes(void);
Bike* cadastrar_bike(void);
char* cod (void);
void gravar_bike(Bike*);
char editar_bike(void);
Bike* buscar_bike(void);
void excluir_bike(void);
void opcao_editar (void);
void altera_tipo (void);
void altera_aro (void);
void altera_marca (void);
void altera_valor (void);
char tipo_bike (void);
char* ler_cod_bike (void); 
void print_bike(Bike*);
char check_bike (char*);


