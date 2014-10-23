typedef struct pilha Pilha;
typedef struct cartas Cartas;

struct pilha{
    struct cartas *topo;
    int same;
    int tamanho;
};
struct cartas {
    struct cartas *ant;
    int numCarta;
    char cor;
    char naipe;
};

void cria_jogo();
void distribui_cartas(Pilha *p);
