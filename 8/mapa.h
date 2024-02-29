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

pno_mapa buscar_mapa(pno_mapa raiz, char chave[]);

pno_mapa inserir_mapa(pno_mapa raiz, char chave[]);

pno_mapa minimo_mapa(pno_mapa raiz);

pno_mapa anscestral_a_direita_mapa(pno_mapa x);

pno_mapa sucessor_mapa(pno_mapa x);

void remover_sucessor_mapa(pno_mapa raiz);

pno_mapa remover_rec_mapa(pno_mapa raiz , char chave[]);

void imprimir_mapa(pno_mapa node);

// ------------------------------------
// VISITA -----------------------------
typedef struct no_visita* pno_visita;
struct no_visita{
    int data;
    char nome[50];
    int sauron;
    pno_visita esq, dir, pai;
};

pno_visita buscar_visita(pno_visita raiz, int chave);

pno_visita inserir_visita(pno_visita raiz, int chave, char nome[], int sauron);

pno_visita minimo_visita(pno_visita raiz);

pno_visita anscestral_a_direita_visita(pno_visita x);

pno_visita sucessor_visita(pno_visita x);

void remover_sucessor_visita(pno_visita raiz);

pno_visita remover_rec_visita(pno_visita raiz , int chave);

void relatorio_data(pno_visita node, int min, int max);

void relatorio_pista(pno_visita node, int min, int max);

// ------------------------------------

void destruct_mapa(pno_mapa node);
void destruct_vis(pno_visita node);