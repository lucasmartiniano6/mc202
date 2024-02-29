#include <stdio.h>
#include <string.h>

#define MAXN 99

void setMat(int mat[][MAXN], int n)
{
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j+=6){
      mat[i][j] = 1;
      mat[i][j+1] = 1;
      mat[i][j+2] = 1;
    }
  }
}

void printMat(int mat[][MAXN], int n)
{
  printf("\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ", mat[i][j]);
    } 
    printf("\n");
  }
}

void transposeUtil(int x[][MAXN], int y[][MAXN], int n)
{
  int trans[MAXN][MAXN] = {0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      trans[i][j] = y[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      trans[i][j] = x[j][i];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      y[i][j] = trans[i][j];
    }
  }
  printMat(y,n);
}

void transpose(int mat_a[][MAXN], int mat_b[][MAXN], int n)
{
  char x,y;
  scanf("%c %c", &x, &y);

  if(x=='A' && y=='B') transposeUtil(mat_a,mat_b,n);
  else if(x=='A' && y=='A') transposeUtil(mat_a,mat_a,n);
  else if(x=='B' && y=='A') transposeUtil(mat_b,mat_a,n);
  else if(x=='B' && y=='B') transposeUtil(mat_b,mat_b,n);
}

void sumUtil(int x[][MAXN], int y[][MAXN], int z[][MAXN], int n)
{
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int soma = x[i][j]+y[i][j];
      if(soma!=0) z[i][j] = 1;
      else z[i][j] = 0;
    }
  }
  printMat(z,n);
}

void sum(int mat_a[][MAXN], int mat_b[][MAXN], int n)
{
  char x,y,z;
  scanf("%c %c %c", &x, &y, &z);
  if(x==y && x=='A') 
  {
    if(z=='a') sumUtil(mat_a,mat_a,mat_a,n); 
    else sumUtil(mat_a,mat_a,mat_b, n);
  }
  else if(x==y && x=='B') 
  {
    if(z=='a') sumUtil(mat_b,mat_b,mat_a,n); 
    else sumUtil(mat_b,mat_b,mat_b, n);
  }
  else if(z=='A') sumUtil(mat_a,mat_b,mat_a,n); 
  else if(z=='B') sumUtil(mat_a,mat_b,mat_b,n); 
}

void mulElementUtil(int x[][MAXN], int y[][MAXN], int z[][MAXN], int n)
{
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int mul = x[i][j]*y[i][j];
      if(mul != 0) z[i][j] = 1;
      else z[i][j] = 0;
    }
  }
  printMat(z,n);  
}

void mulElement(int mat_a[][MAXN], int mat_b[][MAXN], int n)
{
  char x,y,z;
  scanf("%c %c %c", &x, &y, &z);
  if(x==y && x=='A') 
  {
    if(z=='a') mulElementUtil(mat_a,mat_a,mat_a,n); 
    else mulElementUtil(mat_a,mat_a,mat_b, n);
  }
  else if(x==y && x=='B') 
  {
    if(z=='a') mulElementUtil(mat_b,mat_b,mat_a,n); 
    else mulElementUtil(mat_b,mat_b,mat_b, n);
  }
  else if(z=='A') mulElementUtil(mat_a,mat_b,mat_a,n); 
  else if(z=='B') mulElementUtil(mat_a,mat_b,mat_b,n); 
}

void mulMatUtil(int x[][MAXN], int y[][MAXN], int z[][MAXN], int n)
{
  int trans[MAXN][MAXN] = {0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int acculmulator = 0;
      for(int k=0;k<n;k++){
        acculmulator+= x[i][k]*y[k][j];  
      }
      if(acculmulator!=0) trans[i][j] = 1;
      else trans[i][j] = 0;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      z[i][j] = trans[i][j];
    }
  }
  printMat(z,n);
}

void mulMat(int mat_a[][MAXN], int mat_b[][MAXN], int n)
{
  char x,y,z;
  scanf("%c %c %c", &x, &y, &z);
  if(x==y && x=='A') 
  {
    if(z=='a') mulMatUtil(mat_a,mat_a,mat_a,n); 
    else mulMatUtil(mat_a,mat_a,mat_b, n);
  }
  else if(x==y && x=='B') 
  {
    if(z=='a') mulMatUtil(mat_b,mat_b,mat_a,n); 
    else mulMatUtil(mat_b,mat_b,mat_b, n);
  }
  else if(x=='A' && y=='B' && z=='A') mulMatUtil(mat_a,mat_b,mat_a,n); 
  else if(x=='A' && y=='B' && z=='B') mulMatUtil(mat_a,mat_b,mat_b,n); 
  else if(x=='B' && y=='A' && z=='A') mulMatUtil(mat_b,mat_a,mat_a,n); 
  else if(x=='B' && y=='A' && z=='B') mulMatUtil(mat_b,mat_a,mat_b,n); 
}


void bordasUtil(int x[][MAXN], int y[][MAXN], int n) 
{
  int transition[MAXN][MAXN] = {0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      transition[i][j] = y[i][j];
    }
  }
 for(int i=1;i<n-1;i++){
    for(int j=1;j<n-1;j++){
      if(x[i][j]==0) continue;

      if(x[i-1][j] == 1 && x[i+1][j]==1 && x[i][j+1]==1 && x[i][j-1]==1
      && x[i-1][j-1]==1 && x[i-1][j+1]==1
      && x[i+1][j-1]==1 && x[i+1][j+1]==1){
        transition[i][j] = 0;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      y[i][j] = transition[i][j];
    }
  }
  printMat(y,n);
}

void bordas(int mat_a[][MAXN], int mat_b[][MAXN], int n)
{
  char x,y;
  scanf("%c %c", &x, &y);
  
  if(x=='A' && y=='B') bordasUtil(mat_a,mat_b,n);
  else if(x=='A' && y=='A') bordasUtil(mat_a,mat_a,n);
  else if(x=='B' && y=='A') bordasUtil(mat_b,mat_a,n);
  else if(x=='B' && y=='B') bordasUtil(mat_b,mat_b,n);
}

int main()
{
  int mat_a[MAXN][MAXN] = {0};
  int mat_b[MAXN][MAXN] = {0};
  int n,o;
  scanf("%d", &n);
  scanf("%d", &o);

  setMat(mat_a,n);
  setMat(mat_b,n);

  while(o--){
    char op[11];
    scanf("%s ", op);
    if(!strcmp(op, "TRANSPOSTA")) transpose(mat_a,mat_b,n);
    else if(!strcmp(op, "SOMA")) sum(mat_a,mat_b,n);
    else if(!strcmp(op, "MULTI_ELEM")) mulElement(mat_a,mat_b,n);
    else if(!strcmp(op, "MULTI_MAT")) mulMat(mat_a,mat_b,n);
    else if(!strcmp(op, "BORDAS")) bordas(mat_a,mat_b,n);
  }
  return 0;
}
