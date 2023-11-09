


typedef struct promo Promo;

struct promo {
    char anuncio[40];
    char val[5];
    char cod[5];
    char status;
};





void modulo_promo(void);
char promo(void);
void listar_promo(void);
Promo* cadastrar_promo(void);
char editar_promo(void);
void excluir_promo(void);
void edit_promo (void);
void edit_anuncio (void);
void edit_validade (void);
void gravar_promo(Promo* pro);
void ler_cod(char* cod);
