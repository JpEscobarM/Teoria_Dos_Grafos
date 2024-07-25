#include <stdio.h>
#include <stdlib.h>
#define n 10
int vnivel[n] = {-1};
int low[n] = {-1};
int g[n][n] = {  {0,0,0,1,1,0,1,0,0,0},
                 {0,0,0,0,0,1,1,0,0,0},
                 {0,0,0,0,1,0,1,1,0,1},
                 {0,1,0,1,0,0,0,0,0,0},
                 {0,0,0,1,0,0,0,0,0,0},
                 {0,0,0,1,0,1,0,1,1,0},
                 {0,0,0,0,0,0,0,0,0,0},
                 {0,0,1,0,1,0,0,1,0,0},
                 {0,0,0,0,0,0,0,1,1,0},
                 {1,0,0,0,0,0,0,0,1,0},};

void dfs(int v, int nivel){

    vnivel[v] = nivel;

    int i;
    for ( i = 0 ; i < n ; i ++){

        if( g[v][i] == 1 && vnivel[i] == -1){

            g[v][i] = 2;
            g[i][v] = 0 ;
            dfs(v,nivel+1);
        }
    }


}

int lowpt(int v){

        if( low[v]!= -1){return low[v]; };


        low[v] = v;

        int i;

        for( i  = 0 ; i < n ; i ++){

            if( g[v][i] == 2 && vnivel[low[i]]< vnivel[low[v]]){
                low[v] = low[i] ;
            }
            else{

                if( g[v][i] ==1 && vnivel[i] < vnivel[low[v]]){
                    low[v] = i;

                }

            }

        }
        return low[v];
}




int main(){

    dfs(0,0);

    int i,j ;

    for ( i = 0 ; i  < n ; i ++ ){

        for( j = 0 ; j < n ; j ++){

            if (g[i][j] == 1 && vnivel[i] < vnivel[j]){

                g[i][j] = 0;

            }

        }
    }

    lowpt(0);


    for ( i = 0 ; i  < n ; i ++ ){

        for( j = 0 ; j < n ; j ++){

           printf("%d", g[i][j]);
            }
         printf("\n");
        }
        printf("\n");


return 0;
}
