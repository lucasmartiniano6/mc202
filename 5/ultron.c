#include <stdio.h>
#include <stdlib.h>
#include "ultron.h"
 
pvector init(int cp){
    pvector v;
    v = malloc(sizeof(struct vector));
    v->data = malloc(cp*sizeof(int));
    v->size = 0;
    v->capacity = cp;
    return v;
}
 
pvector insert(pvector v, int x){
    if(v->size == v->capacity){
        int *temp = v->data;
        v->capacity *= 2;
        v->data = malloc(v->capacity*sizeof(int));
        for(int i=0;i<v->size;i++) v->data[i]=temp[i];
        free(temp);
    }
 
    int i;
    for(i=v->size-1; i>=0 && v->data[i]>x; i--)
        v->data[i+1] = v->data[i];
    v->data[i+1] = x;
    v->size++;
    return v;
}
 
pvector erase(pvector v, int i){
    printf("erasing index ");
    printf("%d", i);
    printf("\n");
    for(int j=0;j<v->size; j++){
        printf("%d ", v->data[j]);
    }
    printf("\n");
    printf("going\n");
    for(; i < v->size-1; i++)
        v->data[i] = v->data[i+1];
    v->size--;
 
    if(v->size < 0.25 * v->capacity){
        int *temp = v->data;
        v->capacity /= 2;
        v->data = malloc(v->capacity*sizeof(int));
        for(int i=0;i<v->size;i++) v->data[i]=temp[i];
        free(temp);
    }
    return v;
}
 
void destruct(pvector v){
    free(v->data);
}