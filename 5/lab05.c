#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultron.h"
 
void print(pvector* mat, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ", mat[i]->data[j]);
        printf("\n");
    }
}
 
pvector* inl(pvector* mat, int *n, int m){
    pvector* temp = mat;
    mat = malloc(((*n)+1)*sizeof(pvector*));
    for(int i=0;i<*n;i++){
        mat[i] = init(m);
        for(int j=0;j<m;j++) mat[i]->data[j] = temp[i]->data[j];
    }
    
    for(int i=0;i<*n;i++) destruct(temp[i]);
    free(temp);
 
    mat[*n] = init(m);
    for(int j=0;j<m;j++) scanf("%d", &mat[*n]->data[j]);
    (*n)++;
 
    return mat;
}
 
pvector* outl(pvector* mat, int *n, int *m){
    int i;
    scanf("%d", &i);
    for(; i<(*n)-1; i++){
        mat[i] = mat[i+1];
    }
 
    destruct(mat[(*n)-1]);
 
    (*n)--;
    return mat;
}
 
pvector* inc(pvector* mat, int *n, int* m){
    for(int i=0; i<*n; i++){
        int num;
        scanf("%d", &num);
        mat[i] = insert(mat[i], num);
    }
    (*m)++;
    return mat;
}
 
pvector* outc(pvector* mat, int *n, int* m){
    int j;
    scanf("%d", &j);  
    mat[0] = erase(mat[0], j);
    // for(int i=0; i<*n; i++){
    //     mat[i] = erase(mat[i], j);
    // }
 
    (*m)--;
    return mat;
}
 
int main(){
    int n,m;    
    scanf("%d %d", &n, &m);
 
    pvector* mat = malloc(n*sizeof(pvector*));
 
    for(int i=0;i<n;i++){
        mat[i] = init(m);
        for(int j=0;j<m;j++){
            int a; scanf("%d" ,&a);
            insert(mat[i], a);
        }
    }  
 
    int q; scanf("%d", &q);
    while(q--){
        char op[4]; scanf("%s ", op);
        if(!strcmp(op, "OUT")){
            char tipo[2]; scanf("%s ", tipo);
            if(!strcmp(tipo, "C")) mat = outc(mat, &n, &m);
            else if(!strcmp(tipo, "L")) mat = outl(mat, &n, &m);
        }
        else if(!strcmp(op, "IN")){
            char tipo[2]; scanf("%s ", tipo);
            if(!strcmp(tipo, "C")) mat = inc(mat, &n, &m);
            else if(!strcmp(tipo, "L")) mat = inl(mat, &n, m);
        }
        print(mat, n, m);
        printf("###\n");
    }    
    printf("COMBINACAO MATRICIAL FINALIZADA!\n");
   
    for(int i=0;i<n;i++) destruct(mat[i]);
    free(mat);
 
    return 0;
}