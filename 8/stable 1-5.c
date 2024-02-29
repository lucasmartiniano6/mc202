#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAPA -----------------------------

typedef struct no_mapa* pno_mapa;
struct no_mapa{
    char nome[50];
    int vis;
    pno_mapa esq, dir, pai;
};

pno_mapa buscar_mapa(pno_mapa raiz, char chave[]){
    if(raiz == NULL || !strcmp(chave, raiz->nome) ) return raiz;

    if(strcmp(chave,raiz->nome) < 0) return buscar_mapa(raiz->esq, chave);
    else return buscar_mapa(raiz->dir, chave);
}

pno_mapa inserir_mapa(pno_mapa raiz, char chave[]){
    pno_mapa novo;
    if(raiz == NULL){
        novo = malloc(sizeof(struct no_mapa));
        novo->esq = novo->dir = NULL;
        novo->vis = 1;
        strcpy(novo->nome, chave);
        return novo;
    }

    if(strcmp(chave,raiz->nome) < 0){
        raiz->esq = inserir_mapa(raiz->esq, chave);
        raiz->esq->pai = raiz;
    }
    else{
        raiz->dir = inserir_mapa(raiz->dir, chave);
        raiz->dir->pai = raiz;
    }

    return raiz;
}

pno_mapa minimo_mapa(pno_mapa raiz){
    if(raiz == NULL || raiz->esq == NULL) return raiz;
    return minimo_mapa(raiz->esq);
}

pno_mapa anscestral_a_direita_mapa(pno_mapa x){
    if(x==NULL) return NULL;
    if(x->pai == NULL || x->pai->esq == x) return x->pai;
    else return anscestral_a_direita_mapa(x->pai);
}

pno_mapa sucessor_mapa(pno_mapa x){
    if(x->dir != NULL)
        return minimo_mapa(x->dir);
    return anscestral_a_direita_mapa(x);
}

void remover_sucessor_mapa(pno_mapa raiz){
    pno_mapa min = raiz->dir;
    pno_mapa pai = raiz;
    while(min->esq != NULL){
        pai = min;
        min = min->esq;
    }    
    if(pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;

    strcpy(raiz->nome, min->nome);
    raiz->vis = min->vis;
}

pno_mapa remover_rec_mapa(pno_mapa raiz , char chave[]) {
    if (raiz == NULL) return NULL;

    if(strcmp(chave, raiz->nome) < 0)
        raiz->esq = remover_rec_mapa(raiz->esq , chave);
    else if(strcmp(chave, raiz->nome) > 0)
        raiz->dir = remover_rec_mapa(raiz->dir , chave);
    else if (raiz->esq == NULL)
        return raiz->dir;
    else if (raiz->dir == NULL)
        return raiz->esq;
    else
        remover_sucessor_mapa(raiz);
    return raiz;
}

void imprimir_mapa(pno_mapa node){
    if(node == NULL) return;

    printf("%s\n", node->nome);
    imprimir_mapa(node->esq);
    imprimir_mapa(node->dir);
}

// ------------------------------------
// VISITA -----------------------------
typedef struct no_visita* pno_visita;
struct no_visita{
    int data;
    char nome[50];
    int sauron;
    pno_visita esq, dir, pai;
};

pno_visita buscar_visita(pno_visita raiz, int chave){
    if(raiz == NULL || raiz->data == chave) return raiz;

    if(chave < raiz->data) return buscar_visita(raiz->esq, chave);
    else return buscar_visita(raiz->dir, chave);
}

pno_visita inserir_visita(pno_visita raiz, int chave, char nome[], int sauron){
    pno_visita novo;
    if(raiz == NULL){
        novo = malloc(sizeof(struct no_visita));
        novo->esq = novo->dir = NULL;
        novo->sauron = sauron;
        novo->data = chave;
        strcpy(novo->nome, nome);
        return novo;
    }

    if(chave < raiz->data){
        raiz->esq = inserir_visita(raiz->esq, chave, nome, sauron);
        raiz->esq->pai = raiz;
    }
    else{
        raiz->dir = inserir_visita(raiz->dir, chave, nome, sauron);
        raiz->dir->pai = raiz;
    }

    return raiz;
}

pno_visita minimo_visita(pno_visita raiz){
    if(raiz == NULL || raiz->esq == NULL) return raiz;
    return minimo_visita(raiz->esq);
}

pno_visita anscestral_a_direita_visita(pno_visita x){
    if(x==NULL) return NULL;
    if(x->pai == NULL || x->pai->esq == x) return x->pai;
    else return anscestral_a_direita_visita(x->pai);
}

pno_visita sucessor_visita(pno_visita x){
    if(x->dir != NULL)
        return minimo_visita(x->dir);
    return anscestral_a_direita_visita(x);
}

void remover_sucessor_visita(pno_visita raiz){
    pno_visita min = raiz->dir;
    pno_visita pai = raiz;
    while(min->esq != NULL){
        pai = min;
        min = min->esq;
    }    
    if(pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;

    raiz->data = min->data;
    strcpy(raiz->nome, min->nome);
    raiz->sauron = min->sauron;
}

pno_visita remover_rec_visita(pno_visita raiz , int chave) {
    if (raiz == NULL) return NULL;

    if(chave < raiz->data)
        raiz->esq = remover_rec_visita(raiz->esq , chave);
    else if(chave > raiz->data)
        raiz->dir = remover_rec_visita(raiz->dir , chave);
    else if (raiz->esq == NULL)
        return raiz->dir;
    else if (raiz->dir == NULL)
        return raiz->esq;
    else
        remover_sucessor_visita(raiz);
    return raiz;
}

void relatorio_data(pno_visita node, int min, int max){
    if(node == NULL) return;

    relatorio_data(node->esq, min, max);

    if(min <= node->data && node->data <= max){
        printf("DATA: %i\n", node->data);
        printf("CIDADE: %s\n", node->nome);
        printf("####\n");
    }

    relatorio_data(node->dir, min, max);
}

void relatorio_pista(pno_visita node, int min, int max){
    if(node == NULL) return;


    relatorio_pista(node->dir, min, max);

    if(min <= node->data && node->data <= max && node->sauron){
        printf("DATA: %i\n", node->data);
        printf("CIDADE: %s\n", node->nome);
        printf("####\n");
    }

    relatorio_pista(node->esq, min, max);

}

// ------------------------------------


int main(){
    // pno_mapa mapa;
    // mapa = inserir_mapa(mapa, "k");
    // pno_mapa find = buscar_mapa(mapa, "d");
    // if(find == NULL){
    //     mapa = inserir_mapa(mapa, "d");        
    // }
    // else{
    //     find->vis += 1;
    // }
    // mapa = remover_rec_mapa(mapa, "c");
    // imprimir_mapa(mapa);
    
    // pno_visita visita;
    // visita = inserir_visita(visita, 5, "cinco", 0);
    // pno_visita find = buscar_visita(visita, 7);
    // if(find == NULL){
    //     visita = inserir_visita(visita, 7, "sete", 1);
    // }
    // else {}
    // relatorio_data(visita, 3, 5);
    
    pno_mapa mapa = NULL;
    pno_visita visita = NULL;
    int q; scanf("%d", &q);
    while(q--){
        char op[50]; scanf("%s", op);
        if(!strcmp(op, "insere_visita")){
            char nome[50]; scanf("%s", nome);
            int data; scanf("%d", &data);    
            int pista; scanf("%d", &pista);    

            pno_mapa find = buscar_mapa(mapa, nome);
            if(find==NULL){
                mapa = inserir_mapa(mapa, nome);
                printf("ARVORE: MAPA\n");
                printf("CIDADE: %s\n", nome);
                printf("INSERIDO COM SUCESSO!\n");
                printf("####\n");
            }
            else{
                find->vis += 1;
            }

            visita = inserir_visita(visita, data, nome, pista);
            printf("ARVORE: VISITA\n");
            printf("DATA: %i\n", data);
            printf("CIDADE: %s\n", nome);
            printf("INSERIDO COM SUCESSO!\n");
            printf("####\n");
        }
        else if(!strcmp(op, "exclui_visita")){
            int data; scanf("%d", &data);
            pno_visita find_vis = buscar_visita(visita, data);
            char nome[50]; strcpy(nome, find_vis->nome);
            visita = remover_rec_visita(visita, data);
            pno_mapa find_mapa = buscar_mapa(mapa, nome);
            find_mapa->vis -= 1;
            printf("CIDADE: %s\n", nome);
            printf("QUANTIDADE DE VISITAS RESTANTES: %i\n", find_mapa->vis);
            printf("####\n");
            if(find_mapa->vis <= 0)
                mapa = remover_rec_mapa(mapa, nome);                
        }
        else if(!strcmp(op, "relatorio_data")){
            printf("--VISITAS--\n");
            int min,max;
            scanf("%d", &min); scanf("%d", &max);
            relatorio_data(visita, min, max);
        }
        else if(!strcmp(op, "relatorio_pista")){
            printf("--PISTAS--\n");
            int min,max;
            scanf("%d", &min); scanf("%d", &max);
            relatorio_pista(visita, min, max);
        }
    }        
    return 0;
}