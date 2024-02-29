typedef struct no *p_no;

struct no {
    int v;
    p_no prox;
};

typedef struct grafo *p_grafo;

struct grafo {
    p_no *adjacencia;
    int n;
};

p_grafo criar_grafo(int n);

void libera_lista(p_no lista);


void destroi_grafo(p_grafo g);

p_no insere_na_lista(p_no lista , int v);


void insere_aresta(p_grafo g, int u, int v);


p_no remove_da_lista(p_no lista , int v);


void remove_aresta(p_grafo g, int u, int v);


void imprime_arestas(p_grafo g);

typedef struct fila *p_fila;

struct fila {
    int *v;
    int ini, fim, N, tamanho;
};

p_fila criar_fila(int N);

void destroi_fila(p_fila f);

void enfileira(p_fila f, int x);


int desenfileira(p_fila f);


int fila_vazia(p_fila f);


int busca_em_largura (p_grafo g, int s, int final);