#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila* pfila;
struct fila{
    char *v;
    int ini,fim, N, tamanho;
};

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

int main(){
    pfila queue = criar_fila(500);
    ppilha stack = criar_pilha();

    char entrada[500];
    fgets(entrada, sizeof(entrada), stdin);        

    // MUDAR EXIT
    while(strcmp(entrada, "EXIT\n")) {
        if(entrada[strlen(entrada)-1] == '\n') entrada[strlen(entrada)-1] = '\0';

        if(entrada[0]=='E' && entrada[1]=='X' && entrada[2]=='E' && entrada[3]=='C'){
            char n[5] = {0,0,0,0,0};
            for(int i=5;i<strlen(entrada);i++) n[i-5] = entrada[i];
            int num = atoi(n);
            for(int i=0;i<num;i++){
                char c = pop_fila(queue);
                entrada[i] = c;
            }
            entrada[num] = '\0';
            push_pilha(stack, entrada, num-1);
        }
        else if(entrada[0]=='D' && entrada[1]=='E' && entrada[2]=='L'){
            char n[4] = {0,0,0,0};
            for(int i=4;i<strlen(entrada);i++) n[i-4] = entrada[i];
            int num = atoi(n);
            pop_pilha(stack, num);
        }
        else{
            for(int i=0;i<=strlen(entrada);i++) push_fila(queue, entrada[i]);
        }

        printf("FILA ATUAL: ");
        show_fila(queue);
        printf("\nPILHA ATUAL: ");
        show_pilha(stack->topo);

        printf("\n####\n");
        fgets(entrada, sizeof(entrada), stdin);        
    }
    destruir_fila(queue);
    destruir_pilha(stack);
    return 0;
}
