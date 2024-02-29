#include <stdio.h>
#include <stdlib.h>

typedef struct no* pno;
struct no{
    char str[50]; 
    int n;
    pno prox;
};

typedef struct pilha* ppilha;
struct pilha{
    pno topo;
};

ppilha criar_pilha();

void push_pilha(ppilha pilha, char entrada[], int size);

void pop_pilha(ppilha pilha, int m);

void dest_pilha_rec(pno topo);
void destruir_pilha(ppilha pilha);

void show_pilha(pno topo);