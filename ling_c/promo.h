


typedef struct promo Promo;

struct promo {
    char anuncio[40];
    char val[12];
    char cod[12];
};





void modulo_promo(void);
char promo(void);
void listar_promo(void);
void cadastrar_promo(void);
char editar_promo(void);
void excluir_promo(void);
void edit_promo (void);
void edit_anuncio (void);
void edit_validade (void);
