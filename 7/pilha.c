#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

ppilha criar_pilha(){
    ppilha pilha = malloc(sizeof(struct pilha));
    pilha->topo = NULL;
    return pilha;
}

void push_pilha(ppilha pilha, char entrada[], int size){
    if(pilha->topo == NULL){
        pno novo = malloc(sizeof(struct no));
        novo->n = 0;
        novo->prox = pilha->topo;
        pilha->topo = novo;
    }

    if(pilha->topo->n + size < 50){
        for(int i=pilha->topo->n;i<=pilha->topo->n+size;i++){
            pilha->topo->str[i] = entrada[i-pilha->topo->n];
        }
        pilha->topo->n += size+1;
    }
    else{
        pno novo = malloc(sizeof(struct no));
        novo->n = 0;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        push_pilha(pilha, entrada, size);
    }
}

void pop_pilha(ppilha pilha, int m){
    if(m < pilha->topo->n){
        while(pilha->topo->str[pilha->topo->n] == '\0'){
            pilha->topo->n--;
        }
        pilha->topo->n -= m-1;
        pilha->topo->str[pilha->topo->n] = '\0';

        if(pilha->topo->n == 0) pilha->topo->n = 0;
        else pilha->topo->n += 1;
    }
    else{
        m -= pilha->topo->n - 1;
        pno topo = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(topo);
        if(m>0) pop_pilha(pilha, m);
    }
}

void dest_pilha_rec(pno topo){
    if(topo != NULL){
        dest_pilha_rec(topo->prox);
        free(topo);
    }
}
void destruir_pilha(ppilha pilha){
    dest_pilha_rec(pilha->topo);
    free(pilha);
}

void show_pilha(pno topo){
    if(topo != NULL){
        show_pilha(topo->prox);
        for(int i=0;i<topo->n;i++){
            if(topo->str[i] == '\0') printf(" ");
            printf("%c", topo->str[i]);
        }
    }
}