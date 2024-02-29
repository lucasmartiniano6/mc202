#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

pfila criar_fila(int N){
    pfila f;
    f = malloc(sizeof(struct fila));
    f->v = malloc(N * sizeof(char));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
    return f;
}

void push_fila(pfila f, char c){
    f->v[f->fim] = c;
    f->fim = (f->fim + 1) % f->N;
    f->tamanho++;
}

char pop_fila(pfila f){
    char c = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho--;
    return c;
}

void destruir_fila(pfila f){
    free(f->v);
    free(f);
}

void show_fila(pfila queue){
    for(int i=queue->ini;i<queue->fim;i++){
        if(queue->v[i]=='\0') printf(" ");
        printf("%c", queue->v[i]);
    }
}