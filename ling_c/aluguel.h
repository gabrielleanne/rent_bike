




typedef struct aluguel Aluguel;

struct aluguel {
    char cod_bike[6];
    int tempo;
    char cpf[12];
    float valor;
    char status;
    char cod_aluguel[4];
    char data[12];
    char vigencia;
};






void modulo_aluguel(void);
char aluguel(void);
Aluguel* novo_aluguel(void);
void gravar_aluguel(Aluguel* aluga);
Aluguel* buscar_aluguel(void);
void print_aluguel(Aluguel* aluga);
void excluir_aluguel(void);
float valor_aluguel (void);
void baixa_aluguel(void);
 






