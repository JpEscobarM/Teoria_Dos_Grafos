#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6
#define inf 99

int grafo[N][N] = {{inf,1,1,inf,1,1},
                       {1,inf,1,1,inf,1},
                       {1,1,inf,1,1,1},
                       {inf,1,1,inf,1,1},
                       {1,inf,1,1,inf,1},
                       {1,1,1,1,1,inf},  };

void bfs( int vi , int g[N][N], int nivel[N]){

    for ( int i = 0 ; i <N ; i++) nivel[i]= -1;

    nivel[vi] = 0;

    int NivelCorrente=0;

   while( 1 )
{
    int trocou=0;
        for(int i =0; i<N; i ++)
        if( nivel [i]== NivelCorrente )
            for( int j =0; j<N; j ++)
                if(g[i][j] ==1 && nivel[j] == -1)
                {
                nivel[j]= NivelCorrente +1;
                trocou=1;
                }
    if (trocou==0) break ;
    NivelCorrente++;
}

}



int main(){

    int nivel[N];
   bfs(0,grafo,nivel);

   for( int j =0; j<N; j ++)
   printf("%d", nivel[j]);

return 0;
}
