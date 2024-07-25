#include <stdio.h>
#include <stdlib.h>
#define n 10
int g[n][n] ={  {0,1,0,0,0,0,0,0,0,0,0},
                {1,0,1,0,0,0,0,0,0,0,0},
                {0,1,0,1,0,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0},};


int associacaoPerfeita(int grafo[n][n]){

    int i;
    int grau[n] ={0};
    for( i = 0 ; i< n ; i ++){
        for( int j = i + 1 ; j< n ; j ++ ){
            if(grafo[i][j] == 1){
                grau[i]++;
                grau[j]++;

            }
        }


    }
    for( i = 0 ; i < n ; i ++){
            if(grau[i] != 1){
                return 0;
            }

    }

/*
int associacaoPerfeita(int grafo[10][10]){

    int i,j;
    int grau[n] = {0};
    for( i = 0 ; i < n ;i ++){
        for( j = 0 ; j  < n ; j ++){

            if(grafo[i][j] == 1)
            grau[i]++;
        }
    }
        for(i=0;i<n;i++){
           if( grau[i] != 1){
            return 0;
           }
        }
        return 1;
}


*/
return 1;
}


int main(){
return 0;
}
