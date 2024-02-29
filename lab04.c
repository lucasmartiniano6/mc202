#include <stdio.h>
#include <stdlib.h>

void append_elite(int* v, int best_begin, int best_end, int* elite, int* tamanho_elite, int* atual_elite){
    if(best_end-best_begin + *atual_elite < *tamanho_elite){
        int cnt = best_begin;
        for(int i=*atual_elite;i<*atual_elite+best_end-best_begin;i++){
            elite[i] = v[cnt]; cnt++;
        }
        *atual_elite += best_end-best_begin; 
    }

}

void normalize(int* elite, int n){
    int s=0;
    for(int i=0;i<n;i++) s+= elite[i];
    s /= n;
    for(int i=0;i<n;i++) elite[i] -= s;
}

int main(){
    int q, tamanho_elite, atual_elite=0;
    scanf("%i", &q);
    tamanho_elite = 100;
    int* elite = malloc(tamanho_elite*sizeof(int));
    for(int k=0;k<q;k++){
        int n,soma=0,best=0,begin=0,end=0,best_begin,best_end;
        scanf("%i", &n);
        int* vetor = malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            scanf("%i", &vetor[i]);
            if(soma+vetor[i]>vetor[i]){
                soma += vetor[i];
                end++;
            }
            else {
                soma = vetor[i];
                begin = i;
                end = i+1;
            } 

            if(soma>best) {
                best = soma;
                best_begin = begin;
                best_end = end;
            }
        }
        printf("Sub-tropa Forte %i: ", k+1);
        for(int i=best_begin;i<best_end-1;i++){
            printf("%i ", vetor[i]);
        }
        printf("%i\n", vetor[best_end-1]);
        
        append_elite(vetor, best_begin, best_end, elite, &tamanho_elite, &atual_elite);
        free(vetor); 
    }

    normalize(elite, atual_elite);
    int soma=0,best=0,begin=0,end=0,best_begin,best_end;
    for(int i=0;i<atual_elite;i++){
            if(soma+elite[i]>elite[i]){
                soma += elite[i];
                end++;
            }
            else {
                soma = elite[i];
                begin = i;
                end = i+1;
            } 

            if(soma>best) {
                best = soma;
                best_begin = begin;
                best_end = end;
            }
    }

    for(int i=best_begin;i<best_end;i++) printf("%i", elite[i]);
    printf("\n"); 
    free(elite);
    return 0;
}