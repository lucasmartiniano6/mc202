typedef struct fila* pfila;

struct fila{
    char *v;
    int ini,fim, N, tamanho;
};

pfila criar_fila(int N);

void push_fila(pfila f, char c);

char pop_fila(pfila f);

void destruir_fila(pfila f);

void show_fila(pfila queue);