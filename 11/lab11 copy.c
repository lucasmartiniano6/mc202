#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
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

p_grafo criar_grafo(int n) {
    int i;
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adjacencia = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++)
        g->adjacencia[i] = NULL;
    return g;
}

void libera_lista(p_no lista) {
    if (lista != NULL) {
        libera_lista(lista ->prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo g) {
    int i;
    for (i = 0; i < g->n; i++)
    libera_lista(g->adjacencia[i]);
    free(g->adjacencia);
    free(g);
}


p_no insere_na_lista(p_no lista , int v) {
    p_no novo = malloc(sizeof(struct no));
    novo->v = v;
    novo->prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v) {
    g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
    g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
}

p_no remove_da_lista(p_no lista , int v) {
    p_no proximo;
    if (lista == NULL)
        return NULL;
    else if (lista ->v == v) {
        proximo = lista ->prox;
        free(lista);
        return proximo;
    } else {
    lista ->prox = remove_da_lista(lista ->prox , v);
    return lista;
    }
}

void remove_aresta(p_grafo g, int u, int v) {
    g->adjacencia[u] = remove_da_lista(g->adjacencia[u], v);
    g->adjacencia[v] = remove_da_lista(g->adjacencia[v], u);
}

void imprime_arestas(p_grafo g) {
    int u;
    p_no t;
    for (u = 0; u < g->n; u++)
        for (t = g->adjacencia[u]; t != NULL; t = t->prox)
            printf("{%d,%d}\n", u, t->v);
}

typedef struct fila *p_fila;

struct fila {
    int *v;
    int ini, fim, N, tamanho;
};

p_fila criar_fila(int N) {
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->v = malloc(N * sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
    return f;
}

void destroi_fila(p_fila f){
    free(f->v);
    free(f);
}

void enfileira(p_fila f, int x) {
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    f->tamanho ++;
}

int desenfileira(p_fila f) {
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho --;
    return x;
}

int fila_vazia(p_fila f){
    if(f->N > 0) return 0;
    return 1;
}

int busca_em_largura (p_grafo g, int s, int final) {
    int w, v;
    int *pai = malloc(g->n * sizeof(int));
    int *visitado = malloc(g->n * sizeof(int));
    int *depth = malloc(g->n * sizeof(int));
    p_fila f = criar_fila(2*g->n);
    for (v = 0; v < g->n; v++) {
        pai[v] = -1;
        visitado[v] = 0;
    }
    enfileira(f,s);
    depth[s] = 0;
    pai[s] = s;
    visitado[s] = 1;
    while (! fila_vazia(f)) {
        v = desenfileira(f);
        if(v == final){
            return depth[v];
        }
        for (p_no t = g->adjacencia[v]; t != NULL; t = t->prox){
            if(!visitado[t->v]){
                visitado[t->v] = 1;/* evita repetição na fila */
                pai[t->v] = v;
                depth[t->v] = 1 + depth[v];
                enfileira(f, t->v);
            }
        }
            
    }
    destroi_fila(f);
    free(visitado);
    free(depth);
    return -1;
}


int main(){
    printf("GRAFO AMZ CONSTRUIDO!\n");
    int nc, np; 
    scanf("%d %d", &nc, &np);
    int prox = nc + np;
    int q;
    scanf("%d", &q);

    p_grafo g = criar_grafo(MAXN);

    while(q--){
        int a,b;
        scanf("%d %d", &a, &b);
        insere_aresta(g, a, b);
    }
    
    scanf("%d ", &q);
    while(q--){
        char op; 
        scanf("%c ", &op); 
        int a,b; 
        scanf("%d %d ", &a, &b);
        if(op == 'D'){
            int mx; scanf("%d ", &mx);
            int dist = busca_em_largura(g, a, b);
            printf("DISTANCIA %d -> %d = %d\n", a, b, dist);
            if(dist > mx){
                printf("%d ADICIONADO E CONECTADO A", prox);
                int add[MAXN];
                add[0] = b;
                insere_aresta(g, prox, b);

                int cnt = 1;
                for (p_no t = g->adjacencia[b]; t != NULL; t = t->prox){
                    insere_aresta(g, prox, t->v);
                    add[cnt] = t->v;
                    cnt++;
                }

                for(int i=0;i<cnt;i++){
                    for(int j=i;j<cnt;j++){
                        if(add[j] < add[i]){
                            int temp = add[i];
                            add[i] = add[j];
                            add[j] = temp;
                        }
                    }
                }

                for(int i=0;i<cnt;i++){
                    if(add[i] == prox) continue;
                    printf(" %d", add[i]);
                }
                printf("\n");
                prox++;
            }
        }
        else if(op == 'R'){
            printf("ARESTA %d -> %d REMOVIDO\n", a,b);
            remove_aresta(g, a, b);
        }
    }

    return 0;
}
