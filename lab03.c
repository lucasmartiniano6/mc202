#include "represa.h"
#include <stdio.h>

int main(){
    Represa vetor[1000];
    int n;
    scanf("%i", &n);
    for(int i=0;i<n;i++){
        vetor[i] = read_rep();
    } 
    padronizar_nome(vetor,n);
    for(int i=0;i<n;i++){
        print_rep(vetor[i]);
    } 
    return 0;
}