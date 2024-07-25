#include <stdio.h>
#include <stdlib.h>
#define n 10
   //          A B C D E F G H I J
int g[n][n]= {{0,1,0,0,0,0,0,0,0,0}, //A
              {1,0,0,0,0,0,0,0,0,0},//B
              {0,0,0,1,0,0,0,0,0,0},//C
              {0,0,1,0,0,0,0,0,0,0},//D
              {0,0,0,0,0,1,0,0,0,0},//E
              {0,0,0,0,1,0,0,0,0,0},//F
              {0,0,0,0,0,0,0,1,0,0},//G
              {0,0,0,0,0,0,1,0,0,0},//H
              {0,0,0,0,0,0,0,0,0,1},//I
              {0,0,0,0,0,0,0,0,1,0},//J
};//11

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



int main(){


    associacaoPerfeita(g);

return 0;
}
