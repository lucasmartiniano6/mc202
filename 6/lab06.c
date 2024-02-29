#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no *pno;
struct no{
    int x,y;
    pno prox, ant;
};

typedef struct snake* psnake;
struct snake{
    pno head, tail;
};

psnake init(psnake p){
    p->head = NULL;
    p->tail = NULL;
    return p;
}

psnake push_front(psnake p, int x, int y){
    pno novo = malloc(sizeof(struct no));
    novo->x = x, novo->y = y;

    if(p->head == NULL) p->head = novo;
    if(p->tail == NULL){
        p->tail = novo;
        novo->prox = NULL;
        novo->ant = NULL;
        return p;
    }

    p->head->ant = novo;
    novo->prox = p->head;
    p->head = novo;
    novo->ant = NULL;
    return p;
}

psnake push_back(psnake p, int x, int y){
    pno novo = malloc(sizeof(struct no));
    novo->x = x, novo->y = y;

    if(p->head == NULL) p->head = novo;
    if(p->tail == NULL) {
        p->tail = novo;
        novo->prox = NULL;
        novo->ant = NULL;
        return p;
    }

    p->tail->prox = novo;
    novo->ant = p->tail;
    p->tail = novo;
    novo->prox = NULL;
    return p;
}

psnake pop_back(psnake p){
    p->tail = p->tail->ant;
    free(p->tail->prox);
    p->tail->prox = NULL;
    return p;
}

void destruct(pno head){
    if(head!=NULL){
        destruct(head->prox);
        free(head);
    }
}

void imprime(psnake p){
    for(pno atual = p->head; atual!=NULL; atual=atual->prox)
        printf("%d %d\n", atual->x, atual->y);
}

void imprime_matriz(char** mat, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }
}

int main(){
    psnake player = malloc(sizeof(struct snake));
    player = init(player);
    
    int n,m; scanf("%d %d", &n, &m); 
    char** mat = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        mat[i] = malloc(m*sizeof(char));
        for(int j=0;j<m;j++){
            mat[i][j] = '_';
        }
    }

    imprime(player);
    imprime_matriz(mat, n, m);
    destruct(player->head);

    for(int i=0;i<n;i++)
        free(mat[i]);
    free(mat);
    return 0;
}