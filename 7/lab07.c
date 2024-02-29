#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

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
