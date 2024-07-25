#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 6

int G[6][6]={{0,1,0,0,1,0},
             {1,0,1,0,1,0},
             {0,1,0,1,0,0},
             {0,0,1,0,1,0},
             {1,1,0,1,0,1},
             {1,0,0,0,0,0}};
int vnivel[6]={-1,-1,-1,-1,-1,-1};
int low[n] = {-1,-1,-1,-1,-1,-1};

void dfs(int v, int nivel)
{
vnivel[v]=nivel;
int i;
for (i=0;i<6;i++)
   {
   if (G[v][i]==1 && vnivel[i]==-1)
      {
      G[v][i]=2;
      G[i][v]=0;
      dfs(i,nivel+1);
      }
   }
}


int lowpt(int v){

        if( low[v]!= -1){return low[v]; };


        low[v] = v;

        int i;

        for( i  = 0 ; i < n ; i ++){

            if( G[v][i] == 2 && vnivel[low[i]]< vnivel[low[v]]){
                low[v] = low[i] ;
            }
            else{

                if( G[v][i] ==1 && vnivel[i] < vnivel[low[v]]){
                    low[v] = i;

                }

            }

        }
        return low[v];
}


int main() {
  dfs(0,0);
  int i,j;
  for (i=0;i<6;i++)
     for (j=0;j<6;j++)
if (G[i][j]==1 && vnivel[i]<vnivel[j])
           G[i][j]=0;


lowpt(0);


 for (i=0;i<6;i++){
     for (j=0;j<6;j++)
    printf("%d", G[i][j]);
 printf("%\n");
}
  return 0;
}
