#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    printf("GRAFO AMZ CONSTRUIDO!\n");
    int nc, np; 
    scanf("%d %d", &nc, &np);
    int prox = nc + np;
    int q;
    scanf("%d", &q);

    p_grafo g = criar_grafo(100);

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
                int add[100];
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
    destroi_grafo(g);
    return 0;
}
