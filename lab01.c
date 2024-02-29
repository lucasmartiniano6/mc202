#include <stdio.h>

void printVector(int u[], int t)
{
  for(int i=0;i<t;i++){
    if(i==t-1) printf("%d \n",u[i]);
    else printf("%d ",u[i]);
  }
}

void banner(int u[],int t)
{
  int b;
  int conjunto[1000];
  scanf("%d",&b);
  for(int i=0;i<b;i++) 
    scanf("%d",&conjunto[i]);

  for(int i=0;i<t;i++){
    int ok = 0;
    for(int j=0;j<b;j++){
      if(u[i] == conjunto[j]) ok = 1;
    }
    if(!ok) u[i]=0;
  }
}

void mobius(int u[], int t)
{
  int m;
  scanf("%d",&m);
  for(int i=0;i<t;i++)
    if(i%2 != 0) u[i]*=m;  
}

void ciclico(int u[], int t)
{
  int p;
  scanf("%d",&p);
  int aux[1000];
  for(int i=0;i<t;i++){
    int nova_posicao = (i+p)%t;
    aux[nova_posicao] = u[i];
  }
  for(int i=0;i<t;i++){
    u[i] = aux[i];
  }
}

void inversao(int u[], int t)
{
  for(int i=0;i<t/2;i++){
    int aux = u[i];
    u[i] = u[t-1-i];
    u[t-1-i] = aux;
  }
}

int main()
{
  int t;
  int u[1000];
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    scanf("%d",&u[i]);
  }
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int operacao;
    scanf("%d",&operacao);
    if (operacao == 1) banner(u,t);
    else if (operacao == 2) mobius(u,t); 
    else if (operacao == 3) ciclico(u,t); 
    else inversao(u,t);
    printVector(u,t);
  }

  return 0;
}
