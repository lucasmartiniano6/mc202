#include "mapa.h"

int main(){
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
    
    destruct_mapa(mapa);
    destruct_vis(visita);
    return 0;
}