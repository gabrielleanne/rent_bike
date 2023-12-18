




typedef struct aluguel Aluguel;

struct aluguel {
    char cod_bike[9];
    int tempo;
    char cpf[14];
    float valor;
    char status;
    char cod_aluguel[9];
    char data[13];
    char vigencia;
};






void modulo_aluguel(void);
char aluguel(void);
Aluguel* novo_aluguel(void);
void gravar_aluguel(Aluguel* aluga);
char* cod_aluguel(void);
void print_aluguel(Aluguel* aluga);
void excluir_aluguel(void);
float valor_aluguel (int tempo);
char* codi (void);
Aluguel* buscar_aluguel(void);
void disponibilidade_n(char* cod);
void disponibilidade_s(const char* cod_bike);
 






